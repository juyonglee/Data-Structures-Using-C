#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

//  Queue를 초기화하는 기능
void QueueInit(Queue* pq) {
    pq->front = NULL;
    pq->rear = NULL;
}

//  Queue가 비어있는지 확인하는 기능
int QIsEmpty(Queue* pq) {
    if(pq->front == NULL)
        return TRUE;
    return FALSE;
}

//  Queue에 데이터를 저장하는 기능
void Enqueue(Queue* pq, Data data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(QIsEmpty(pq)) {
        pq->front = newNode;
        pq->rear = newNode;
    }
    pq->rear->next = newNode;
    pq->rear = newNode;
}
