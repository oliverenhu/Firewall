### Assignment 1 - Pass the Pigs

DESCRIPTION
This program runs a simple cyclic game based on asking the user for 2 inputs, asking for players between 2-10 as wellas a seed that provides a recreatable pattern of numbers. These inputs will be used to determine the retraints associated with the game. The program will determine a winner based on when the player will randomly roll to pig and land in a specified position to gain points until landing on side which, ends the player's turn and the next player's turn begins. Eventually the winner will be the person that reaches 100 points first and the game will end.

Pseudocode:

include name.h file / includes the names in a array required to be accessed by the game
include studio.h
include stdlib.h

enumerate pig positions(SIDE, RAZORBACK,TROTTER,SNOUTER,JOWLER) set each to an int associated with the amount of points
establish constant array type Position with the probabilities of the poistion associated with the size of array named pig[]
constant function get_position() that translates based on pig position rolled from in to string by using switch function
	return 0
initialize check_winner function

main
	define int players
	define long long seed
	print "How many players? "
	ask for int input players
	if(players <=1 or players >=11)
		print (" Invalid number of players . Using 2 instead .")
		players equal 2
	print ("Random seed: "
	ask for long long input seed 
	if(seed <=4294967295 and seed >= 0)
		set seed through srandom()
		check_winner() function input players
	else
		print(" Invalid random seed . using 2021 instead .")
		set 2021 through srandom
		check_winner() function input players
	return 0
void check winner function with input as (int players)
	define scores associated with each player as 0 in an array
	set win int to 0
WIN:
	while win equal 0
		interate through players with for loop starting from 0 to players with variable i
			define position as int
			define r as as int
			print((name[i]) rolls the pig...)
			do 
				if(scores[i] >= 100)
					print name[i] wins with scores[i] points!
					set win to 1
					goto WIN
				r equals random() mod 7
				position equal pig[r]
				position is added to players score
				if(r equal 0 or 1 )
					print pig lands on get_position(r)indentation(\n)
				else if r equal 3 
					print pig lands get_position(r)
				else
					print pig lands on get_position(r)
			while(position !=0) 

Files

names.h

Header file that is included in the pig.c implementation to provided names of players in an array

pig.c

This contains the implementation of the game.

Makefile

This file will be provided in the course resource repository. It is a file that directs program compi-lation, building the programpigfrompig.c.

README.md

It describe how to use your program.	

DESIGN.pdf

This design document must describe your design anddesign  process  for  your  program  with  enough  detail  such  that  a  sufficiently  knowledgeable  programmerwould be able to replicate your implementation.

INSTRUCTIONS

This program is intended to be run in the Ubuntu Virtual Box with PuTTY and in order to run program you must provide two inputs, one for the number of players and two for seed. 
