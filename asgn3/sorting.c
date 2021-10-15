#include <stdio.h>
#include "stats.h"
#include "heap.h"
#include "insert.h"
#include "set.h"
#include "quick.h"
#include "shell.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#define OPTIONS "aeisqrnph:"

int main(int argc, char **argv){
	int opt = 0;
	char *seed;
	int size,elements;
	
	while((opt =getopt(argc, argv , OPTIONS))!=-1){
		switch(opt){
			case 'a':
		        break;
			
			case 'e':
                        break;
			
			case 'i':
                        break;
 			
			case 's':
                        break;
 			
			case 'q':
                        break;
 			
			case 'r':
			seed=argv[optind];
			
			
			
			printf("%s",seed);
			
                        break;
 			
			case 'n':
			size=optopt;
                        break;
 			
			case 'p':
			elements=optopt;	
                        break;
 			
			case 'h':
                        break;
		}}

	return 0;

//uint64_t mask = 0x3FFFFFFF;






}

