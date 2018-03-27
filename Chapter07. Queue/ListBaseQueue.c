#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

//  Queue를 초기화하는 기능
void QueueInit(Queue* pq) {
    pq->front = NULL;
    pq->rear = NULL;
}
