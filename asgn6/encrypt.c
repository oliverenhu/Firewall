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
    char *pub = "rsa.pub";
    FILE *infile = stdin;
    FILE *outfile = stdout;
    FILE *pubkey = stdin;
    bool verbose = false;
    int opt = 0;
    while ((opt = getopt(argc, argv, "i:o:n:vh")) != -1) { //commands for encryption
        switch (opt) {
        case 'i': infile = fopen(optarg, "r"); break; //opens specified infile for reading
        case 'o':
            outfile = fopen(optarg, "w+");
            break; //opens specified outfile for reading and writing
        case 'n': pub = optarg; break; //sets name of pubfile
        case 'v': verbose = true; break; //sets print stats to true
        case 'h': //prints helpful message
            printf(
                "SYNOPSIS\n   Encrypts data using RSA encryption.\n   Encrypted data is decrypted "
                "by the decrypt program.\n\nUSAGE\n   ./encrypt [-hv] [-i infile] [-o outfile] -n "
                "pubkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v      "
                "        Display verbose program output.\n   -i infile       Input file of data to "
                "encrypt (default: stdin).\n   -o outfile      Output file for encrypted data "
                "(default: stdout).\n   -n pbfile       Public key file (default: rsa.pub).\n");
            return 0;
        }
    }

    mpz_t usr, s, n, e;
    mpz_inits(usr, s, n, e, NULL);

    pubkey = fopen(pub, "r"); //opens pubfile and reads
    if (pubkey == NULL) { //prints helpful message if opening pubfile fails
        printf("SYNOPSIS\n   Encrypts data using RSA encryption.\n   Encrypted data is decrypted "
               "by the decrypt program.\n\nUSAGE\n   ./encrypt [-hv] [-i infile] [-o outfile] -n "
               "pubkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v       "
               "       Display verbose program output.\n   -i infile       Input file of data to "
               "encrypt (default: stdin).\n   -o outfile      Output file for encrypted data "
               "(default: stdout).\n   -n pbfile       Public key file (default: rsa.pub).\n");

        return 0;
    }
    if (infile == NULL) { //prints helpful message if opening infile fails
        printf("SYNOPSIS\n   Encrypts data using RSA encryption.\n   Encrypted data is decrypted "
               "by the decrypt program.\n\nUSAGE\n   ./encrypt [-hv] [-i infile] [-o outfile] -n "
               "pubkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v       "
               "       Display verbose program output.\n   -i infile       Input file of data to "
               "encrypt (default: stdin).\n   -o outfile      Output file for encrypted data "
               "(default: stdout).\n   -n pbfile       Public key file (default: rsa.pub).\n");
        return 0;
    }
    if (outfile == NULL) { //prints helpful message if opening outfile fails
        printf("SYNOPSIS\n   Encrypts data using RSA encryption.\n   Encrypted data is decrypted "
               "by the decrypt program.\n\nUSAGE\n   ./encrypt [-hv] [-i infile] [-o outfile] -n "
               "pubkey\n\nOPTIONS\n   -h              Display program help and usage.\n   -v       "
               "       Display verbose program output.\n   -i infile       Input file of data to "
               "encrypt (default: stdin).\n   -o outfile      Output file for encrypted data "
               "(default: stdout).\n   -n pbfile       Public key file (default: rsa.pub).\n");
        return 0;
    }

    rsa_read_pub(n, e, s, username, pubkey); //reads pubkey file and stores values n,e,s,username
    if (verbose) { //prints out states of variables with username

        gmp_printf("user = %s\ns (%zu bits) = %Zd\nn (%zu bits) = %Zd\ne (%zu bits) = %Zd\n",
            username, mpz_sizeinbase(s, 2), s, mpz_sizeinbase(n, 2), n, mpz_sizeinbase(e, 2), e);
    }

    mpz_set_str(usr, username, 62); //sets username to usr mpz
    if (!rsa_verify(usr, s, e, n)) { //determines if user has permission to open file
        printf("No permission\n");
        return 0;
    }
    rsa_encrypt_file(infile, outfile, n, e); //encrypts file into hexstring
    //clears mpz,closes file
    mpz_clears(usr, s, e, n, NULL);
    fclose(infile);
    fclose(outfile);
    fclose(pubkey);
    return 0;
}
