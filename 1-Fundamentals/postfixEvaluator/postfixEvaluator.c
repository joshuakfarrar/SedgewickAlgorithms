#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void handleChar(struct Stack * stack, char c) {
    switch (c) {
      case ' ':
      case '\n':
        break;
      case '+':
        push(stack, (pop(stack) + pop(stack)));
        break;
      case '*':
        push(stack, (pop(stack) * pop(stack)));
        break;
      default:
        // http://stackoverflow.com/questions/439573/how-to-convert-a-single-char-into-an-int
        push(stack, (c - '0'));
        break;
    }
    return;
}

int main(int argc, char * argv[]) {
    char c;
    struct Stack *stack = createStack();

    while ((c = fgetc(stdin)) != EOF) {
      handleChar(stack, c);
    }

    printf("Result: %d\n", pop(stack));

    destroyStack(stack);

    return 0;
}
