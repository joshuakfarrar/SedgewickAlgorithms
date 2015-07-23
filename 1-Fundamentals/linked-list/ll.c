#include <stdio.h>
#include "node.h"

int main(int argc, char *argv[]) {
    // initialize nodes
    struct Node *nodeA = createNode();
    nodeA->value = "first";

    struct Node *nodeB = createNode();
    nodeB->value = "second";

    // point a to b
    nodeA->to = nodeB;

    // what is the value of the node pointed to by nodeA?
    printf("%s\n", next(nodeA)->value);

    return 0;
}
