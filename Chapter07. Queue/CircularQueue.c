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

//  Queue의 다음 위치에 해당하는 인덱스 값을 반환하는 기능
int NextPosIdx(int pos) {
    if(pos+1 == QUE_LEN) 
        return 0;
    return pos+1;
}