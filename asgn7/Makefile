CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm
bf.o: bf.c
	$(CC) $(CFLAG) -c bf.c

bv.o: bv.c
	$(CC) $(CFLAGS) -c bv.c

format:
	clang-format -i -style=file *.[ch]
clean:
	rm -f banhammer *.o


