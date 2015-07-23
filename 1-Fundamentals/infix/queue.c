#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "node.h"

struct Queue * createQueue() {
    return malloc(sizeof(struct Queue));
}

void qq(struct Queue * queue, char value) {
    struct Node *item = createNode();
    item->value = value;

    if (queue->size == 0) {
        queue->first = item;
        queue->last = item;
    } else {
        queue->last->next = item;
        queue->last = item;
    }

    queue->size++;

    return;
}

char qd(struct Queue * queue) {
    if (queue->size == 0) {
        printf("nothing in this queue\n");
    }
    struct Node *item = queue->first;
    char ch = item->value;

    queue->first = item->next;

    destroyNode(item);

    queue->size--;

    return ch;
}

void qp(struct Queue * queue) {
    struct Node *item = queue->first;
    while(item != NULL) {
        printf("%c", item->value);
        item = item->next;
        if (item != NULL) {
            printf(" ");
        }
    }
    printf("\n");
    return;
}
