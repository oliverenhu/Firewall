CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm
all: banhammer
banhammer: banhammer.o bst.o node.o bf.o ht.o bv.o speck.o parser.o 
	$(CC) -o banhammer banhammer.o bst.o node.o ht.o bf.o bv.o speck.o parser.o $(LFLAGS)

banhammer.o: banhammer.c bst.h node.h bf.h bv.h ht.h salts.h parser.h speck.h messages.h
	$(CC) $(CFLAG) -c banhammer.c

ht.o: ht.c ht.h salts.h speck.h
	$(CC) $(CFLAG) -c ht.c

bst.o: bst.c bst.h node.h
	$(CC) $(CFLAG) -c bst.c

node.o: node.c node.h
	$(CC) $(CFLAG) -c node.c

bf.o: bf.c bf.h bv.h salts.h speck.h
	$(CC) $(CFLAG) -c bf.c

bv.o: bv.c bv.h
	$(CC) $(CFLAGS) -c bv.c

speck.o: speck.c speck.h
	$(CC) $(CFLAGS) -c speck.c

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

format:
	clang-format -i -style=file *.[ch]
clean:
	rm -f banhammer *.o


