#include "numtheory.h"
#include "randstate.h"
#include <gmp.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void gcd(mpz_t d, mpz_t a, mpz_t b) { //init sets  a and b mpz to temp variables
    mpz_t at, bt, t;
    mpz_init_set(at, a);
    mpz_init_set(bt, b);
    mpz_init(t);
    while (mpz_sgn(bt) != 0) { //while bt is zero
        mpz_set(t, bt); //t stores b
        mpz_mod(bt, at, bt); //b equal a mod b
        mpz_set(at, t); //a equal t
    }
    mpz_set(d, at); //gcd is a
    mpz_clears(at, bt, t, NULL);
    return;
}
void mod_inverse(mpz_t i, mpz_t a, mpz_t n) {
    mpz_t q, qri, rqri, tqti, qti, r, ri, t, ti; //r,r',t,t'are stored as n,a,0,1
    mpz_inits(q, qri, qti, rqri, tqti, NULL);
    mpz_init_set(r, n);
    mpz_init_set(ri, a);
    mpz_init_set_ui(t, 0);
    mpz_init_set_ui(ti, 1);
    while (mpz_sgn(ri) != 0) { //while r' == 0
        mpz_fdiv_q(q, r, ri); //q=floor[r/r']
        mpz_mul(qri, q, ri); //(r,r')=(r',r-q*r'))
        mpz_sub(rqri, r, qri);
        mpz_set(r, ri);
        mpz_set(ri, rqri);
        mpz_mul(qti, q, ti); //(t,t')=(t',t-q*t')
        mpz_sub(tqti, t, qti);
        mpz_set(t, ti);
        mpz_set(ti, tqti);
    }

    if (mpz_cmp_ui(r, 1) > 0) { //if r greater than 1 return 0
        mpz_set_ui(i, 0);
        mpz_clears(q, qri, qti, rqri, tqti, r, ri, t, ti, NULL);

        return;
    }
    if (mpz_sgn(t) == -1) { //if t less than 0 return t+n
        mpz_add(t, t, n);
    }
    mpz_set(i, t);

    mpz_clears(q, qri, qti, r, ri, t, ti, rqri, tqti, NULL);
    return;
}
void pow_mod(mpz_t out, mpz_t base, mpz_t exponent, mpz_t modulus) {
    mpz_t d, n, v, p, odd, vpmul, ppmul;
    mpz_init_set(d, exponent);
    mpz_init_set(n, modulus);
    mpz_init_set_ui(v, 1);
    mpz_init_set(p, base);
    mpz_inits(vpmul, ppmul, odd, NULL); //while d>0 if d is
    while (mpz_sgn(d) > 0) {
        mpz_mod_ui(odd, d, 2);
        if (mpz_sgn(odd) == 1) { //if d is odd
            mpz_mul(vpmul, v, p); //v = v*p mod n
            mpz_mod(v, vpmul, n);
        }
        mpz_mul(ppmul, p, p); //p = p*p mod n
        mpz_mod(p, ppmul, n); //d = floor(d/2)
        mpz_fdiv_q_ui(d, d, 2);
    }

    mpz_set(out, v); //return v into out
    mpz_clears(d, n, v, p, odd, vpmul, ppmul, NULL);

    return;
}
bool is_prime(mpz_t n, uint64_t iters) {

    if (mpz_sgn(n) == 0 || mpz_cmp_ui(n, 4) == 0) { //0 and 4 are not prime
        return false;
    }
    if (mpz_cmp_ui(n, 2) == 0 || mpz_cmp_ui(n, 3) == 0) { // 2 and 3 are prime
        return true;
    }
    //write n-1 = 2^(s)*r such that r is odd
    mpz_t r, reven, two, twos, rand, a, y, s1, j, s, nr;
    mpz_init_set_ui(s, 0);
    mpz_init_set_ui(two, 2);
    mpz_inits(r, reven, twos, rand, a, y, s1, j, nr, NULL);
    mpz_sub_ui(nr, n, 1);
    mpz_sub_ui(rand, nr, 2);
    mpz_set_ui(twos, 1);

    mpz_fdiv_q(r, nr, twos);
    mpz_mod_ui(reven, r, 2);
    while (mpz_get_ui(reven) == 0) { //while loop checks which r is even iterates s
        mpz_add_ui(s, s, 1);

        mpz_mul_ui(twos, twos, 2);

        if (mpz_cmp(nr, twos) < 0) {
            mpz_clears(r, reven, two, twos, rand, a, y, s1, j, s, nr, NULL);
            return false;
        }
        mpz_fdiv_q(r, nr, twos);
        mpz_mod_ui(reven, r, 2);
    }
    mpz_sub_ui(s1, s, 1);
    for (uint64_t i = 1; i < iters; i += 1) { //iters k -1 times
        mpz_urandomm(a, state, rand);
        mpz_add_ui(a, a, 2);
        pow_mod(y, a, r, n); //random between [2:n-2]and y= powermod (random,r,n)
        if (mpz_cmp_ui(y, 1) != 0 && mpz_cmp(y, nr) != 0) {
            mpz_set_ui(j, 1);

            while (mpz_cmp(j, s1) <= 0 && mpz_cmp(y, nr) != 0) {

                pow_mod(y, y, two, n); //powermod(y,2,n)

                if (mpz_cmp_ui(y, 1) == 0) {
                    mpz_clears(r, reven, two, twos, rand, a, y, s1, j, s, nr, NULL);
                    return false;
                }
                mpz_add_ui(j, j, 1);
            }
            if (mpz_cmp(y, nr) != 0) {
                mpz_clears(r, reven, two, twos, rand, a, y, s1, j, s, nr, NULL);
                return false;
            }
        }
    }
    mpz_clears(r, reven, twos, two, s, nr, rand, a, y, s1, j, NULL);
    return true;
}

void make_prime(mpz_t p, uint64_t bits,
    uint64_t iters) { //generates a prime passed into p using (bits,iters) as parameters in isprime
    mpz_t prime;
    size_t nob = bits;
    mpz_init_set(prime, p);
    mp_bitcnt_t maxsize = bits;
    while (!is_prime(prime, iters) || mpz_sizeinbase(prime, 2) < nob) {
        mpz_rrandomb(prime, state, maxsize);
    }
    mpz_set(p, prime);
    mpz_clear(prime);

    return;
}
