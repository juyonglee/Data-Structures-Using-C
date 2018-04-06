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
