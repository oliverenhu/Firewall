CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm


tsp.o: tsp.c
       $(CC) $(CFLAGS) -c tsp.c

clean:
	rm -f tsp *.o

format:
	clang-format -i -style=file *.[ch]


