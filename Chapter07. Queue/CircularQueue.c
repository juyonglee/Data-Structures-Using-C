#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue *pq) {
    pq->front = 0;
    pq->rear = 0;
}