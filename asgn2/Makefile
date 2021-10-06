CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: pig

pig: pig.o
	$(CC) -o math-test math-test.o

pig.o: pig.c names.h
	$(CC) $(CFLAGS) -c math-test.c

clean:
	rm -f math-test math-test.o

format:
	clang-format -i -style=file *.[ch]

