#include <stdio.h>
#include <string.h>
#include "stack.h"

void handleToken(struct Stack * stack, char * token) {
    if (strcmp(token, "+") == 0) {
        push(stack, token);
    } else if (strcmp(token, "*") == 0) {
        push(stack, token);
    } else if (strcmp(token, ")") == 0) {
        printf("%s ", pop(stack));
    } else if (strcmp(token, "(") == 0) {
        printf("");
    } else {
        printf("%s ", token);
    }

    return;
}

int main(int argc, char * argv[]) {
    struct Stack *stack = createStack();
    char token[1024];
    char c;
    int i = 0;

    while ((c = fgetc(stdin)) != EOF) {
        if (c == ' ' || c == '\n') {
            token[i++] = '\0';
            handleToken(stack, token);
            memset(token, 0, 1024);
            i = 0;
        } else {
            token[i++] = c;
        }
    }

    printf("\n");

    return 0;
}
