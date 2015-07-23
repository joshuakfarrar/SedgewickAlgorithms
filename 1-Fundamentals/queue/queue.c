#include <stdlib.h>
#include <string.h>
#include "queue.h"

struct Queue *createQueue() {
   return malloc(sizeof(struct Queue));
}

void queueQueue(struct Queue *queue, char *txt) {
    struct Node *item = createNode();
    item->value = txt;

    if (queue->first == NULL) {
        queue->first = item;
        queue->last = item;
    } else {
        queue->last->next = item;
        queue->last = item;
    }

    return;
}

char *queueDequeue(struct Queue *queue) {
    struct Node *item = queue->first;
    char *buffer = strdup(item->value);

    queue->first = item->next;

    destroyNode(item);

    return buffer;
}
