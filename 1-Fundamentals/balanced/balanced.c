#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int matchingPair(const char open, const char close) {
    char match;

    switch(open) {
        case '{':
            match = '}';
            break;
        case '[':
            match = ']';
            break;
        case '(':
            match = ')';
            break;
    }

    if (match != close) {
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int i;
    struct Stack *stack = createStack();
    char ch;
    char p;

    for(i = 0; i < strlen(argv[1]); i++) {
        ch = argv[1][i];
        switch(argv[1][i]) {
            case '{':
            case '[':
            case '(':
                push(stack, ch);
                break;
            case '}':
            case ']':
            case ')':
                p = pop(stack);
                if ( matchingPair(p, ch) < 0) {
                    printf("false\n");
                    exit(1);
                }
                break;
        }
    }

    // to solve the "what if there are too few closing parans?" bug
    if (stack->size > 0) {
        printf("false\n");
        return 1;
    }

    printf("true\n");
    return 0;
}
