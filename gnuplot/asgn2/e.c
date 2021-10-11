#include "mathlib.h"
#include <math.h>
#include <stdio.h>
int term = 1; //allows for the term to be counted

double e() {
    double error = 1; //initializes error as 1 before it is overwritten in do-while loop
    double e = 1; //declared with 1 as base term of e
    double preterm = 1; //declared as base term of e mean to compare terms
    double pree; //declared as pree to be the previous term of e
    term = 1; //allows for term to be reinitialized
    do {
        pree = e; //sets pree to e

        e += 1 / (term * preterm); //simulates a factorial and adds it to e as a summation

        preterm = term * preterm; //factorial is saved in preterm

        term += 1; // term plus 1
        error = e - pree; // error is caculated and compared to EPSILON in while loop
	printf("e() = %.15f, M_E = %.15f, diff = %.15f\n", e, M_E, fabs(e - M_E));

    } while (error > EPSILON);

    return e;
}
int e_terms() {

    return term;
}
