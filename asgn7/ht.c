#include "ht.h"
#include "salts.h"
#include "speck.h"
#include <stdlib.h>
uint64_t lookups;

struct HashTable {
	uint64_t salt[2];
	uint32_t size;
	Node **trees;
};


HashTable *ht_create(uint32_t size){
	HashTable *ht=(HashTable *) malloc(sizeof(HashTable));
	if(ht){
		ht->size=size;
		ht->salt[0]=SALT_HASHTABLE_LO;
		ht->salt[1]=SALT_HASHTABLE_HI;
		ht->trees=(Node **) calloc(size,sizeof(Node));
	}
	return ht;
	
}
void ht_delete(HashTable **ht){
	if(*ht&&(*ht)->trees){
		
		free((*ht)->trees);
		free(*ht);
		
		*ht=NULL;
	}
	return;	
}
uint32_t ht_size(HashTable *ht){
	return ht->size;
}
Node *ht_lookup(HashTable *ht, char *oldspeak){
	lookup+=1;
	bst_find(ht->trees[hash(ht->salt,oldspeak)],oldspeak);
}
void ht_insert(HashTable *ht, char *oldspeak, char *newspeak){
	bst_insert(ht->trees[(hash(ht->salt,oldspeak))],oldspeak,newspeak);
}
uint32_t ht_count(HashTable *ht){
	uint32_t count;
	for( int i=0;i<ht_size(ht);i+=1){
		if(ht->trees[i]){
			count+=1;			
		}
	}
	return count;
}
double ht_avg_bst_size(HashTable *ht){
	uint32_t avg_size;
	for( int i=0;i<ht_size(ht);i+=1){
                if(ht->trees[i]){
                        avg_size+=bst_size(ht->trees[i]);
                }
        }
	avg_size/=ht_count(ht);
	return avg_size;
}	

double ht_avg_bst_height(HashTable *ht){
	uint32_t avg_height;
        for( int i=0;i<ht_size(ht);i+=1){
                if(ht->trees[i]){
                        avg_height+=bst_height(ht->trees[i]);
                }
        }
        avg_height/=ht_count(ht);
        return avg_height;
}


void ht_print(HashTable *ht){
	for (int i=0;i<ht_size(ht);i+=1){
		if(ht->trees[i]){
			bst_print(ht->trees[i]);
		}
}
