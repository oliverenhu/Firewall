#include "mathlib.h"
#include <math.h>
#include <stdio.h>

int eulerterms = 0;
double pi_euler() {
    double error = 1;
    double prepi;
    double pi = 0;
    double pow;
    eulerterms = 0;
    for (double k = 1; EPSILON < error; k += 1) {
        pow = (1.000 / (k * k));
        prepi = pi;
        pi += pow;
        error = pi - prepi;
        eulerterms += 1;
	double pie = sqrt_newton(pi * 6.0);
	printf("pi_euler() = %.15f, M_PI = %.15f, diff = %.15f\n", pie, M_PI,fabs(pie - M_PI));
    }
    

    return pi;
}
int pi_euler_terms() {
    return eulerterms;
}
