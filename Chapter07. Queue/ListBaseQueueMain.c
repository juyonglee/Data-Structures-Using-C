#include <stdio.h>
#include "ListBaseQueue.h"

int main(void) {
    //  Queueㅇㅢ 생성 및 초기화
    Queue q;
    QueueInit(&q);

    //  데이터 삽입
    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);
    Enqueue(&q, 50);

    //  데이터 추출
    while(!QIsEmpty(&q))
        printf("%d ", Dequeue(&q));
    printf("\n");    
    return 0;
}
