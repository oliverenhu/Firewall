#include <stdio.h>
#include "mathlib.h"
int term = 1;

double e(){
	double error=1;
	double e = 1;
	double preterm=1;
	double pree;
	term=1;
	do{
		pree=e;

		e+=1/(term*preterm);

		preterm=term*preterm;

	
		term+=1;
		error=e-pree;
		
	}while(error>EPSILON);
	
	
	return e;
}
int e_terms(){
	

	return term;
}

