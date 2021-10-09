# include <stdio.h>
# include <unistd.h>
# include "mathlib.h"
# define OPTIONS "aebmrvnsh"

int main ( int argc , char ** argv ) {
	int opt = 0;
	while (( opt = getopt (argc , argv , OPTIONS )) != -1) {
		switch ( opt ) {
		case 'e':
		printf ("- option .\n");
		e();
		e_terms();		
		break;
		case 'm':
		
		pi_madhava();
		break ;
		}
		}	
	return 0;
	}

