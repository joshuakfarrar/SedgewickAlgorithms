#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "node.h"

struct Stack * createStack() {
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->size = 0;
    return stack;
}

void push(struct Stack *stack, const char ch) {
    struct Node *new = createNode();
    new->value = ch;

    new->next = stack->first;
    stack->first = new;

    stack->size++;
    return;
}

char pop(struct Stack *stack) {
    struct Node *item = stack->first;
    char ch = item->value;
    stack->first = stack->first->next;
    destroyNode(item);
    stack->size--;
    return ch;
}

