#include "randstate.h"
#include <gmp.h>
#include <stdint.h>

gmp_randstate_t state; //initiates state from header file
void randstate_init(uint64_t seed) { //sets randinit state to seed
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, seed);
}

void randstate_clear(void) { //clears state
    gmp_randclear(state);
}
