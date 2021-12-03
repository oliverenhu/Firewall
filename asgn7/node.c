#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Node *node_create(char *oldspeak, char *newspeak){
	Node *n= (Node *) malloc(sizeof(Node));
	if(n){
		n->oldspeak=(char *)malloc(sizeof(char));
		if(!oldspeak){
		n->oldspeak=strdup(oldspeak);
		}
		n->newspeak=(char *)malloc(sizeof(char));
		if(!newspeak){
		n->newspeak=strdup(newspeak);
		}
	}
	return n;	
}
void node_delete(Node **n){
	free((*n)->oldspeak);
	free((*n)->newspeak);
	free(*n);
}
void node_print(Node *n){
	if(n->newspeak==NULL){
		printf("%s\n", n->oldspeak);
		return;
	}
	if(n->newspeak && n->oldspeak){
		printf("%s -> %s\n", n->oldspeak , n->newspeak );	
	}
}
