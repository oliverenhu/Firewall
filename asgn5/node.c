#include "node.h"


Node *node_create(uint8_t symbol, uint64_t frequencyi){
	Node *n= (Node *) malloc(sizeof(Node));
	if(n){
	n->symbol=symbol;
	n->frequency=frequency;

	{
	return n;
}


void node_delete(Node **n){
	if(*n&&(*n)->left&&(*n)->right){
	free((*n)->left);
	free((*n)->right)
	free(*n);
	*n =NULL
	}
	return;
}
Node *node_join(Node *left, Node *right){

}

void node_print(Node *n);

