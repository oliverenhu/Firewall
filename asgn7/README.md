# Assignment 7 - The Great Firewall of Santa Cruz

Description: This program will utlize two text files to create a filter for a stdin input. The first filter will take words from "badspeak.txt" and store them into a BloomFilter inorder to filter out those specific words from the input and return those words as unacceptatble to the user. A secocnd text file "newspeak.txt" will provided translations for certain words provided and will reeducate the user in giving them the newspeak translation of their words. The banhammer program will also allow the user to see statistics invloving the innerworkings of the FireWall.

## Building 

banhammer.c: This contains main() and may contain the other functions necessary to complete the assignment. 

messages.h: Defines the mixspeak, badspeak, and goodspeak messages that are used in banhammer.c. 

salts.h: Defines the primary, secondary, and tertiary salts to be used in your Bloom filter implementation. Also defines the salt used by the hash table in your hash table implementation.

speck.h: Defines the interface for the hash function using the SPECK cipher. 

speck.c: Contains the implementation of the hash function using the SPECK cipher. 

ht.h: Defines the interface for the hash table. 

ht.c: Contains the implementation of the hash table. 

bst.h: Defines the interface for the binary search tree. 
bst.c: Contains the implementation of the binary search tree.

node.h: Defines the interface for the node. 

node.c: Contains the implementation of the node.

bf.h: Defines the interface for the Bloom filter. 

bf.c: Contains the implementation of the Bloom filter. 

bv.h: Defines the interface for the bit vector.  

bv.c: Contains the implementation of the bit vector. 

parser.h: Defines the interface for the regex parsing module.  

parser.c: Contains the implementation of the regex parsing module. 

Makefile: This is a file that will allow the grader to type make to compile your program. 

• CC = clang must be specified.
• CFLAGS = -Wall -Wextra -Werror -Wpedantic must be included. 
• make should build the banhammer executable, as should make all and make banhammer. 
• make clean must remove all files that are compiler generated.
• make format should format all your source code, including the header files.

README.md: This must be in Markdown. This must describe how to use your program and Makefile. This includes listing and explaining the command-line options that your program accepts. 

DESIGN.pdf: This must be a PDF. The design document should describe your design for your program with enough detail that a sufficiently knowledgeable programmer would be able to replicate your implementation. 

WRITEUP.pdf: This document must be a PDF. The writeup must include at least the following: 
• Graphs comparing the total number of lookups and average binary search tree branches traversed as you vary the hash table and Bloom filter size. 
• Analysis of the graphs you produce
## Instruction
This program is intended to be run in the Ubuntu Virtual Box with PuTTY and in order to run program you will be given a list of commands when running the program using '-h'. Then input anything into the stdin such as a textfile or sentence and press ENTER and the CTRL+D.
