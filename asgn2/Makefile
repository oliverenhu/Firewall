CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm

	 

mathlib-test: mathlib-test.o e.o newton.o madhava.o
	$(CC) -o mathlib-test mathlib-test.o e.o newton.o madhava.o $(LFLAGS)

mathlib-test.o: mathlib-test.c mathlib.h
	$(CC) $(CFLAGS) -c mathlib-test.c

madhava.o: madhava.c
	$(CC) $(CFLAGS) -c madhava.c

e.o: e.c
	$(CC) $(CFLAGS) -c e.c

newton.o: newton.c
	$(CC) $(CFLAGS) -c newton.c	
	
clean:
	rm -f mathlib-test mathlib-test.o

format:
	clang-format -i -style=file *.[ch]

