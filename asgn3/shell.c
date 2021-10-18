#include "insert.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
uint32_t gaps(uint32_t n) {
    static uint32_t iter_val = 0;
    if (iter_val <= 0) {
        iter_val = (uint32_t)(log(3 + 2 * n) / log(3));
    } else {
        iter_val -= 1;
    }
    return (uint32_t) floor(pow(3, iter_val) - 1) / 2;
}
void shell_sort(Stats *stats, uint32_t *A, uint32_t n) {
    uint32_t iteration = (uint32_t)(log(3 + 2 * n) / log(3));
    for (uint32_t i = 0; i < iteration; i += 1) {
        uint32_t gap = gaps(n);

        for (uint32_t j = gap; j < n; j += 1) {
            uint32_t h = j;
            uint32_t temp = move(stats, A[j]);

            while ((h >= gap) && cmp(stats, temp, A[h - gap]) == -1) {
                A[h] = move(stats, A[h - gap]);
                h -= gap;
            }
            A[h] = move(stats, temp);
        }
    }
}
