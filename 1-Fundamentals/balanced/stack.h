#ifndef STACK_H
#define STACK_H

struct Stack {
    struct Node *first;
    int size;
};

struct Stack *createStack();
void push(struct Stack *stack, const char ch);
char pop(struct Stack *stack);

#endif
