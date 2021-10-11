#include "mathlib.h"
#include <math.h>
#include <stdio.h>
int vieterms = 0;
double pi_viete() {
    double error = 1;
    double prepi;
    double pi = sqrt_newton(2) / 2.0;
    double pow = sqrt_newton(2);
    vieterms = 0;
    while (EPSILON < error) {

        pow = sqrt_newton(pow + 2);

        prepi = pi;

        pi *= pow / 2.0;
        error = prepi - pi;
        vieterms += 1;
	printf("pi_viete() = %.15f, M_PI = %.15f, diff = %.15f\n",2.0/ pi, M_PI, fabs(2.0/pi - M_PI));

    }
    pi = 2.0 / pi;

    return pi;
}
int pi_viete_factors() {

    return vieterms;
}
