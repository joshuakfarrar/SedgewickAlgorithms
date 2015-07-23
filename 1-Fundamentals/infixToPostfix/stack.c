#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "node.h"

struct Stack * createStack() {
    return malloc(sizeof(struct Stack));
}

void push(struct Stack * stack, char * value) {
    struct Node *item = createNode();
    item->value = strdup(value);

    item->next = stack->first;
    stack->first = item;

    return;
}

char * pop(struct Stack * stack) {
    struct Node *item = stack->first;
    char * value = strdup(item->value);
    stack->first = stack->first->next;
    destroyNode(item);
    return value;
}
