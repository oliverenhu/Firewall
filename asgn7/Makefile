CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm
bst.o: bst.c bst.h node.h
	$(CC) $(CFLAG) -c bst.c

node.o: node.c node.h
	$(CC) $(CFLAG) -c node.c

bf.o: bf.c bf.h bv.h salts.h speck.h
	$(CC) $(CFLAG) -c bf.c

bv.o: bv.c bv.h
	$(CC) $(CFLAGS) -c bv.c

format:
	clang-format -i -style=file *.[ch]
clean:
	rm -f banhammer *.o


