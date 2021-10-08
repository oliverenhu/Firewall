#include <stdio.h>
#include "mathlib.h"

int e_terms();
double e(){
	double error;
	double term = 1;
	double e = 1.0000000000000;
	double preterm=1;
	double pree;
	double cont=1;
	do{
		pree=e;
		printf("pree %.15f\n",pree);
		e+=cont/(term*preterm);
		printf("e %.15f\n",e);
		preterm=term*preterm;
	        printf("preterm %.15f\n",preterm);
		printf("term %f\n",term);
		term+=1;
		error=e-pree;
		printf("error %.15f\n",error);
	}while(error>EPSILON);
	printf("%f\n",term);
	printf("%.15f\n",e);
	return 0;
}
/*int e_terms(){
	printf("%d",term;

	return 0;
}*/

