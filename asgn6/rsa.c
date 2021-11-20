#include "rsa.h"
#include "randstate.h"
#include "numtheory.h"
#include <stdlib.h>

void rsa_make_pub(mpz_t p, mpz_t q, mpz_t n, mpz_t e, uint64_t nbits, uint64_t iters) {
    mpz_t pbits, qbits, nbit, twobit, buf, tot, pt, qt, co, d;
    mp_bitcnt_t bit = nbits;
    mpz_inits(pbits, qbits, nbit, twobit, buf, tot, pt, qt, co, d, NULL);
    mpz_init_set_ui(nbit, nbits);
    mpz_fdiv_q_ui(buf, nbit, 4);
    mpz_mul_ui(twobit, nbit, 2);
    mpz_fdiv_q_ui(twobit, twobit, 4);
    mpz_add_ui(twobit, twobit, 1);
    mpz_urandomm(pbits, state, twobit);
    mpz_add(pbits, pbits, buf);
    mpz_sub(qbits, nbit, pbits);
    make_prime(p, mpz_get_ui(pbits), iters);
    make_prime(q, mpz_get_ui(qbits), iters);
    mpz_mul(n, p, q);
    mpz_sub_ui(pt, p, 1);
    mpz_sub_ui(qt, q, 1);
    mpz_mul(tot, pt, qt);
    
    do {
        mpz_urandomb(co, state, bit);
        gcd(d, co, tot);
    } while (mpz_cmp_ui(d, 1) != 0);
    mpz_set(e, co);
    //	gmp_printf("pbits %Zd",pbits);
    //	gmp_printf("pbits %Zd",qbits);
    mpz_clears(pbits, qbits, nbit, twobit, buf, tot, pt, qt, co, d, NULL);
}

void rsa_write_pub(mpz_t n, mpz_t e, mpz_t s, char username[], FILE *pbfile) {
    gmp_fprintf(pbfile, "%Zx\n%Zx\n%Zx\n", n, e, s);
    gmp_fprintf(pbfile, "%s", username);
}
void rsa_read_pub(mpz_t n, mpz_t e, mpz_t s, char username[], FILE *pbfile) {

    gmp_fscanf(pbfile, "%Zx\n%Zx\n%Zx\n%s",n, e, s, username);
}

void rsa_make_priv(mpz_t d, mpz_t e, mpz_t p, mpz_t q) {
    mpz_t ptot, p1, q1;
    mpz_inits(ptot, p1, q1, NULL);
    mpz_sub_ui(p1, p, 1);
    mpz_sub_ui(q1, q, 1);
    mpz_mul(ptot, p1, q1);
    mod_inverse(d, e, ptot);
  //  gmp_printf("tot %Zd\n",ptot);
    mpz_clears(ptot, p1, q1, NULL);
}
void rsa_write_priv(mpz_t n, mpz_t d, FILE *pvfile) {
    gmp_fprintf(pvfile, "%Zx\n%Zx\n", n, d);
}
void rsa_read_priv(mpz_t n, mpz_t d, FILE *pvfile) {
    gmp_fscanf(pvfile, "%Zx\n%Zx\n", n, d);
}
void rsa_encrypt(mpz_t c, mpz_t m, mpz_t e, mpz_t n) {
    pow_mod(c, m, e, n);
}
void rsa_encrypt_file(FILE *infile, FILE *outfile, mpz_t n, mpz_t e) {
    mpz_t k, m, encrypt;
    size_t j;
    
    
    mpz_inits(k, m, encrypt,NULL);
    size_t log = mpz_sizeinbase(n, 2);
    mpz_set_ui(k, log);
    mpz_sub_ui(k, k, 1);
    mpz_fdiv_q_ui(k, k, 8);
    
    
    
    uint8_t *kbytes = (uint8_t *) calloc(mpz_get_ui(k), sizeof(uint8_t));
    kbytes[0] = 0xff;
    
    do{
        
    j = fread(kbytes+1 ,1 , mpz_get_ui(k) - 1, infile);
    
    mpz_import(m, j + 1, 1, 1, 1, 0, kbytes);
    rsa_encrypt(encrypt, m, e, n);
    gmp_fprintf(outfile, "%Zx\n", encrypt);
    
    }while(j==mpz_get_ui(k)-1);
    mpz_clears(k,m,encrypt,NULL);
    free(kbytes);
}
void rsa_decrypt(mpz_t m, mpz_t c, mpz_t d, mpz_t n) {
    pow_mod(m, c, d, n);
}
void rsa_decrypt_file(FILE *infile, FILE *outfile, mpz_t n, mpz_t d) {
    size_t j;
    mpz_t k, c, decrypt;
    mpz_inits(k, c, decrypt,NULL);
    size_t log = mpz_sizeinbase(n, 2);
    mpz_set_ui(k, log);
    mpz_sub_ui(k, k, 1);
    mpz_fdiv_q_ui(k, k, 8);
    uint8_t *kbytes = (uint8_t *) calloc(mpz_get_ui(k), sizeof(uint8_t));
    do{
    j = gmp_fscanf(infile, "%Zx\n", c);
    
    rsa_decrypt(decrypt, c, d, n);
    mpz_export(kbytes, &j, 1, 1, 1, 0, decrypt);
    fwrite(kbytes + 1, 1, j - 1, outfile);
    if(feof(infile)){
        break;
		    }    
    }while(1);
    mpz_clears(k,c,decrypt,NULL);
    free(kbytes); 
}
void rsa_sign(mpz_t s, mpz_t m, mpz_t d, mpz_t n) {
    pow_mod(s, m, d, n);
}
bool rsa_verify(mpz_t m, mpz_t s, mpz_t e, mpz_t n) {
    mpz_t t;
    mpz_init(t);
    pow_mod(t, s, e, n);
    if (mpz_cmp(t, m) == 0) {
        mpz_clear(t);
        return true;
    }
    mpz_clear(t);
    return false;
}
