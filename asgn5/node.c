#include "node.h"
#include <stdlib.h>

Node *node_create(uint8_t symbol, uint64_t frequency){
	Node *n= (Node *) malloc(sizeof(Node));
	if(n){
	n->symbol=symbol;
	n->frequency=frequency;

	}
	return n;
}


void node_delete(Node **n){
	if(*n&&(*n)->left&&(*n)->right){
	free((*n)->left);
	free((*n)->right);
	free(*n);
	*n =NULL;
	}
	return;
}
Node *node_join(Node *left, Node *right){
	Node *parent=node_create('$',left->frequency + right->frequency);
	return parent;
}

void node_print(Node *n);

