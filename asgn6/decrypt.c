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
    
    
    char *priv="rsa.priv";
    FILE *infile = stdin;
    FILE *outfile = stdout;
    FILE *privkey = stdin;
    bool verbose = false;
    int opt = 0;
    while ((opt = getopt(argc, argv, "i:o:nvh")) != -1) {
        switch (opt) {
        case 'i': infile= fopen(optarg,"r"); break;
        case 'o': outfile= fopen(optarg,"w+"); break;
	case 'n': priv = optarg; break;	  
        case 'v': verbose = true; break;
        case 'h': printf("SYNOPSIS\n   Encrypts data using RSA encryption.\n   Encrypted data is decrypted by the decrypt program.\n\nUSAGE\n   ./encrypt [-hv] [-i infile] [-o outfile] -n pubkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v              Display verbose program output.\n   -i infile       Input file of data to encrypt (default: stdin).\n   -o outfile      Output file for encrypted data (default: stdout).\n   -n pbfile       Public key file (default: rsa.pub).\n");
            return 0;
        }
    }	
	
	mpz_t n,e,d;
        mpz_inits(n,e,d,NULL);
	privkey=fopen(priv,"r");
	if(privkey==NULL){
            printf("SYNOPSIS\n   Encrypts data using RSA encryption.\n   Encrypted data is decrypted by the decrypt program.\n\nUSAGE\n   ./encrypt [-hv] [-i infile] [-o outfile] -n pubkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v              Display verbose program output.\n   -i infile       Input file of data to encrypt (default: stdin).\n   -o outfile      Output file for encrypted data (default: stdout).\n   -n pbfile       Public key file (default: rsa.pub).\n");
		return 0;
	}
	if(infile==NULL){
	printf("SYNOPSIS\n   Encrypts data using RSA encryption.\n   Encrypted data is decrypted by the decrypt program.\n\nUSAGE\n   ./encrypt [-hv] [-i infile] [-o outfile] -n pubkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v              Display verbose program output.\n   -i infile       Input file of data to encrypt (default: stdin).\n   -o outfile      Output file for encrypted data (default: stdout).\n   -n pbfile       Public key file (default: rsa.pub).\n");
                return 0;
        }


	rsa_read_priv(n,d,privkey);
	mod_inverse(e,d,n);
	if(verbose){
	
    	gmp_printf("n (%zu bits) = %Zd\ne (%zu bits) = %Zd\n",mpz_sizeinbase(n,2),n,mpz_sizeinbase(e,2),e);
        }
	
	
	rsa_decrypt_file(infile,outfile,n,d);
		
	mpz_clears(e,n,d,NULL);
	fclose(infile);
	fclose(outfile);
	fclose(privkey);
	return 0;

}

