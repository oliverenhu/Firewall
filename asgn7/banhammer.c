# include "parser.h"
# include <regex.h>
# include <stdio.h>
# include "node.h"
# include "bst.h"
# include "bf.h"
# include "bv.h"
# define WORD "[a-zA-Z]+"

int main ( void ) {
	/*
	regex_t re;
	if ( regcomp(&re , WORD , REG_EXTENDED ) ) {
	fprintf(stderr , "Failed to compile regex .\n") ;
	return 1;
}

	char *word = NULL ;
	while (( word = next_word(stdin,&re))!= NULL ) {
	printf (" Word : %s\n", word );
	}*/
	Node *y=_create("fd","dsf");
	
		
//	bst_insert(y,"ewwwe","rer");

	node_print(y);
	node_delete(&y);
//	clear_words();
//	regfree(&re);
	return 0;
}
