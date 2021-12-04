#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Node *node_create(char *oldspeak, char *newspeak){
	Node *n= (Node *)malloc(sizeof(Node));
	if(n){
		
		if(oldspeak){
		n->oldspeak=strdup(oldspeak);
		}
		
		if(newspeak){
		n->newspeak=strdup(newspeak);
		}
		
		
	}
	return n;	
}
void node_delete(Node **n){
	if(*n){
		free((*n)->oldspeak);
		free((*n)->newspeak);
		free(*n);

		*n=NULL;
	}
	return;
}
void node_print(Node *n){
	if(n->newspeak==NULL && n->oldspeak){
		printf("%s\n", n->oldspeak);
		
	}
	else if(n->newspeak && n->oldspeak){
		printf("%s -> %s\n", n->oldspeak , n->newspeak );	
	}
}
