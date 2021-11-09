#include "header.h"
#include "node.h"
#include "pq.h"
#include "code.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "io.h"
#include <fcntl.h>
#include "huffman.h"
#include <inttypes.h>
#include <sys/stat.h>
int main(int argc, char **argv) {
    int infile;
  
    int outfile;
    bool stats = false;
    int opt = 0;
    while ((opt = getopt(argc, argv, "i:o:vh")) != -1) {
        switch (opt) {
        case 'i': infile = open(optarg, O_RDWR); break;
        case 'o': outfile = open(optarg, O_RDWR|O_CREAT); break;
        case 'v': stats = true; break;
        case 'h':
            printf("SYNOPSIS\n  Traveling Salesman Problem using DFS.\n\nUSAGE\n  ./tsp [-u] [-v] "
                   "[-h] [-i infile] [-o outfile]\n\nOPTIONS\n  -u             Use undirected "
                   "graph.\n  -v             Enable verbose printing.\n  -h             Program "
                   "usage and help.\n  -i infile      Input containing graph (default: stdin)\n  "
                   "-o outfile     Output of computed path (default: stdout)\n");
            return 0;
        }
    }
    uint64_t histogram[ALPHABET]={0};
    Code table[ALPHABET]={0};
    uint8_t buf[BLOCK];
    int bytes=0;
    do{
    int bytes = (read_bytes(infile, buf, BLOCK));
    for (int i = 0; i < bytes; i += 1) {
            histogram[buf[i]] += 1;
    }
    }while(bytes>0);


    
    int leaves=2;
    for(int i =0;i<ALPHABET;i+=1){
    	if(histogram[i]>0){
//		printf("symbol:%c,frequency:%lu\n",i,histogram[i]);
		leaves+=1;
		}

    }
    histogram[0] += 1;
    histogram[255] += 1;
    
    Node *root=build_tree(histogram);
     //returns the root of the build_tree()
    

    build_codes(root,table);           //builds the code

    Header head;
    head.magic=MAGIC;
    struct stat permissions;
     
    fstat(infile,&permissions);
    head.permissions=permissions.st_mode;
    fchmod(outfile,head.permissions);
    head.file_size=permissions.st_size;
    head.tree_size=leaves*3-1;	    
    write(outfile,&head.magic,4);
    write(outfile,&head.permissions,2);
    write(outfile,&head.tree_size,2);
    write(outfile,&head.file_size,8);
    
/*  
for(int i = 0; i < ALPHABET; i += 1) {
	if(histogram[i]>0){
	printf("%c:",i);
	code_print(&table[i]);
	printf("\n");
}

}*/
    dump_tree(outfile,root);	
    lseek(infile,0,SEEK_SET);
    bytes_read=0;
    do{
    int bytes = (read_bytes(infile, buf, BLOCK));
    for (int i = 0; i < bytes; i += 1) {

           write_code(outfile,&table[buf[i]]); 
    }
    }while(bytes>0);

    flush_codes(outfile);	

    return 0;
}
