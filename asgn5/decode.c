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
        case 'o': outfile = open(optarg, O_RDWR | O_CREAT); break;
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
    uint8_t headbuf[16];
    uint32_t magic;
    uint16_t tree_size;
    uint8_t file_size;
    read_bytes(infile,headbuf,16);
    magic= (headbuf[3]<<24)|(headbuf[2]<<16)|(headbuf[1]<<8)|(headbuf[0]);
    if(magic!=MAGIC){
    printf("MAGIC NUMBER DOES NOT MATCH\n");
	    return 0;
    }	    
    Header head;
    
    head.permissions=(headbuf[5]<<8)|headbuf[4];
    fchmod(outfile,head.permissions);
    tree_size=(headbuf[7]<<8)|headbuf[6];
    file_size=(headbuf[9]<<8)|headbuf[8]; 
    uint8_t tree[tree_size];
    
    read_bytes(infile,tree,tree_size);
    
    Node *root=rebuild_tree(tree_size,tree);
    return 0;
    Code table[ALPHABET] = { 0 };
    build_codes(root, table);
    uint8_t out[file_size];
    
    
    uint64_t outindex=0;
   
    bool read=true;    
    static Code c;
    while(read){
        for(int i=0;i<ALPHABET;i+=1){
		if(c.bits==table[i].bits){
		out[outindex]=i;
		outindex+=1;

		}	
	}
	uint8_t bit;	
        read=read_bit(infile,&bit);
	code_push_bit(&c,bit);
		
	
    }
    write_bytes(outfile,out,file_size);
	return 0;
    
}
