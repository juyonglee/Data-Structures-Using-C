#include <stdio.h>
#include "CircularQueue.h"

int main(void) {
    //  Queue의 생성
    Queue q;
    //  Queue의 초기화
    QueueInit(&q);
    
    //  Queue에 데이터 삽입
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);
    
    //  데이터 꺼내기 - 프로그램의 종료를 방지하기 위해 사용자가 구현한 코드
    while(!QIsEmpty(&q))
        printf("%d ", Dequeue(&q)); 
    
    return 0;
}
