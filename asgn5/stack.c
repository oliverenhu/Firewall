#include "stack.h"
#include "node.h"
#include <stdlib.h>
#include <unistd.h>
struct Stack {
    uint32_t top; // Index of the next empty slot .
    uint32_t capacity; // Number of items that can be pushed .
    Node **items; // Array of items , each with type uint32_t .
};
Stack *stack_create(uint32_t capacity) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    if (s) {
        s->top = 0;
        s->capacity = capacity;
        s->items = (Node **) calloc(capacity, sizeof(Node));
        if (!s->items) {
            free(s);
            s = NULL;
        }
    }
    return s;
}

void stack_delete(Stack **s) {
    if (*s && (*s)->items) {
        free((*s)->items);
        free(*s);
        *s = NULL;
    }
    return;
}



bool stack_empty(Stack *s) {

    return s->top == 0;
}
uint32_t stack_size(Stack *s) {
    return s->top;
}

bool stack_full(Stack *s) {
    return (stack_size(s) == s->capacity);
}
bool stack_push(Stack *s, Node *n) {
    if (!stack_full(s)) {
        *s->items[s->top] = *n;
        s->top += 1;
        return true;
    }
    return false;
}
bool stack_pop(Stack *s, Node **n) {
    if (!stack_empty(s)) {
        s->top -= 1;
        **n = *s->items[s->top];
        return true;
    }
    return false;
}

void stack_print(Stack *s) {
    for (uint32_t i = 0; i < s->top; i += 1) { 
	node_print(s->items[i]);
}
}
