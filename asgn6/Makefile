CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra $(shell pkg-config --cflags gmp)
LFLAGS = $(shell pkg-config --libs gmp)


keygen: keygen.o randstate.o numtheory.o rsa.o
	$(CC) -o keygen keygen.o randstate.o numtheory.o rsa.o $(LFLAGS)
keygen.o: keygen.c randstate.h numtheory.h rsa.h
	$(CC) $(CFLAGS) -c keygen.c
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

all: keygen
