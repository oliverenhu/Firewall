#include "node.h"
#include <stdlib.h>
#include <stdio.h>
Node *node_create(uint8_t symbol, uint64_t frequency){
	Node *n= (Node *) malloc(sizeof(Node));
	if(n){
	n->symbol=symbol;
	n->frequency=frequency;

	}
	return n;
}


void node_delete(Node **n){
	if(*n){
	free((*n)->left);
	free((*n)->right);
	free(*n);
	*n =NULL;
	}
	return;
}
Node *node_join(Node *left, Node *right){
	Node *parent=node_create('$',left->frequency + right->frequency);
	parent->left=left;
	parent->right=right;
	return parent;
}

void node_print(Node *n){
	printf("%hhu,%lu\n",n->symbol,n->frequency);
//	node_print(n->left);
//	node_print(n->right);
	return;
}
	
