#include "randstate.h"
#include <gmp.h>
#include <stdint.h>

gmp_randstate_t state;
void randstate_init(uint64_t seed) {
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, seed);
}

void randstate_clear(void) {
    gmp_randclear(state);
}
