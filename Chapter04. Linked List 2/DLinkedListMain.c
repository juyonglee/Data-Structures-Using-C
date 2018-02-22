#include <stdio.h>
#include "DLinkedList.h"

int main(void) {
    //  리스트의 생성 및 초기화
    List list;
    int data;
    ListInit(&list);

    //  데이터의 저장
    LInsert(&list, 60);
    LInsert(&list, 70);
    LInsert(&list, 80);
    LInsert(&list, 90);

    //  저장된 데이터의 전체 출력
    printf("현재 저장된 데이터의 수: %d\n", LCount(&list));

    if(LFirst(&list, &data)) {
        printf("%d ", data);
        while(LNext(&list, &data)) {
            printf("%d ", data);    
        }
    }
    printf("\n\n");

    //  숫자 70을 검색하여 모두 삭제
    if(LFirst(&list, &data)) {
        if(data == 70)
            LRemove(&list);

        while(LNext(&list, &data)) {
            if(data == 70)
                LRemove(&list);   
        }
    }

    //  삭제 후 남아있는 데이터 전체 출력
    printf("현재 저장된 데이터의 수: %d\n", LCount(&list));

    if(LFirst(&list, &data)) {
        printf("%d ", data);
        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");
    return 0;
}