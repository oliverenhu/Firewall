#include <stdio.h>
#include "mathlib.h"

double sqrt_newton(double x){
	double z = 0.0;
	double y = 1.0;
	while((y-z) > EPSILON){
	z = y;
	y = 0.5 * (z + x / z);
	}
	
	printf("%f",y);
	return y;
}
