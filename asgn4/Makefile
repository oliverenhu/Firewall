CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LFLAGS= -lm

tsp: tsp.o graph.o stack.o path.o
	$(CC) -o tsp tsp.o graph.o stack.o path.o $(LFALGS)

tsp.o: tsp.c graph.h stack.h vertices.h path.h
	$(CC) $(CFLAGS) -c tsp.c

graph.o: graph.c graph.h vertices.h
	$(CC) $(CFLAGS) -c graph.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

path.o: path.c path.h graph.h vertices.h stack.h
	$(CC) $(CFLAGS) -c path.c
clean:
	rm -f tsp *.o

format:
	clang-format -i -style=file *.[ch]


