#include <stdio.h>
#include "mathlib.h"

int terms =1;
double pi_madhava(){
	double error =1;
	double prepi;
	double pi=1;
	double pow=1;
	terms=1;
	for(int k=1;EPSILON<error;k+=1){
		for(int i=1;i<=k;i+=1){
			pow*=(1.0/-3.0);
		}
		prepi=(pow)/(2*k+1);
            	pi+=prepi;
            	if((prepi)>0){
                error=prepi;
            	}
            	else {
                error=-1*prepi;
            	}
            	pow=1;
		terms+=1;
	}
	pi=sqrt_newton(12)*pi;
	
	return pi;
}
int pi_madhava_terms(){

	return terms;
}
