#include <stdlib.h>
#include "node.h"

struct Node * next(struct Node *node) {
    return node->to;
}

struct Node * createNode() {
    return malloc(sizeof(struct Node));
}
