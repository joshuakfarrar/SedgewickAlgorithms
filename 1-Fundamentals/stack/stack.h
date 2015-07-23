#ifndef STACK_H
#define STACK_H

struct Stack {
    struct Node *first;
};

struct Stack *createStack();
void push(struct Stack *stack, char *message);
char *pop(struct Stack *stack);

#endif
