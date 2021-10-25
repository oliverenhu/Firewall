# Assignment 4 -The Perambulations of Denver Long

DESCRIPTION
This program calculates the quickest path passing through a 2d array of interconnected vertices and visits each vertice only one time while ending back at the original vertice. A graph function is used to store a matrix of values that denote the weight associated with each path connecting vertice to vertice. This program will attempt to utilize a recursive pathing method to find the quickest path with a given file input of number of vertices, name of vertices and a matrix of vertice and weight values.
## Building

Files

README.md: A file meant to show how to build and run the program and how the program handles bugs.

Makefile : A file that builds the tsp.c program and linked all the graph stack and path sources file to main

DESIGN.pdf: Describes the entire assignment along with all information regarding the program

graph.h specifies the interface to the graph ADT.

graph.c implements the graph ADT.

path.h specifies the interface to the path ADT.

path.c implements the path ADT.

stack.h specifies the interface to the stack ADT.

stack.c implements the stack ADT.

tsp.c contains main() and may contain any other functions necessary.
-h : Prints out a help message describing the purpose of the graph and the command-line options
it accepts, exiting the program afterwards. Refer to the reference program in the resources repo for
an idea of what to print.

-v : Enables verbose printing. If enabled, the program prints out all Hamiltonian paths found as
well as the total number of recursive calls to dfs().

-u : Specifies the graph to be undirected.

-i infile : Specify the input file path containing the cities and edges of a graph. If not specified,
the default input should be set as stdin.

-o outfile : Specify the output file path to print to. If not specified, the default output should be
set as stdout.

vertices.h defines macros regarding vertices.


##RUNNING

INSTRUCTIONS

This program is intended to be run in the Ubuntu Virtual Box with PuTTY and in order to run program you will be given a list of commands when running the program using '-h'. It will provide you will many commands linked to each mathmatical method with statistics and differences provided.


