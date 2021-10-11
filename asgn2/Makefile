CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm

	 

mathlib-test: mathlib-test.o e.o newton.o madhava.o euler.o bbp.o viete.o
	$(CC) -o mathlib-test mathlib-test.o e.o newton.o madhava.o euler.o bbp.o viete.o $(LFLAGS)

mathlib-test.o: mathlib-test.c mathlib.h
	$(CC) $(CFLAGS) -c mathlib-test.c

euler.o: euler.c
	$(CC) $(CFLAGS) -c euler.c

madhava.o: madhava.c
	$(CC) $(CFLAGS) -c madhava.c

bbp.o: bbp.c
	$(CC) $(CFLAGS) -c bbp.c
viete.o: viete.c
	$(CC) $(CFLAGS) -c viete.c
e.o: e.c
	$(CC) $(CFLAGS) -c e.c

newton.o: newton.c
	$(CC) $(CFLAGS) -c newton.c	
	
clean:
	rm -f mathlib-test mathlib-test.o

format:
	clang-format -i -style=file *.[ch]
all: mathlib-test.o e.o newton.o madhava.o euler.o bbp.o viete.o
