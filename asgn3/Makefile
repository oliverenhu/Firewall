CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm

	 

sorting: sorting.o insert.o stats.o shell.o heap.o quick.o
	$(CC) -o sorting sorting.o insert.o stats.o shell.o heap.o quick.o $(LFLAGS)

sorting.o: sorting.c set.h heap.h insert.h quick.h shell.h
	$(CC) $(CFLAGS) -c sorting.c

insert.o: insert.c stats.h  
	$(CC) $(CFLAGS) -c insert.c

heap.o: heap.c stats.h
	$(CC) $(CFLAGS) -c heap.c

shell.o: shell.c stats.h
	$(CC) $(CFLAGS) -c shell.c


stats.o: stats.c stats.h
	$(CC) $(CFLAGS) -c stats.c

quick.o: quick.c stats.h
	$(CC) $(CFLAGS) -c quick.c

test: test.o 
	$(CC) -o test test.o 

test.o: test.c set.h heap.h insert.h quick.h shell.h
	$(CC) $(CFLAGS) -c test.c

clean:
	rm -f sorting *.o

format:
	clang-format -i -style=file *.[ch]
all: sorting

