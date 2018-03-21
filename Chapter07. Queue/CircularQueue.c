#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

//  Queue를 초기화하는 기능
void QueueInit(Queue *pq) {
    pq->front = 0;
    pq->rear = 0;
}

//  Queue가 비어있는지 확인하는 기능
int QIsEmpty(Queue *pq) {
    if(pq->front == pq->rear)
        return TRUE;
    return FALSE;
}