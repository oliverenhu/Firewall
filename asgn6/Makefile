CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra $(shell pkg-config --cflags gmp)
LFLAGS = $(shell pkg-config --libs gmp)

make:keygen encrypt decrypt
keygen: keygen.o randstate.o numtheory.o rsa.o
	$(CC) -o keygen keygen.o randstate.o numtheory.o rsa.o $(LFLAGS)

keygen.o: keygen.c randstate.h numtheory.h rsa.h
	$(CC) $(CFLAGS) -c keygen.c

encrypt: encrypt.o randstate.o numtheory.o rsa.o
	$(CC) -o encrypt encrypt.o randstate.o numtheory.o rsa.o $(LFLAGS)

encrypt.o: encrypt.c randstate.h numtheory.h rsa.h
	$(CC) $(CFLAGS) -c encrypt.c

decrypt: decrypt.o randstate.o numtheory.o rsa.o
	$(CC) -o decrypt decrypt.o randstate.o numtheory.o rsa.o $(LFLAGS)

decrypt.o: decrypt.c randstate.h numtheory.h rsa.h
	$(CC) $(CFLAGS) -c decrypt.c

randstate.o: randstate.c randstate.h 
	$(CC) $(CFLAGS) -c randstate.c

numtheory.o: numtheory.c numtheory.h randstate.h
	$(CC) $(CFLAGS) -c numtheory.c
rsa.o: rsa.c rsa.h numtheory.h randstate.h
	$(CC) $(CFLAGS) -c rsa.c

format:
	clang-format -i -style=file *.[ch]
clean:
	rm -f keygen *.o

all: keygen encrypt decrypt
