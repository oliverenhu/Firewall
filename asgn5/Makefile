CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm

	 

encode: encode.o node.o pq.o stack.o code.o io.o huffman.o
	$(CC) -o encode encode.o node.o pq.o stack.o code.o io.o huffman.o $(LFLAGS)

encode.o: encode.c header.h node.h pq.h stack.h code.h io.h huffman.h
	$(CC) $(CFLAGS) -c encode.c

node.o: node.c node.h 
	$(CC) $(CFLAGS) -c node.c

pq.o: pq.c pq.h node.h
	$(CC) $(CFLAGS) -c pq.c

stack.o: stack.c stack.h node.h
	$(CC) $(CFLAGS) -c stack.c

code.o: code.c code.h 
	$(CC) $(CFLAGS) -c code.c
io.o: io.c io.h code.h 
	$(CC) $(CFLAGS) -c io.c
huffman.o: huffman.c huffman.h pq.h
	$(CC) $(CFLAGS) -c huffman.c

clean:
	rm -f sorting *.o

format:
	clang-format -i -style=file *.[ch]

all: encode

