# include <stdio.h>
# include <unistd.h>
# include "mathlib.h"
# include <math.h>
# define OPTIONS "aebmrvnsh"

int main ( int argc , char ** argv ) {
	int opt = 0;
	while (( opt = getopt (argc , argv , OPTIONS )) != -1) {
		switch ( opt ) {
		case 'e':
		
		e();
		e_terms();		
		break;
		case 'm':
		//sqrt_newton(12);
		pi_madhava();
		pi_madhava_terms();
		break ;
		case 'r':
		
		pi_euler();
		break;
		
		case 'b':
		pi_bbp();
		pi_bbp_terms();
		break;
		case 'v':
		pi_viete();
		pi_viete_factors();
		break;
		}


	}	
	return 0;
	}

