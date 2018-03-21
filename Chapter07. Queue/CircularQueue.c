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

//  Queue에 데이터를 저장하는 기능
void Enqueue(Queue *pq, Data data) {
    //  Queue가 꽉 찬 경우
    if(NextPosIdx(pq->rear) == pq->front) {
        puts("저장공간이 부족해 Queue에 더 이상의 데이터를 저장할 수 없습니다.");
        exit(-1);
    }

    //  데이터의 추가를 위해 rear을 한 칸 이동
    pq->rear = NextPosIdx(pq->rear);
    //  rear가 가리키는 곳에 데이터 저장
    pq->queArr[pq->rear] = data;
}
