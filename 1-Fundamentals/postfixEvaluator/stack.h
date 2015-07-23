#ifndef STACK_H
#define STACK_H

struct Stack {
    struct Node * first;
    int size;
};

struct Stack * createStack();
void push(struct Stack * stack, int value);
int pop(struct Stack * stack);
void destroyStack(struct Stack * stack);

#endif
