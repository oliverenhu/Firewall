#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Node *node_create(char *oldspeak, char *newspeak) {
    Node *n = (Node *) malloc(sizeof(Node));
    if (n) {

        if (oldspeak) {
            n->oldspeak = strdup(oldspeak);
        } else {
            n->oldspeak = NULL;
        }
        if (newspeak) {

            n->newspeak = strdup(newspeak);
        } else {
            n->newspeak = NULL;
        }
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}
void node_delete(Node **n) {
    if (*n) {

        if ((*n)->oldspeak) {
            free((*n)->oldspeak);
            (*n)->oldspeak = NULL;
        }

        if ((*n)->newspeak) {

            free((*n)->newspeak);
            (*n)->newspeak = NULL;
        }

        free(*n);

        *n = NULL;
    }
    return;
}
void node_print(Node *n) {
    if (n->newspeak == NULL && n->oldspeak) {
        printf("%s\n", n->oldspeak);

    } else if (n->newspeak && n->oldspeak) {
        printf("%s -> %s\n", n->oldspeak, n->newspeak);
    }
}
