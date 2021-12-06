#include "ht.h"
#include "salts.h"
#include "speck.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
uint64_t lookups;

struct HashTable {
    uint64_t salt[2];
    uint32_t size;
    Node **trees;
};

HashTable *ht_create(uint32_t
        size) { //creates the salt for hash and dynamically allocates an array of bst and stores size
    HashTable *ht = (HashTable *) malloc(sizeof(HashTable));
    if (ht) {
        ht->size = size;
        ht->salt[0] = SALT_HASHTABLE_LO;
        ht->salt[1] = SALT_HASHTABLE_HI;
        ht->trees = (Node **) calloc(size, sizeof(Node));
    }
    return ht;
}
void ht_delete(HashTable **ht) { //deletes bst trees and frees ht
    if (*ht && (*ht)->trees) {

        for (int i = 0; i < ht_size(*ht); i += 1) {
            if ((*ht)->trees[i]) {
                bst_delete(&((*ht)->trees[i]));
            }
        }
        free((*ht)->trees);
        free(*ht);

        *ht = NULL;
    }
    return;
}
uint32_t ht_size(HashTable *ht) { //returns size
    return ht->size;
}
Node *ht_lookup(HashTable *ht, char *oldspeak) { //uses bst_find to determine if oldspeak is in ht
    lookups += 1;
    uint32_t index = (hash(ht->salt, oldspeak)) % ht_size(ht);
    return bst_find(ht->trees[index], oldspeak);
}
void ht_insert(HashTable *ht, char *oldspeak,
    char *
        newspeak) { //inserts a new node based off oldspeak and newspeak using hashing to find the index

    lookups += 1;
    uint32_t index = (hash(ht->salt, oldspeak)) % ht_size(ht);
    if (!ht->trees[index]) {
        ht->trees[index] = node_create(oldspeak, newspeak);
    } else {
        bst_insert(ht->trees[index], oldspeak, newspeak);
    }
}
uint32_t ht_count(HashTable *ht) { //counts the number of non-Null bsts
    uint32_t count = 0;
    for (int i = 0; i < ht_size(ht); i += 1) {
        if (ht->trees[i]) {
            count += 1;
        }
    }
    return count;
}
double ht_avg_bst_size(HashTable *ht) { //returns the average bst size
    double avg_size = 0;
    for (int i = 0; i < ht_size(ht); i += 1) {
        if (ht->trees[i]) {
            avg_size += bst_size(ht->trees[i]);
        }
    }
    avg_size /= (double) ht_count(ht);
    return avg_size;
}

double ht_avg_bst_height(HashTable *ht) { //returns the average bst height
    double avg_height = 0;
    for (int i = 0; i < ht_size(ht); i += 1) {
        if (ht->trees[i]) {
            avg_height += bst_height(ht->trees[i]);
        }
    }
    avg_height /= (double) ht_count(ht);
    return avg_height;
}

void ht_print(HashTable *ht) {
    for (int i = 0; i < ht_size(ht); i += 1) {
        if (ht->trees[i]) {
            bst_print(ht->trees[i]);
        }
    }
}
