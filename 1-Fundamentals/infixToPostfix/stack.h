#ifndef STACK_H
#define STACK_H

struct Stack {
    struct Node * first;
};

struct Stack * createStack();
void push(struct Stack * stack, char * value);
char * pop(struct Stack * stack);

#endif
