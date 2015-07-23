#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

#define CHARACTER_INSERTED 1

void insertParen(struct Queue * queue) {
    int ops = 0;
    int needed_parens = 0;

    char ch;

    struct Stack *s = createStack();
    struct Stack *t = createStack();
    while(queue->size > 0) {
        push(s, qd(queue));
    }

    int done = 0;
    while( ! done ) {
        ch = peek(s);
        switch(ch) {
            case '+':
            case '-':
            case '*':
            case '/':
                ops++;
                if (ops > needed_parens) {
                    done = 1;
                } else {
                    push(t, pop(s));
                }
                break;
            case ')':
                needed_parens++;
            default:
                push(t, pop(s));
                break;
        }

        if (s->size == 0 || done == 1) {
            push(t, '(');
            done = 1;
        }
    }

    // drain whatever is left
    while (s->size > 0) {
        push(t, pop(s));
    }

    while (t->size > 0) {
        qq(queue, pop(t));
    }

    return;
}

int handleCharacter(struct Queue * queue, char character) {
    switch(character) {
        case ' ':
            break;
        case ')':
            qq(queue, character);
            insertParen(queue);
            return CHARACTER_INSERTED;
        default:
            qq(queue, character);
            break;
    }
    return 0;
}

int main(int argc, char * argv[]) {
    int i, res;
    char * string = argv[1];
    struct Queue *queue = createQueue();

    for (i = 0; i < strlen(string); i++) {
        res = handleCharacter(queue, string[i]);
        if (res == CHARACTER_INSERTED) {
            i++;
        }
    }

    // print results
    qp(queue);

    return 0;
}
