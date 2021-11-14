#include "numtheory.h"
#include "randstate.h"
#include <gmp.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void gcd(mpz_t g, mpz_t a, mpz_t b);
	mpz_init_set(at,a);
	mpz_init_set(bt,b);
	mpz_init(t);
	while(mpz_sgn(bt)!=0){
		mpz_set(t,bt);
		mpz_mod(bt,at,bt);
		mpz_set(at,t);
	}
	mpz_set(d,at);

void mod_inverse(mpz_t o, mpz_t a, mpz_t n);

void pow_mod(mpz_t o, mpz_t a, mpz_t d, mpz_t n){
	mpz_t v, p, odd, vpmul,ppmul;
	mpz_init_set_ui(v,1);
	mpz_init_set(p,a);
	while(mpz_sgn(d)>0){
		mpz_mod(odd,d,2);
		if(mpz_sgn(odd)==1){
			mpz_mul(vpmul,v,p);
			mpz_mod(v,vpmul,n);
			}
		mpz_mul(ppmul,p,p);
                mpz_mod(p,ppmul,n);
		mpz_div(d,d,2);
	}
	return v;
}
bool is_prime(mpz_t n, uint64_t iters){
	mpz_t r,reven,s,twos,two;
	mpz_init(twos);
	mpz_init(reven);
	mpz_init(s);
	mpz_set(s,0);
	mpz_init(r);
	mpz_sub(r,n,1);
	mpz_mod(reven,r,2);
	while(reven==0){

		mpz_div(r,
		mpz_mod(reven,r,2);
	}
}
void make_prime(mpz_t p, uint64_t bits, uint64_t iters);

