#ifndef NODE_H
#define NODE_H

struct Node {
    struct Node *to;
    char *value;
};

struct Node * next(struct Node *node); 
struct Node * createNode();

#endif
