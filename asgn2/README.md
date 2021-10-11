# Assignment 2 - A Little Slice of Pi

DESCRIPTION
This program simulates calculating mathematical constants e and pi. These constants are calculated term by term from summations and terms required are determined by once the error between terms to become less than the given constant EPSILON e =10-14. The main program mathlib-test.c compiles all the methods of solving e and pi and allows for the users to use created commands denoted with a ‘-’ that print out statistics and differences between the methods. The commands’-h’ show how to use the program along with all the possible commands the program can run. Overall the program uses multiple methods of calculating pi and can reveal data such as the amount of terms required to reach pi or e allowing for the user to better understand how well the methods can approximate pi.
## Building

Files

e.c:
Implements e() and e_terms()

bbp.c: 
Implements pi_bbp() and pi_bbp_terms()

euler.c: 
Implements pi_euler() and pi_euler_terms()
madhava.c: 
Implements pi_madhava() and pi_madhava_terms()

mathlib-test.c: 
This contains the main() function which tests each of your math library functions. 
Contains the commands
-a : Runs all tests. 
-e : Runs e approximation test. 
-b : Runs Bailey-Borwein-Plouffe π approximation test. 
-m : Runs Madhava π approximation test. 
-r : Runs Euler sequence π approximation test. 
-v : Runs Viète π approximation test. 
-n : Runs Newton-Raphson square root approximation tests.
-s : Enable printing of statistics to see computed terms and factors for each tested function. 
-h : Display a help message detailing program usage.

mathlib.h: 
This contains the interface for your math library. 

newton.c: Implementation of the square root approximation sqrt_newton()and the function to return the number of computed iterations sqrt_newton_iters(). 

viete.c: 
This contains the implementation of Viète’s formula to approximate π and the function to return the number of computed factors. Includes pi_viete() and pi_viete_factors()

Makefile

Linked source file to main through command prompt and allowing for new source files to be run quickly. It also cleans up the file format tools and makes it more accessible

README.md

It describe how to use your program.

DESIGN.pdf

This design document must describe your design anddesign  process  for  your  program  with  enough  detail  such  that  a  sufficiently  knowledgeable  programmerwould be able to replicate your implementation.

WRITEUP.pdf
Includes graphs comparing the methods and terms used to approach e and pi.

##RUNNING

INSTRUCTIONS

This program is intended to be run in the Ubuntu Virtual Box with PuTTY and in order to run program you will be given a list of commands when running the program using '-h'. It will provide you will many commands linked to each mathmatical method with statistics and differences provided.

