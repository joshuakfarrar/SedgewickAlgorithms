#ifndef QUEUE_H
#define QUEUE_H

struct Queue {
    struct Node * first;
    struct Node * last;
    int size;
};

struct Queue * createQueue();
void qq(struct Queue * queue, char value);
char qd(struct Queue * queue);
void qp(struct Queue * queue);
void destroyQueue(struct Queue * queue);

#endif
