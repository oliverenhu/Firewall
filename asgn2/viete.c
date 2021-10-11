#include <stdio.h>
#include "mathlib.h"
int vieterms=0;
double pi_viete(){
        double error =1;
        double prepi;
        double pi=sqrt_newton(2)/2.0;
        double pow=sqrt_newton(2);
	vieterms=0;
	while(EPSILON<error) {
        	
		pow=sqrt_newton(pow+2);
	   	
        	prepi=pi;
        	   
		pi*=pow/2.0;   
	   	error=prepi-pi;
		vieterms+=1;
        }	
        pi=2.0/pi;
	        
        
	return pi;
}
int pi_viete_factors(){
	
        return vieterms;  

}



