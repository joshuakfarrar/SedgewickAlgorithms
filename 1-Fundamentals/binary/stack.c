#include <stdlib.h>
#include "stack.h"
#include "node.h"

struct Stack * createStack() {
    return malloc(sizeof(struct Stack));
}

void destroyStack(struct Stack * stack) {
    free(stack);
    return;
}

void push(struct Stack * stack, int value) {
    struct Node *item = createNode();
    item->value = value;

    if (stack->first == NULL) {
       stack->first = item;
    } else {
       item->next = stack->first;
       stack->first = item;
    }

    stack->size++;

    return;
}

int pop(struct Stack * stack) {
    struct Node *item = stack->first;

    if (item == NULL) {
        return -1;
    }

    int i = item->value;

    stack->first = item->next;

    destroyNode(item);

    stack->size--;

    return i;
}
