#include <stdio.h>
#include "mathlib.h"

double pi_madhava(){
	double error =1;
	double prepi;
	double pi=1;
	float pow=1;
	for(int k=1;EPSILON<error;k+=1){
		for(int i=k;i>0;i-=1){
			pow*=(1/-3);
		}
		prepi=sqrt_newton(12)*(pow)/(2*k+1);
		pi+=prepi;
		error=pi-prepi;
	}
	printf("%f",pi);
	return 0;
}
