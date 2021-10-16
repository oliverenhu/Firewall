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
#define OPTIONS "aeisqr:n:p:h:"
typedef enum { HEAP , SHELL , INSERTION , QUICK } Sorts;
const char *names[] = {"Heap Sort","Shell Sort","Insertion Sort","Quick Sort"};

int main(int argc, char **argv){
	int opt = 0;
	uint64_t seed =  13371453;
        uint32_t size = 100;
	int elements = 100 ;
	uint64_t mask = 0x3FFFFFFF;
	Set command = empty_set();
	while((opt =getopt(argc, argv , OPTIONS))!=-1){
		switch(opt){
			case 'a':
		        command = insert_set(HEAP, command);
			command = insert_set(INSERTION, command);
			command = insert_set(SHELL,command);
			command = insert_set(QUICK, command);
			break;
			
			case 'e':
                        command = insert_set(HEAP, command);
			break;
			
			case 'i':
			command = insert_set(INSERTION, command);
                        break;
 			
			case 's':
			command = insert_set(SHELL,command);
                        break;
 			
			case 'q':
			command = insert_set(QUICK, command);
                        break;
 			
			case 'r':
			seed=mask && atoi(optarg);
			
                        break;
 			
			case 'n':
			size=atoi(optarg);
                        break;
 			
			case 'p':
			elements=atoi(optarg);	
                        break;
 			
			case 'h':
                        break;
		}
	}
	srandom(seed);
	
	return 0;








}

