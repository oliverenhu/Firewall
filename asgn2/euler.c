#include <stdio.h>
#include "mathlib.h"

double pi_euler(){
        double error =1;
        double prepi;
        double pi=0;
        double pow;
        for(int k=1;EPSILON<error;k+=1) {
           pow=(1.000/(k*k));
           prepi=pi;
           pi+=pow;
	   error=pi-prepi;
        }
        pi=sqrt_newton(pi*6);
        printf("%f",pi);
	return pi;
}
int pi_euler_terms(){
        return 0;

}

