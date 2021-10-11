#include "mathlib.h"
#include <math.h>
#include <stdio.h>
double fabsminus(double y, double z);
int sqrterms = 0;
double sqrt_newton(double x) {
    double z = 0.0;
    double y = 1.0;
    sqrterms = 0;
    while (fabsminus(y, z) > EPSILON) {
        z = y;
        y = 0.5 * (z + x / z);
        sqrterms += 1;
	printf("sqrt_newton(%.6f) = %.15f, sqrt(%.6f)= %.15f, diff = %.15f\n", x,
                    y, x, sqrt(x), fabs(y - sqrt(x)));

    }

    //printf("%f",y);
    return y;
}
double fabsminus(double y, double z) {
    double zero = 0;
    if (y - z > zero) {
        return y - z;
    } else {
        return (-1 * (y - z));
    }
}
int sqrt_newton_iters() {
    return sqrterms;
}
