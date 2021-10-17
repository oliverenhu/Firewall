#include "insert.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int partition(Stats *stats, uint32_t *A, int lo, int hi) {
    int i = lo - 1;
    for (int j = lo; j < hi; j += 1) {
        if (cmp(stats, A[j - 1], A[hi - 1]) == -1) {
            i += 1;
            swap(stats, &A[i - 1], &A[j - 1]);
        }
    }
    swap(stats, &A[i], &A[hi - 1]);
    return i + 1;
}
void quick_sorter(Stats *stats, uint32_t *A, int lo, int hi) {
    if (lo < hi) {
        int p = partition(stats, A, lo, hi);
        quick_sorter(stats, A, lo, p - 1);
        quick_sorter(stats, A, p + 1, hi);
    }
}
void quick_sort(Stats *stats, uint32_t *A, uint32_t n) {
    quick_sorter(stats, A, 1, n);
}
