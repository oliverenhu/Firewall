#include "numtheory.h"
#include "randstate.h"
#include "rsa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <gmp.h>
#include <time.h>
int main(int argc, char **argv) {
    char *username;	
    
    char *pub="rsa.pub";
    char *priv="rsa.priv";
    FILE *pbfile = stdout;
    FILE *pvfile = stdout;
    bool verbose = false;
    uint64_t seed=time(NULL);
    int opt = 0;
    uint64_t nbits=256;
    uint64_t iters=50;
    while ((opt = getopt(argc, argv, "b:i:n:d:s:vh")) != -1) {
        switch (opt) {
	case 'b': nbits=atoi(optarg);
	case 'i': iters=atoi(optarg);	  
        case 'n': pub = (optarg); break;
        case 'd': priv = (optarg); break;
	case 's': seed = atoi(optarg); break;	  
        case 'v': verbose = true; break;
        case 'h': printf("SYNOPSIS\n   Generates an RSA public/private key pair.\n\nUSAGE\n   ./keygen [-hv] [-b bits] -n pbfile -d pvfile\n\nOPTIONS\n   -h              Display program help and usage.\n   -v              Display verbose program output.\n   -b bits         Minimum bits needed for public key n (default: 256).\n   -i confidence   Miller-Rabin iterations for testing primes (default: 50).\n   -n pbfile       Public key file (default: rsa.pub).\n   -d pvfile       Private key file (default: rsa.priv).\n   -s seed         Random seed for testing.\n"); 
            return 0;
        }
    }
    pbfile=fopen(pub,"w+");
    if(pbfile==NULL){
	    printf("SYNOPSIS\n   Generates an RSA public/private key pair.\n\nUSAGE\n   ./keygen [-hv] [-b bits] -n pbfile -d pvfile\n\nOPTIONS\n   -h              Display program help and usage.\n   -v              Display verbose program output.\n   -b bits         Minimum bits needed for public key n (default: 256).\n   -i confidence   Miller-Rabin iterations for testing primes (default: 50).\n   -n pbfile       Public key file (default: rsa.pub).\n   -d pvfile       Private key file (default: rsa.priv).\n   -s seed         Random seed for testing.\n");
    return 0;
    }
    pvfile=fopen(priv,"w+");
    if(pvfile==NULL){
            printf("SYNOPSIS\n   Generates an RSA public/private key pair.\n\nUSAGE\n   ./keygen [-hv] [-b bits] -n pbfile -d pvfile\n\nOPTIONS\n   -h              Display program help and usage.\n   -v              Display verbose program output.\n   -b bits         Minimum bits needed for public key n (default: 256).\n   -i confidence   Miller-Rabin iterations for testing primes (default: 50).\n   -n pbfile       Public key file (default: rsa.pub).\n   -d pvfile       Private key file (default: rsa.priv).\n   -s seed         Random seed for testing.\n");
    return 0;
    }
    
    fchmod(fileno(pvfile),0600);
    randstate_init(seed);
    mpz_t p,q,e,n,d,usr,s;
    mpz_inits(p,q,e,n,d,usr,s,NULL);
    rsa_make_pub(p,q,n,e,nbits,iters);
    rsa_make_priv(d,e,p,q); 
    username=getenv("USER");
    mpz_set_str(usr,username,62);
    rsa_sign(s,usr,d,n);
    rsa_write_pub(n,e,s,username,pbfile);
    rsa_write_priv(n,d,pvfile);
    if(verbose){
    	gmp_printf("user = %s\ns (%zu bits) = %Zd\np (%zu bits) = %Zd\nq (%zu bits) = %Zd\nn (%zu bits) = %Zd\ne (%zu bits) = %Zd\nd (%zu bits) = %Zd\n",username,mpz_sizeinbase(s,2),s,mpz_sizeinbase(p,2),p,mpz_sizeinbase(q,2),q,mpz_sizeinbase(n,2),n,mpz_sizeinbase(e,2),e,mpz_sizeinbase(d,2),d);
    }
    mpz_clears(p,q,e,n,d,usr,s,NULL);
    randstate_clear();    
    fclose(pbfile);
    fclose(pvfile);
    return 0;	    
}

