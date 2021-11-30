CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm

bv.o: bv.c
	$(CC) $(CFLAGS) -c bv.c

format:
	clang-format -i -style=file *.[ch]
clean:
	rm -f banhammer *.o


