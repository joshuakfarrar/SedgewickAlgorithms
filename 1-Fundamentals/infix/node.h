#ifndef NODE_H
#define NODE_H

struct Node {
    struct Node * next;
    char value;
};

struct Node * createNode();
void destroyNode(struct Node * node);

#endif
