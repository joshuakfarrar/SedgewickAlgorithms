#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

struct Queue {
    struct Node *first;
    struct Node *last;
};

struct Queue *createQueue();
void queueQueue(struct Queue *queue, char *txt);
char *queueDequeue(struct Queue *queue);

#endif
