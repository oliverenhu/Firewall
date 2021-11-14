#include "numtheory.h"
#include "randstate.h"
#include <gmp.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void gcd(mpz_t d, mpz_t a, mpz_t b);
	mpz_init_set(at,a);
	mpz_init_set(bt,b);
	mpz_init(t);
	while(mpz_sgn(bt)!=0){
		mpz_set(t,bt);
		mpz_mod(bt,at,bt);
		mpz_set(at,t);
	}
	mpz_set(d,at);

void mod_inverse(mpz_t i, mpz_t a, mpz_t n);
	mpz_init_set(r,n);
        mpz_init_set(ri,a);
	mpz_init_set_ui(t,0);
        mpz_init_set_ui(ti,1);
	mpz_t q, qri, rqri, qti, tqti;
	while(mpz_sgn(ri)!=0){
		mpz_fdiv_q(q,r,ri);
		mpz_set(r,ri);
		mpz_mul(qri,q,ri);
		mpz_sub(rqri,r,qri);
                mpz_set(t,ti);
                mpz_mul(qti,q,ti);
                mpz_sub(tqti,t,qti);		
	}
	if(mpz_sgn(t)==-1){
		mpz_add(t,t,n);
		mpz_set(i,t);
	}
	if(mpz_cmp_ui(r,1)>0){
		mpz_set_ui(i,0);	
	}

void pow_mod(mpz_t out, mpz_t base, mpz_t exponent, mpz_t modulus){
	mpz_t v, p, odd, vpmul,ppmul;
	mpz_init_set(d,exponent);
	mpz_init_set(n,modulus);
	mpz_init_set_ui(v,1);
	mpz_init_set(p,base);
	while(mpz_sgn(d)>0){
		mpz_mod(odd,d,2);
		if(mpz_sgn(odd)==1){
			mpz_mul(vpmul,v,p);
			mpz_mod(v,vpmul,n);
			}
		mpz_mul(ppmul,p,p);
                mpz_mod(p,ppmul,n);
		mpz_fdiv_q(d,d,2);
	}
	mpz_set(out,v);
}
bool is_prime(mpz_t n, uint64_t iters){
	mpz_t r,reven,twos,two;
	mpz_init_set_ui(mod,1);
	mpz_init_set_ui(s,0);
	mpz_init_set_ui(two,2);
	mpz_sub(r,n,1);
	mpz_mod(reven,r,2);
	while(reven==0){
		mpz_powm(twos,two,s,two
		mpz_div(r,r,twos)
		mpz_mod_ui(reven,r,2);
	}
}
void make_prime(mpz_t p, uint64_t bits, uint64_t iters);

