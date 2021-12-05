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
#define WORD "(?i)[a-z0-9A-Z_]+(?-i)([-']?(?i)[a-z0-9A-Z_]+)+"

int main(int argc, char **argv) {
    uint32_t htsize = 2 << 16;
    uint32_t bfsize = 2 << 20;
    int opt = 0;
    bool stats = false;
    bool rightspeak = false;
    bool thoughtcrime = false;
    FILE *bad;
    FILE *new;
    char badspeak[1024];
    char oldspeak[1024];
    char newspeak[1024];

    while ((opt = getopt(argc, argv, "t:f:sh")) != -1) { //commands for encryption
        switch (opt) {
        case 't': htsize = atoi(optarg); break; //opens specified infile for reading
        case 'f': bfsize = atoi(optarg); break;
        case 's': stats = true; break; //sets name of pubfile
        case 'h': return 0;
        }
    }
    BloomFilter *bf = bf_create(bfsize);
    HashTable *ht = ht_create(htsize);
    bad = fopen("badspeak.txt", "r");
    new = fopen("newspeak.txt", "r");
    while (1) {
        fscanf(bad, "%s\n", badspeak);

        bf_insert(bf, badspeak);
        ht_insert(ht, badspeak, NULL);

        if (feof(bad)) {
            break;
        }
    }
    while (1) {
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
    if (regcomp(&re, WORD, REG_EXTENDED)) {
        fprintf(stderr, "Failed to compile regex .\n");
        return 1;
    }

    char *word = NULL;
    while ((word = next_word(stdin, &re)) != NULL) {
        if (bf_probe(bf, word) && ht_lookup(ht, word)->oldspeak) {
            if (ht_lookup(ht, word)->newspeak) {
                if (!new_message) {
                    new_message
                        = node_create(ht_lookup(ht, word)->oldspeak, ht_lookup(ht, word)->newspeak);
                } else {
                    bst_insert(
                        new_message, ht_lookup(ht, word)->oldspeak, ht_lookup(ht, word)->newspeak);
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
    if (rightspeak && thoughtcrime) {
        printf("%s", mixspeak_message);
        bst_print(bad_message);
        bst_print(new_message);
    } else if (thoughtcrime && !rightspeak) {
        printf("%s", badspeak_message);
        bst_print(bad_message);
    }

    else if (!thoughtcrime && rightspeak) {
        printf("%s", goodspeak_message);
        bst_print(new_message);
    }

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
