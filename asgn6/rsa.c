#include "rsa.h"
#include "randstate.h"
#include "numtheory.h"


void rsa_make_pub(mpz_t p, mpz_t q, mpz_t n, mpz_t e, uint64_t nbits, uint64_t iters){
	mpz_t pbits, qbits, twobit,buf,tot,pt,qt,co,d;
	mpz_inits(pbits,qbits,twobit,buf,tot,pt,qt,co,d);
	mpz_fdiv_q_ui(buf,nbits,4);
	mpz_mul_ui(twobit,nbits,2);
	mpz_fdiv_q_ui(twobits,4);
	mpz_add_ui(twobit,1);
	mpz_urandomm(pbits,state,twobit);
	mpz_add(pbits,pbits,buf);
	mpz_sub(qbits,nbits,pbits);
	make_prime(p,pbits,iters);
	make_prime(q,qbits,iters);
	mpz_mul(n,p,q);
	mpz_sub_ui(pt,p,1);
	mpz_sub_ui(qt,q,1);
	mpz_mul(tot,pt,qt);
	do{
	mpz_urandomb(co,state,nbits);	
	gcd(d,co,tot);
	}while(mpz_cmp_ui(d,1)!=0);
	mpz_set(e,co);
	
}

void rsa_write_pub(mpz_t n, mpz_t e, mpz_t s, char username[], FILE *pbfile);

void rsa_read_pub(mpz_t n, mpz_t e, mpz_t s, char username[], FILE *pbfile);

void rsa_make_priv(mpz_t d, mpz_t e, mpz_t p, mpz_t q);

void rsa_write_priv(mpz_t n, mpz_t d, FILE *pvfile);

void rsa_read_priv(mpz_t n, mpz_t d, FILE *pvfile);

void rsa_encrypt(mpz_t c, mpz_t m, mpz_t e, mpz_t n);

void rsa_encrypt_file(FILE *infile, FILE *outfile, mpz_t n, mpz_t e);

void rsa_decrypt(mpz_t m, mpz_t c, mpz_t d, mpz_t n);

void rsa_decrypt_file(FILE *infile, FILE *outfile, mpz_t n, mpz_t d);

void rsa_sign(mpz_t s, mpz_t m, mpz_t d, mpz_t n);

bool rsa_verify(mpz_t m, mpz_t s, mpz_t e, mpz_t n);

