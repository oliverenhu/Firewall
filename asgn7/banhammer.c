#include "parser.h"
#include <regex.h>
#include <stdio.h>
#include "node.h"
#include "bst.h"
#include "bf.h"
#include "bv.h"
#include "salts.h"
#include <stdint.h>
#include "speck.h"
#include "ht.h"
#include <stdbool.h>
#include "messages.h"
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define WORD "([a-z0-9A-Z_]+([-']?[a-z0-9A-Z_]+)*)"

int main(int argc, char **argv) {
    uint32_t htsize = 65536;
    uint32_t bfsize = 1048576;
    int opt = 0;
    bool stats = false;
    bool rightspeak = false;
    bool thoughtcrime = false;
    FILE *bad;
    FILE *new;
    char badspeak[1024];
    char oldspeak[1024];
    char newspeak[1024];

    while ((opt = getopt(argc, argv, "t:f:sh")) != -1) { //commands for firewall
        switch (opt) {
        case 't': htsize = (uint32_t) atoi(optarg); break;
        case 'f': bfsize = (uint32_t) atoi(optarg); break;
        case 's': stats = true; break; //sets print stats to true
        case 'h':
            printf("SYNOPSIS\n  A word filtering program for the GPRSC.\n  Filters out and reports "
                   "bad words parsed from stdin.\n\nUSAGE\n  ./banhammer [-hs] [-t size] [-f "
                   "size]\n\nOPTIONS\n  -h           Program usage and help.\n  -s           Print "
                   "program statistics.\n  -t size      Specify hash table size (default: 2^16).\n "
                   " -f size      Specify Bloom filter size (default: 2^20).\n");
            //pritns helful message
            return 0;
        }
    }
    BloomFilter *bf = bf_create(bfsize); //initializes BloomFilter
    HashTable *ht = ht_create(htsize); //initializes HashTable
    bad = fopen("badspeak.txt", "r"); //opens badspeak and newspeak.txt
    new = fopen("newspeak.txt", "r");
    while (1) { //scans in all the badspeak into the bf and ht
        fscanf(bad, "%s\n", badspeak);

        bf_insert(bf, badspeak);
        ht_insert(ht, badspeak, NULL);

        if (feof(bad)) {
            break;
        }
    }
    while (1) { //scans in all the newspeak into the bf and ht
        fscanf(new, "%s %s\n", oldspeak, newspeak);
        bf_insert(bf, oldspeak);
        ht_insert(ht, oldspeak, newspeak);

        if (feof(new)) {
            break;
        }
    }

    Node *new_message = bst_create();
    Node *bad_message = bst_create();

    regex_t re;
    if (regcomp(&re, WORD, REG_EXTENDED)) { //determines if regex is valid
        fprintf(stderr, "Failed to compile regex .\n");
        return 1;
    }

    char *word = NULL;
    while (
        (word = next_word(stdin, &re))
        != NULL) { //parses through stdin and cheacks if the word is part of badspeak and newspeak and prints them out accordingly
        for (int i = 0; i < strlen(word); i += 1) {
            word[i] = tolower(word[i]);
        }
        if (bf_probe(bf, word)) {

            if (ht_lookup(ht, word)) {

                if (ht_lookup(ht, word)->newspeak) {
                    if (!new_message) {
                        new_message = node_create(
                            ht_lookup(ht, word)->oldspeak, ht_lookup(ht, word)->newspeak);
                    } else {
                        bst_insert(new_message, ht_lookup(ht, word)->oldspeak,
                            ht_lookup(ht, word)->newspeak);
                    }
                    rightspeak = true;
                }

                else {
                    if (!bad_message) {
                        bad_message = node_create(ht_lookup(ht, word)->oldspeak, NULL);
                    } else {
                        bst_insert(bad_message, ht_lookup(ht, word)->oldspeak, NULL);
                    }

                    thoughtcrime = true;
                }
            }
        }
    }

    if (stats) { //prints out stats
        printf("Average BST size: %0.6f\nAverage BST height: %0.6f\nAverage branches traversed: "
               "%0.6f\nHash table load: %0.6f%%\nBloom filter load: %0.6f%%\n",
            ht_avg_bst_size(ht), ht_avg_bst_height(ht), (double) branches / lookups,
            ((double) 100 * ht_count(ht) / ht_size(ht)),
            (((double) 100 * bf_count(bf)) / bf_size(bf)));
    }
    //prints out message
    if (rightspeak && thoughtcrime && !stats) {
        printf("%s", mixspeak_message);
        bst_print(bad_message);
        bst_print(new_message);
    } else if (thoughtcrime && !rightspeak && !stats) {
        printf("%s", badspeak_message);
        bst_print(bad_message);
    }

    else if (!thoughtcrime && rightspeak && !stats) {
        printf("%s", goodspeak_message);
        bst_print(new_message);
    }
    //frees and closes
    bst_delete(&bad_message);
    bst_delete(&new_message);
    fclose(bad);
    fclose(new);
    bf_delete(&bf);
    ht_delete(&ht);
    clear_words();
    regfree(&re);
    return 0;
}
