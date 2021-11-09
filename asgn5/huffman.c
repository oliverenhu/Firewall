#include "huffman.h"
#include "pq.h"
#include <stdio.h>
#include "io.h"
#include <unistd.h>
#include <stdint.h>
#include "stack.h"
static uint32_t leaves = 0;
Node *build_tree(uint64_t hist[static ALPHABET]) {
    PriorityQueue *q = pq_create(ALPHABET);
    for (int symbol = 0; symbol < ALPHABET; symbol += 1) {
        if (hist[symbol] > 0) {
            Node *n = node_create(symbol, hist[symbol]);
            enqueue(q, n);
            leaves += 1;
        }
    }
    while (pq_size(q) > 1) {
        Node *left = NULL;
        Node *right = NULL;
        dequeue(q, &left);
        dequeue(q, &right);
        Node *parent = node_join(left, right);
        enqueue(q, parent);
    }
    Node *root = NULL;
    dequeue(q, &root);

    return root;
}
Code C;
void build_codes(Node *root, Code table[static ALPHABET]) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            table[root->symbol] = C;
        } else {
            code_push_bit(&C, 0);
            build_codes(root->left, table);
            uint8_t lbit;
            code_pop_bit(&C, &lbit);
            code_push_bit(&C, 1);
            build_codes(root->right, table);
            uint8_t rbit;
            code_pop_bit(&C, &rbit);
        }
    }
}

void dump_tree(int outfile, Node *root) {
    uint8_t L = 76;
    uint8_t I = 73;

    if (root != NULL) {
        dump_tree(outfile, root->left);
        dump_tree(outfile, root->right);
        if (root->left == NULL && root->right == NULL) {

            write(outfile, &L, 1);
            //	printf("L");

            write(outfile, &root->symbol, 1);
            //	printf("%c",root->symbol);

        }

        else {
            write(outfile, &I, 1);
            //  printf("I");
        }
    }
}

Node *rebuild_tree(uint16_t nbytes, uint8_t tree[static nbytes]) {
    Stack *s = stack_create(nbytes);
    for (int i = 0; i < nbytes; i += 1) {
        if (tree[i] == 73) {
            Node *n = node_create(tree[i + 1], 0);
            stack_push(s, n);
        }
        if (tree[i] == 76) {
            Node *left;
            Node *right;
            stack_pop(s, &right);
            stack_pop(s, &left);
            Node *parent = node_join(left, right);
            stack_push(s, parent);
        }
    }
    Node *root;
    stack_pop(s, &root);
    return root;
}
//void delete_tree(Node **root);
