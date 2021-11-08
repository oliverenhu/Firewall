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
    uint8_t buf[BLOCK];
    uint64_t histogram[ALPHABET]={0};
    int bytes = (read_bytes(infile, buf, BLOCK));
    Code table[ALPHABET]={0};

    for (int i = 0; i < bytes; i += 1) {
        
            histogram[buf[i]] += 1;
            printf("symbol:%c,frequency:%lu\n",buf[i],histogram[buf[i]]);
        
    }
    int leaves=0;
    for(int i =0;i<ALPHABET;i+=1){
    	if(histogram[buf[i]]>0){
		leaves+=1;
		}

    }
    histogram[0] += 1;
    histogram[255] += 1;
    	
    
    Node *root=build_tree(histogram);
    node_print(root);
    

    build_codes(root,table);

    Header head;
    head.magic=MAGIC;
    struct stat permissions;
  
    fstat(infile,&permissions);
    head.permissions=permissions.st_mode;
    fchmod(outfile,head.permissions);
    head.tree_size=permissions.st_size;
    head.file_size=bytes;	    
    write(outfile,&head.magic,4);
    write(outfile,&head.tree_size,1);
    write(outfile,&head.file_size,1);
for(int i = 0; i < bytes; i += 1) {
	code_print(&table[buf[i]]);
	printf("\n");
}
    return 0;
}
