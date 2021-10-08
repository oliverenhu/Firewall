#include <stdio.h>
#include "mathlib.h"
int term = 1;
int e_terms();
double e(){
	double error=1;
	double e = 1;
	double preterm=1;
	double pree;
	double cont=1;
	do{
		pree=e;

		e+=cont/(term*preterm);

		preterm=term*preterm;

	
		term+=1;
		error=e-pree;
		
	}while(error>EPSILON);
	
	printf("%.15f\n",e);
	return 0;
}
int e_terms(){
	printf("%d\n",term);

	return 0;
}

