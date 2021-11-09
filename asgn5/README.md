# Assignment 3 -Sorting: Putting your affairs in order
Description:

This program will encode a script given to it using the Huffman code. It will utilize stacks to build the Huffman code while parsing through the binary tree. It will shrink the size of bytes required to transport the file and inorder to read the file once more you will be required to use the Huffman code to remake the tree as print out the script by decoding it. We are able to take the file as an input and output it to a current file or create a new file.

## Building

Files

README.md: A file meant to show how to build and run the program and how the program handles bugs. 
encode.c: This file will contain your implementation of the Huffman encoder. 

decode.c: This file will contain your implementation of the Huffman decoder. 

defines.h: This file will contain the macro definitions used throughout the assignment.  

header.h: This will contain the struct definition for a file header.  

node.h: This file will contain the node ADT interface.   

node.c: This file will contain your implementation of the node ADT. 

pq.h: This file will contain the priority queue ADT interface.   

pq.c: This file will contain your implementation of the priority queue ADT. You must define your priority queue struct in this file. 

code.h: This file will contain the code ADT interface.   

code.c: This file will contain your implementation of the code ADT. 

io.h: This file will contain the I/O module interface.   

io.c: This file will contain your implementation of the I/O module. 

stack.h: This file will contain the stack ADT interface.   

stack.c: This file will contain your implementation of the stack ADT. You must define your stack struct in this file. 

huffman.h: This file will contain the Huffman coding module interface.   

huffman.c: This file will contain your implementation of the Huffman coding module interface. 
Makefile: This is a file that will allow the grader to type make to compile your programs. • CC = clang must be specified. 
• CFLAGS = -Wall -Wextra -Werror -Wpedantic must be included. 
• make should build the encoder and the decoder, as should make all. 
• make encode should build just the encoder.
• make decode should build just the decoder. 
• make clean must remove all files that are compiler generated. 
• make format should format all your source code, including the header files. 

DESIGN.pdf: Describes the entire assignment along with all information regarding the program

##RUNNING

INSTRUCTIONS

This program is intended to be run in the Ubuntu Virtual Box with PuTTY and in order to run program you will be given a list of commands when running the program using '-h'.You will provide the program with a file and it will encode the file into the output file specified.


