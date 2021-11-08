#include "huffman.h"
#include "pq.h"
#include <stdio.h>
#include "io.h"
#define L 76
#define I 73

static uint32_t leaves = 2;
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
uint32_t build_index = 0;
void dump_tree(int outfile, Node *root) {
    uint8_t build_buffer[3 * leaves - 1];

    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            build_buffer[build_index] = L;
            build_index += 1;
            build_buffer[build_index] = root->symbol;
            build_index += 1;
        }

        else {
            build_buffer[build_index] = I;
            dump_tree(outfile, root->left);
            build_index += 1;
           
	    build_buffer[build_index] = I;
            dump_tree(outfile, root->right);
            build_index += 1;
        }
    }
    if (build_index == 3 * leaves - 1) {
        write_bytes(outfile, build_buffer, 3 * leaves - 1);
    }
}
//Node *rebuild_tree(uint16_t nbytes, uint8_t tree[static nbytes]){

	
//}
//void delete_tree(Node **root);
