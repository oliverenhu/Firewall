#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OPTIONS "aeisqr:n:p:h:"
typedef enum {
    HEAP,
    SHELL,
    INSERTION,
    QUICK
} Sorts; // enumerates the 4 sorts so they can be iterated through
const char *names[] = { "Heap Sort", "Shell Sort", "Insertion Sort",
    "Quick Sort" }; // names array for printing out the sorts
void set_sort(Sorts i, Stats *stats, uint32_t *A, uint32_t size,
    uint32_t elements); // declare the set_sort helper function

int main(int argc, char **argv) {
    int p = 0; // variable that helps track whether the -p argument is greater than size
    int opt = 0; // set equal to -<arguments>
    uint64_t seed = 13371453; // default seed
    uint32_t size = 100; // default size
    uint32_t elements = 100; // default printed elements
    uint64_t mask = 0x3FFFFFFF; // bit masked to 30 bits
    Set command = empty_set(); // set tracks the commands

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {

        switch (opt) {
        case 'a': // case a inserts all sorts into command
            command = insert_set(HEAP, command);
            command = insert_set(INSERTION, command);
            command = insert_set(SHELL, command);
            command = insert_set(QUICK, command);
            break;

        case 'e': command = insert_set(HEAP, command); break; // insert HEAP into command

        case 'i': command = insert_set(INSERTION, command); break; // insert INSERTION into command

        case 's': command = insert_set(SHELL, command); break; // insert SHELL into command

        case 'q': command = insert_set(QUICK, command); break; // insert QUICK into command

        case 'r': seed = atoi(optarg); break; // sets seed

        case 'n': // sets array size
            if (atoi(optarg) >= 0) {
                size = atoi(optarg);
            }
            break;

        case 'p': // sets printed elements
            if (atoi(optarg) <= 100) {
                elements = atoi(optarg);
            }

            p = 1;
            break;
        }
    }

    if ((p != 1 && size <= 100)
        || elements > size) { // ensures that elements ==size  if  elements is greater than size
        elements = size;
    }
    uint32_t *A = (uint32_t *) calloc(
        size, sizeof(uint32_t)); // initialize A* array pointer and assigs it memory
    Stats *stats = malloc(sizeof(stats)); // initialize Stats stats pointer and allocates memory

    for (Sorts i = HEAP; i < QUICK + 1;
         i += 1) { // interates through Sorts and check i s they are a member of command set
        if (member_set(i, command)) {
            srandom(seed); // creats a seed for random()
            for (
                uint32_t x = 0; x < size;
                x
                += 1) { // interates through size to create an array that is bitmasked usinging random()

                A[x] = mask & random();
            }

            set_sort(i, stats, A, size,
                elements); // set_sort will print out the array along with stats associated with
        }
    }
    free(A); // frees up the memory allocated
    free(stats);

    return 0;
}

void set_sort(Sorts i, Stats *stats, uint32_t *A, uint32_t size,
    uint32_t
        elements) { //takes in the i value of Sorts and uses the corresponding sorting algorithm

    if (i == 0) {
        heap_sort(stats, A, size);
    }
    if (i == 1) {
        shell_sort(stats, A, size);
    }
    if (i == 2) {
        insertion_sort(stats, A, size);
    }
    if (i == 3) {
        quick_sort(stats, A, size);
    }

    printf("%s, %d elements, %lu moves, %lu compares\n", names[i], size,
        stats->moves, //prints out the name size moves and compares from stats
        stats->compares);

    reset(stats); //resets the moves and compars for the next sort
    for (uint32_t x = 0; x < elements; x += 1) { //formats the array sorted correctly
        if (((x + 1) % 5 == 0 && x != 0) || x == elements - 1) {
            printf("%13" PRIu32 "\n", A[x]);
        } else {
            printf("%13" PRIu32, A[x]);
        }
    }
}
