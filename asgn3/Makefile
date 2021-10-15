CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm

	 

sorting: sorting.o 
	$(CC) -o sorting sorting.o

sorting.o: sorting.c set.h heap.h insert.h quick.h shell.h
	$(CC) $(CFLAGS) -c sorting.c

clean:
	rm -f sorting *.o

format:
	clang-format -i -style=file *.[ch]
all: sorting

