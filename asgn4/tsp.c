#include "graph.h"
#include "path.h"
#include "stack.h"
#include "vertices.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void out(FILE *outfile, int size, Path *shortest, char *cities[]);
void dfs(Graph *graph, uint32_t v, Path *p, FILE *outfile, Path *shortest, char *cities[]);
bool verbose = false;
int recursive = 1;
int main(int argc, char **argv) {
    FILE *infile = stdin;
    FILE *outfile = stdout;
    int size = 0;
    int opt = 0;
    bool undirected = false;
    while ((opt = getopt(argc, argv, "i:o:uvh")) != -1) {
        switch (opt) {
        case 'i': infile = fopen(optarg, "r"); break;
        case 'o': outfile = fopen(optarg, "w"); break;
        case 'u': undirected = true; break;
        case 'v': verbose = true; break;
        case 'h':
            printf("SYNOPSIS\n  Traveling Salesman Problem using DFS.\n\nUSAGE\n  ./tsp [-u] [-v] "
                   "[-h] [-i infile] [-o outfile]\n\nOPTIONS\n  -u             Use undirected "
                   "graph.\n  -v             Enable verbose printing.\n  -h             Program "
                   "usage and help.\n  -i infile      Input containing graph (default: stdin)\n  "
                   "-o outfile     Output of computed path (default: stdout)\n");
            return 0;
        }
    }

    char buf[1024];
    fgets(buf, 1024, infile);

    buf[strlen(buf)] = '\0';
    size = atoi(buf);
    char *cities[size];
    for (int i = 0; i < size; i += 1) {
        fgets(buf, 1024, infile);
        buf[strlen(buf) - 1] = '\0';
        cities[i] = strdup(buf);
    }
    struct Graph *graph = graph_create(size, undirected);
    while (fgets(buf, 1024, infile) != NULL) {
        char *i = strtok(buf, " ");
        char *j = strtok(NULL, " ");
        char *w = strtok(NULL, " ");
        graph_add_edge(graph, atoi(i), atoi(j), atoi(w));
    }

    struct Path *p = path_create();
    struct Path *shortest = path_create();

    dfs(graph, 0, p, outfile, shortest, cities);
    out(outfile, size, shortest, cities);
    for (int i = 0; i < size; i += 1) {
        free(cities[i]);
    }
    graph_delete(&graph);
    path_delete(&p);
    path_delete(&shortest);
    return 0;
}

void dfs(Graph *graph, uint32_t v, Path *p, FILE *outfile, Path *shortest, char *cities[]) {
    graph_mark_visited(graph, v);
    for (uint32_t visit = 1; visit < graph_vertices(graph); visit += 1) {
        if (!graph_visited(graph, visit) && (graph_has_edge(graph, v, visit))) {

            path_push_vertex(p, visit, graph);
            dfs(graph, visit, p, outfile, shortest, cities);
            recursive += 1;
        }
    }
    if (graph_has_edge(graph, v, 0) && path_vertices(p) + 1 == graph_vertices(graph)) {

        path_push_vertex(p, 0, graph);
        if (path_length(shortest) == 0 || (path_length(shortest)) > (path_length(p))) {
            path_copy(shortest, p);
        }
        if (verbose) {
            printf("Path length: %d\n", path_length(p));
            printf("Path: %s -> ", cities[0]);
            path_print(p, outfile, cities);
        }
        uint32_t zero = 0;
        path_pop_vertex(p, &zero, graph);
    }
    graph_mark_unvisited(graph, v);
    path_pop_vertex(p, &v, graph);
}
void out(FILE *outfile, int size, Path *shortest, char *cities[]) {
    if (size != 1) {
        printf("Path length: %d\n", path_length(shortest));
        printf("Path: %s -> ", cities[0]);
        path_print(shortest, outfile, cities);
        printf("Total recursive calls: %d\n", recursive);
    } else {
        printf("There's nowhere to go.\n");
    }
}
