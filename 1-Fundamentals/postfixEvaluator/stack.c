#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "node.h"

struct Stack * createStack() {
    return malloc(sizeof(struct Stack));
}

void push(struct Stack * stack, int value) {
    struct Node *item = createNode();
    item->value = value;

    item->next = stack->first;
    stack->first = item;

    stack->size++;

    return;
}

int pop(struct Stack * stack) {
    if (stack->size == 0) {
        printf("That stack is empty!\n");
        exit(1);
    }

    struct Node *item = stack->first;
    int value = item->value;

    stack->first = item->next;
    destroyNode(item);

    stack->size--;

    return value;
}

void destroyStack(struct Stack * stack) {
    // destroy all nodes in the stack
    while (stack->size > 0) {
      pop(stack);
    }

    // then destroy the stack
    free(stack);
    return;
}
