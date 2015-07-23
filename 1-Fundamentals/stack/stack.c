#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "node.h"

struct Stack * createStack() {
    return malloc(sizeof(struct Stack));
}

void push(struct Stack *stack, char *message) {
    struct Node *new = createNode();
    new->value = message;

    new->next = stack->first;
    stack->first = new;

    return;
}

char * pop(struct Stack *stack) {
    struct Node *item = stack->first;
    char *buffer = strdup(item->value);
    stack->first = stack->first->next;
    destroyNode(item);
    return buffer;
}

