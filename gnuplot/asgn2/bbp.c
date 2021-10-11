#include "mathlib.h"

#include <stdio.h>
int bbpterms = 1;
double pi_bbp() {

    double error = 1;
    double prepi;
    double pi = (47.0 / 15.0);
    double pow = 1;
    double base;
    bbpterms = 1;
    for (int k = 1; EPSILON < error; k += 1) {
        for (int i = 1; i <= k; i += 1) {
            pow *= (1.000 / (16.000));
        }

        prepi = pi;
        base = (k * (120.0 * k + 151.0) + 47.0)
               / (k * (k * (k * (512.0 * k + 1024.0) + 712.0) + 194.0) + 15.0);
        pi += pow * base;

        error = pi - prepi;

        pow = 1;
        bbpterms += 1;
    }

    return pi;
}
int pi_bbp_terms() {

    return bbpterms;
}
