#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

//  Dequeue를 초기화하는 기능
void DequeInit(Deque * pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

//  Dequeue가 비어있는지 확인하는 기능
int DQIsEmpty(Deque * pdeq) {
    if(pdeq->head == NULL)
        return TRUE;
    return FALSE;
}

//  Dequeue의 머리에 데이터를 저장하는 기능
void DQAddFirst(Deque * pdeq, Data data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = pdeq->head;
    
    if(DQIsEmpty(pdeq)) {
        pdeq->head = newNode;
        pdeq->tail = newNode;
    } else {
        pdeq->head->prev = newNode;
    }
    
    pdeq->head = newNode;
    newNode->prev = NULL;
}

//  Dequeue의 꼬리에 데이터를 저장하는 기능
void DQAddLast(Deque * pdeq, Data data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pdeq->tail;

    if(DQIsEmpty(pdeq)) {
        pdeq->head = newNode;
    } else {
        pdeq->tail->next = newNode;
    }
    newNode->next = NULL;
    pdeq->tail = newNode;
}

//  Dequeue의 머리에 데이터를 삭제하는 기능
Data DQRemoveFirst(Deque * pdeq) {
    Node* removeNode = pdeq->head;
    Data removeData = removeNode->data;

    Node* node = removeNode->next;
    pdeq->head = node;

    if(pdeq->head == NULL) {
        pdeq->tail = NULL;
    } else {
        node -> prev = NULL;
    }

    free(removeNode);
    
    return removeData;
}
