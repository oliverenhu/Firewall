# include "parser.h"
# include <regex.h>
# include <stdio.h>
# include "node.h"
# include "bst.h"
# include "bf.h"
# include "bv.h"
# include "salts.h"
#include <stdint.h>
#include "speck.h"
# define WORD "[a-zA-Z]+"

int main (void){
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

	
		



	uint32_t d=3011890399;	
	BloomFilter* b=bf_create(d);
	bf_insert(b,"apple");
	
	printf("%d",bf_probe(b,"apple"));	
//	bf_print(b);	
	bf_delete(&b);
//	clear_words();
//	regfree(&re);
	return 0;
}
