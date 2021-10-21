#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE *infile =stdin;
	FILE *outfile =stdout;

	int opt = 0;
	while ((opt = getopt(argc, argv, "i:o:")) != -1) {
		switch (opt) {
	       	case 'i':
			printf("%s input file\n", optarg);
	       		infile = fopen(optarf, "r");
			break;
		case 'o':
			printf("%s output file\n", optarg);
			outfile = fopen(optarg, "w");
			break;
		}
	}
	
	char buf[1024];
	fgets(buf , 1024 , infile);
	buf[strlen(buf) -1] = '\0';
	fputs(buf, outfile);
	
	return 0;
}	
