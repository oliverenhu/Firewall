#include "numtheory.h"
#include "randstate.h"
#include <gmp.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void gcd(mpz_t d, mpz_t a, mpz_t b){
	mpz_t at, bt, t;
	mpz_init_set(at,a);	
	mpz_init_set(bt,b);
	mpz_init(t);
	while(mpz_sgn(bt)!=0){
		mpz_set(t,bt);
		mpz_mod(bt,at,bt);
		mpz_set(at,t);
	}
	mpz_swap(d,at);
	mpz_clears(at,bt,t,NULL);
	return;
}
void mod_inverse(mpz_t i, mpz_t a, mpz_t n){
	mpz_t q, qri, rqri, qti, tqti,r,ri,t,ti;
	mpz_inits(q,qri,rqri,qti,tqti,NULL);
	mpz_init_set(r,n);
        mpz_init_set(ri,a);
	mpz_init_set_ui(t,0);
        mpz_init_set_ui(ti,1);
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
	gmp_printf("modin is %Zd \n",i);

	mpz_clears(q,qri,rqri,qti,tqti,r,ri,t,ti,NULL);
	return;
}
void pow_mod(mpz_t out, mpz_t base, mpz_t exponent, mpz_t modulus){
	mpz_t d, n, v, p, odd, vpmul,ppmul;
	mpz_init_set(d,exponent);
	mpz_init_set(n,modulus);
	mpz_init_set_ui(v,1);
	mpz_init_set(p,base);
	mpz_inits(vpmul,ppmul,odd,NULL);
	while(mpz_sgn(d)>0){
		mpz_mod_ui(odd,d,2);
		if(mpz_sgn(odd)==1){
			mpz_mul(vpmul,v,p);
			mpz_mod(v,vpmul,n);
			}
		mpz_mul(ppmul,p,p);
                mpz_mod(p,ppmul,n);
		mpz_fdiv_q_ui(d,d,2);
	}
	mpz_set(out,v);
	mpz_clears(d,n,v,p,odd,vpmul,ppmul,NULL);
	gmp_printf("powmod is %Zd \n",out);

	return;
}
bool is_prime(mpz_t n, uint64_t iters){
	mpz_t r,reven,twos,two,rand,a,y,y0,y1,j,mod,s,nr;
	mpz_init_set_ui(mod,1);
	mpz_init_set_ui(s,0);
	mpz_init_set_ui(two,2);
	mpz_inits(r,rand,a,y,y0,j,nr,NULL);
	mpz_sub_ui(nr,n,1);
	mpz_mod_ui(reven,r,2);
	mpz_sub_ui(rand,nr,2);

	while(mpz_sgn(reven)==0){
		mpz_powm(twos,two,s,mod);
		mpz_fdiv_q(r,nr,twos);
		mpz_mod_ui(reven,r,2);
		if(mpz_cmp(nr,two)<0){
			mpz_clears(r,reven,twos,two,rand,a,y,y0,y1,j,mod,s,nr,NULL);
			return false;
		}
		mpz_add_ui(s,s,1);
	}
	for(uint64_t i =1;i<iters;i+=1){
		mpz_urandomm(a,state,rand);
		mpz_add_ui(a,a,2);
		pow_mod(y,a,r,n);
		mpz_set(y,a);
		mpz_add_ui(y0,y,1);
		mpz_add_ui(y1,y,1);
		if(mpz_sgn(y0)!=0 && mpz_cmp(y,nr)!=0){
			mpz_set_ui(j,1);
			while(mpz_cmp(j,s)>-1 && mpz_cmp(y,nr)!=0){
				 pow_mod(y,y,two,n);
			 	 mpz_add_ui(y0,y,1);	 
		 		 if(mpz_sgn(y0)==0){
					mpz_clears(r,reven,twos,two,rand,a,y,y0,y1,j,mod,s,nr,NULL); 
				 	return false;	
				 }
				 mpz_add_ui(j,j,1);		 
			}
			if(mpz_cmp(y,nr)!=0){
				mpz_clears(r,reven,twos,two,rand,a,y,y0,y1,j,mod,s,nr,NULL);
				return false;
			}	
		}
	}
	mpz_clears(r,reven,twos,two,rand,a,y,y0,y1,j,mod,s,nr,NULL);
	return true;
	}

void make_prime(mpz_t p, uint64_t bits, uint64_t iters){
	mpz_t prime;
	size_t nob= bits;
	mpz_init_set(prime,p);
	mp_bitcnt_t maxsize=bits;
	while(!is_prime(prime,iters)||mpz_sizeinbase(prime,2)<nob){
		mpz_rrandomb(prime,state,maxsize);
	}
	mpz_set(p,prime);
	mpz_clear(prime);
	gmp_printf("mkp is %Zd \n",p);

	return;
}	
