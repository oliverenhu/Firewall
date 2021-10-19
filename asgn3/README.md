# Assignment 3 -Sorting: Putting your affairs in order

DESCRIPTION
This program is a compilation of 4 types of sorting algorithms : Insertion sort, Heap sort, Shell sort, Quick sort. The sorting.c main function sets a seed and a random generator to  generate an array of default of 100 elements in sorted order along with stats of each method's amount of time it needed to move and compare. 
## Building

Files

README.md: A file meant to show how to build and run the program and how the program handles bugs. 
Makefile : A file that builds the sorting.c program and linked all the sort sources file to main
Sorting.c:
Test harness that produces an array based off command line.
-a : Employs all sorting algorithms. 
-e : Enables Heap Sort. 
-i : Enables Insertion Sort. 
-s : Enables Shell Sort. 
-q : Enables Quicksort. 
-r seed : Set the random seed to seed. The default seed should be 13371453.
-n size : Set the array size to size. The default size should be 100. 
-p elements : Print out the number of elements from the array.
-h : Prints out program usage. See reference program for example of what to print

DESIGN.pdf: Describes the entire assignment along with all information regarding the program

insert.c implements Insertion Sort.

insert.h specifies the interface to insert.c. 

heap.c implements Heap Sort.

heap.h specifies the interface to heap.c.

quick.c implements recursive Quicksort.

quick.h specifies the interface to quick.c.

set.h implements and specifies the interface for the set.

stats.c implements the statistics module. 

stats.h specifies the interface to the statistics module. 

shell.c implements Shell Sort.

shell.h specifies the interface to shell.c.

##RUNNING

INSTRUCTIONS

This program is intended to be run in the Ubuntu Virtual Box with PuTTY and in order to run program you will be given a list of commands when running the program using '-h'. It will provide you will many commands linked to each mathmatical method with statistics and differences provided.

