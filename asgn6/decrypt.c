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

    char *priv = "rsa.priv";
    FILE *infile = stdin;
    FILE *outfile = stdout;
    FILE *privkey = stdin;
    bool verbose = false;
    int opt = 0;
    while ((opt = getopt(argc, argv, "i:o:n:vh")) != -1) { //decrypt commands
        switch (opt) {
        case 'i': infile = fopen(optarg, "r"); break; //opens infile for reading
        case 'o': outfile = fopen(optarg, "w+"); break; //opens outfile for reading and writing
        case 'n': priv = optarg; break; //sets name of privkey file
        case 'v': verbose = true; break; //sets print varaible state to true
        case 'h': //prints helpful message
            printf(
                "SYNOPSIS\n   Decrypts data using RSA decryption.\n   Encrypted data is encrypted "
                "by the encrypt program.\n\nUSAGE\n   ./decrypt [-hv] [-i infile] [-o outfile] -n "
                "privkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v     "
                "         Display verbose program output.\n   -i infile       Input file of data "
                "to decrypt (default: stdin).\n   -o outfile      Output file for decrypted data "
                "(default: stdout).\n   -n pvfile       Private key file (default: rsa.priv).\n");
            return 0;
        }
    }

    mpz_t n, d;
    mpz_inits(n, d, NULL);
    privkey = fopen(priv, "r"); //opens privkey file for reading
    if (privkey == NULL) { //prints help message if privkey fails to open
        printf("SYNOPSIS\n   Decrypts data using RSA decryption.\n   Encrypted data is encrypted "
               "by the encrypt program.\n\nUSAGE\n   ./decrypt [-hv] [-i infile] [-o outfile] -n "
               "privkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v      "
               "        Display verbose program output.\n   -i infile       Input file of data to "
               "decrypt (default: stdin).\n   -o outfile      Output file for decrypted data "
               "(default: stdout).\n   -n pvfile       Private key file (default: rsa.priv).\n");
        return 0;
    }
    if (infile == NULL) { //prints help message if infile fails to open
        printf("SYNOPSIS\n   Decrypts data using RSA decryption.\n   Encrypted data is encrypted "
               "by the encrypt program.\n\nUSAGE\n   ./decrypt [-hv] [-i infile] [-o outfile] -n "
               "privkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v      "
               "        Display verbose program output.\n   -i infile       Input file of data to "
               "decrypt (default: stdin).\n   -o outfile      Output file for decrypted data "
               "(default: stdout).\n   -n pvfile       Private key file (default: rsa.priv).\n");
        return 0;
    }
    if (outfile == NULL) { //prints help message if outfiel fails to open
        printf("SYNOPSIS\n   Decrypts data using RSA decryption.\n   Encrypted data is encrypted "
               "by the encrypt program.\n\nUSAGE\n   ./decrypt [-hv] [-i infile] [-o outfile] -n "
               "privkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v      "
               "        Display verbose program output.\n   -i infile       Input file of data to "
               "decrypt (default: stdin).\n   -o outfile      Output file for decrypted data "
               "(default: stdout).\n   -n pvfile       Private key file (default: rsa.priv).\n");
        return 0;
    }
    rsa_read_priv(n, d, privkey); //passes in n and d from privkey file

    if (verbose) { //prints out stats of variables

        gmp_printf("n (%zu bits) = %Zd\ne (%zu bits) = %Zd\n", mpz_sizeinbase(n, 2), n,
            mpz_sizeinbase(d, 2), d);
    }

    rsa_decrypt_file(infile, outfile, n, d); //prints out decrypted message to outfile
    //clears mpz and closes files
    mpz_clears(n, d, NULL);
    fclose(infile);
    fclose(outfile);
    fclose(privkey);
    return 0;
}
