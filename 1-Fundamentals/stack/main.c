#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[]) {
    struct Stack *stack = createStack();
    push(stack, "world");
    push(stack, "hello");

    char *a = pop(stack);
    char *b = pop(stack);

    printf("%s %s\n", a, b);

    return 0;
}
