CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm

tsp: tsp.o graph.o
	$(CC) -o tsp tsp.o graph.o $(LFALGS)

tsp.o: tsp.c graph.h stack.h vertices.h path.h
	$(CC) $(CFLAGS) -c tsp.c

graph.o: graph.c graph.h vertices.h
	$(CC) $(CFLAGS) -c graph.c

clean:
	rm -f tsp *.o

format:
	clang-format -i -style=file *.[ch]


