CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm

	 

sorting: sorting.o insert.o 
	$(CC) -o sorting sorting.o insert.o stats.o $(LFLAGS)

sorting.o: sorting.c set.h heap.h insert.h quick.h shell.h
	$(CC) $(CFLAGS) -c sorting.c

insert.o: insert.c 
	$(CC) $(CFLAGS) -c insert.c
stats.o: stats.c stats.h
	$(CC) $(CFLAGS) -c stats.o

clean:
	rm -f sorting *.o

format:
	clang-format -i -style=file *.[ch]
all: sorting

