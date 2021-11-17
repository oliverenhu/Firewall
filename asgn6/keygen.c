#include "numtheory.h"
#include "randstate.h"
#include "rsa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/stat.h>


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

    }

