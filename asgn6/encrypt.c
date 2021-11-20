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
    
    char username[10];
    char *pub="rsa.pub";
    FILE *infile = stdin;
    FILE *outfile = stdout;
    FILE *pubkey = stdin;
    bool verbose = false;
    int opt = 0;
    while ((opt = getopt(argc, argv, "i:o:n:vh")) != -1) {
        switch (opt) {
        case 'i': infile= fopen(optarg,"r"); break;
        case 'o': outfile= fopen(optarg,"w+"); break;
	case 'n': pub = optarg; break;	  
        case 'v': verbose = true; break;
        case 'h': printf("SYNOPSIS\n   Encrypts data using RSA encryption.\n   Encrypted data is decrypted by the decrypt program.\n\nUSAGE\n   ./encrypt [-hv] [-i infile] [-o outfile] -n pubkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v              Display verbose program output.\n   -i infile       Input file of data to encrypt (default: stdin).\n   -o outfile      Output file for encrypted data (default: stdout).\n   -n pbfile       Public key file (default: rsa.pub).\n");
            return 0;
        }
    }	
	
	mpz_t usr,s,n,e;
        mpz_inits(usr,s,n,e,NULL);
	printf("%s",pub);
	pubkey=fopen(pub,"r");
	if(pubkey==NULL){
            printf("SYNOPSIS\n   Encrypts data using RSA encryption.\n   Encrypted data is decrypted by the decrypt program.\n\nUSAGE\n   ./encrypt [-hv] [-i infile] [-o outfile] -n pubkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v              Display verbose program output.\n   -i infile       Input file of data to encrypt (default: stdin).\n   -o outfile      Output file for encrypted data (default: stdout).\n   -n pbfile       Public key file (default: rsa.pub).\n");
	    	
	    return 0;
	}
	if(infile==NULL){
	printf("SYNOPSIS\n   Encrypts data using RSA encryption.\n   Encrypted data is decrypted by the decrypt program.\n\nUSAGE\n   ./encrypt [-hv] [-i infile] [-o outfile] -n pubkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v              Display verbose program output.\n   -i infile       Input file of data to encrypt (default: stdin).\n   -o outfile      Output file for encrypted data (default: stdout).\n   -n pbfile       Public key file (default: rsa.pub).\n");
                return 0;
        }


	rsa_read_pub(n,e,s,username,pubkey);
	if(verbose){
	
    	gmp_printf("user = %s\ns (%zu bits) = %Zd\nn (%zu bits) = %Zd\ne (%zu bits) = %Zd\n",username,mpz_sizeinbase(s,2),s,mpz_sizeinbase(n,2),n,mpz_sizeinbase(e,2),e);
        }
	
	mpz_set_str(usr,username,62);
	if(!rsa_verify(usr,s,e,n)){
		printf("No permission");
		return 0;	
		}
	rsa_encrypt_file(infile,outfile,n,e);
		
	mpz_clears(usr,s,e,n,NULL);
	fclose(infile);
	fclose(outfile);
	fclose(pubkey);
	return 0;

}
