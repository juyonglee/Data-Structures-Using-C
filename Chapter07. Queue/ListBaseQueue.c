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

//  Queue에 데이터를 반환하는 기능
Data Dequeue(Queue* pq) {
    if(QIsEmpty(pq)) {
        puts("데이터가 존재하지 않아 Dequeue 동작을 수행할 수 없습니다.");
        exit(-1);
    }
    Node* delNode = pq->front;
    Data retData = delNode->data;
    pq->front = delNode->next;
    free(delNode);
    return retData;
}

//  Queue에 저장된 가장 앞선 데이터를 반환하는 기능
Data QPeek(Queue* pq) {
    if(QIsEmpty(pq)) {
        puts("데이터가 존재하지 않아 Peek 동작을 수행할 수 없습니다.");
        exit(-1);
    }
    return pq->front->data;
}
