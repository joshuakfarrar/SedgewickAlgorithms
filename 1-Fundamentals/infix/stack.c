#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "node.h"

struct Stack * createStack() {
    return malloc(sizeof(struct Stack));
}

void push(struct Stack * stack, char value) {
    struct Node *item = createNode();
    item->value = value;

    item->next = stack->first;
    stack->first = item;

    stack->size++;

    return;
}

char peek(struct Stack * stack) {
    if (stack->size == 0) {
        printf("stack is empty\n");
    }

    char ch = stack->first->value;

    return ch;
}

char pop(struct Stack * stack) {
    if (stack->size == 0) {
        printf("stack is empty\n");
    }

    struct Node *item = stack->first;
    char ch = item->value;

    stack->first = item->next;

    destroyNode(item);

    stack->size--;

    return ch;
}
