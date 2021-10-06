CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm

all: math-test	 

math-test: math-test.o e.o
	$(CC) -o math-test math-test.o $(LFLAGS)

math-test.o: math-test.c mathlib.h
	$(CC) $(CFLAGS) -c math-test.c
e.0: e.c
	$(CC) $(CFLAGS) -c e.c

clean:
	rm -f math-test math-test.o

format:
	clang-format -i -style=file *.[ch]

