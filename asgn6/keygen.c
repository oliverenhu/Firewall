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
    FILE *pbfile = stdout;
    FILE *pvfile = stdout;
    bool verbose = false;
    int opt = 0;
    int bits;
    while ((opt = getopt(argc, argv, "b:i:n:d:s:vh")) != -1) {
        switch (opt) {
	case 'b': bits=atoi(optarg);
        case 'i': pbfile = fopen(optarg, "w"); break;
        case 'o': pvfile = fopen(optarg, "w"); break;
        case 'v': verbose = true; break;
        case 'h':
            return 0;
        }
    }
    mpz_t d,a,b,c;
    mpz_init(d);
    mpz_init_set_ui(a,659);
    mpz_init_set_ui(b,2);
    mpz_init_set_ui(c,9);

    randstate_init(time(NULL));    
    make_prime(d,256,50);
    gmp_printf("make prime nis %Zd \n",d);	
    
 
  
    mpz_clears(a,b,c,d,NULL);
    randstate_clear();    
    return 0;	    
}

