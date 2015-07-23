#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv[]) {
    struct Queue *queue = createQueue();
    queueQueue(queue, "hello");
    queueQueue(queue, "world");

    char *a = queueDequeue(queue);
    char *b = queueDequeue(queue);

    printf("%s %s\n", a, b);

    return 0;
}
