#include "pq.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
struct PriorityQueue {
    uint32_t capacity;
    uint32_t top;
    Node **items;
};
PriorityQueue *pq_create(uint32_t capacity) {
    PriorityQueue *q = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    if (q) {
        q->top = 0;
        q->capacity = capacity;
        q->items = (Node **) calloc(capacity, sizeof(Node));
        if (!q->items) {
            free(q);
            q = NULL;
        }
    }
    return q;
}
void pq_delete(PriorityQueue **q) {
    if (*q && (*q)->items) {
        free((*q)->items);
        free(*q);
        *q = NULL;
    }
    return;
}

bool pq_empty(PriorityQueue *q) {
    return q->top == 0;
}
bool pq_full(PriorityQueue *q) {
    return (pq_size(q) == q->capacity);
}

uint32_t pq_size(PriorityQueue *q) {
    return q->top;
}

void node_swap(Node *x, Node *y) {
    Node swap = *x;
    *x = *y;
    *y = swap;
}
void queue_sort(Node **items, uint32_t n) {
    for (uint32_t i = 1; i < n; i += 1) {
        uint32_t j = i;
        Node *temp = items[i];
        while ((j > 0) && items[j - 1]->frequency > temp->frequency) {

            items[j] = items[j - 1];
            j -= 1;
        }

        items[j] = temp;
    }
}
bool enqueue(PriorityQueue *q, Node *n) {
    if (!pq_full(q)) {
        q->items[q->top] = n;
        q->top += 1;
        queue_sort(q->items, pq_size(q));
        return true;
    }
    return false;
}
bool dequeue(PriorityQueue *q, Node **n) {
    if (!pq_empty(q)) {
        q->top -= 1;
        *n = q->items[0];
        for (uint32_t i = 0; i < q->top; i += 1) {
            q->items[i] = q->items[i + 1];
        }
        return true;
    }
    return false;
}

void pq_print(PriorityQueue *q) {
    for (uint32_t i = 0; i < pq_size(q); i += 1) {
        node_print(q->items[i]);
    }
}
