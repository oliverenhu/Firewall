CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm

	 

sorting: sorting.o 
	$(CC) -o sorting (LFLAGS)

sorting.o: sorting.c stat.h set.h heap.h insert.h quick.h shell.h
	$(CC) $(CFLAGS) -c sorting.c

clean:
	rm -f sorting *.o

format:
	clang-format -i -style=file *.[ch]
all: sorting

