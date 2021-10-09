#include <stdio.h>
#include "mathlib.h"
double fabsminus(double y,double z);
double sqrt_newton(double x){
	double z = 0.0;
	double y = 1.0;
	while(fabsminus(y,z) > EPSILON){
	z = y;
	y = 0.5 * (z + x / z);
	}
	
	printf("%f",y);
	return y;
}
double fabsminus(double y,double z){
	double zero = 0;
	if(y-z>zero){
		return y-z;
	}
	else{
	return (-1*(y-z));	


}
}
