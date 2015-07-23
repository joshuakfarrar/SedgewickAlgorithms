#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void printUsage(char * name);
void convertToBinary(char * arg);

int main(int argc, char * argv[]) {
    if (argc == 1) {
        printUsage(argv[0]);
        return 1;
    }

    int i;
    for (i = 1; i < argc; i++) {
        convertToBinary(argv[i]);
    }

    return 0;
}

void printUsage(char * name) {
    printf("Usage: %s [int]\n", name);
    return;
}

void convertToBinary(char * arg) {
    char * endptr;
    long int number = strtol(arg, &endptr, 10);

    if (endptr == arg) {
        printf("Error: Could not convert '%s' to a number.\n", arg);
        return;
    }

    int i;
    struct Stack *stack = createStack();

    while (number > 0) {
        push(stack, number % 2);
        number = number / 2;
    }

    while (stack->size > 0) {
        i = pop(stack);
        printf("%d", i);
    }
    printf("\n");

    destroyStack(stack);

    return;
}
