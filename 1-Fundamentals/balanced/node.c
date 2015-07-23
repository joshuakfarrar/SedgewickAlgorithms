#include <stdlib.h>
#include "node.h"

struct Node * createNode() {
    return malloc(sizeof(struct Node));
}

void destroyNode(struct Node *node) {
    free(node);
    return;
}
