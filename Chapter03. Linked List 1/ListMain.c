#include <stdio.h>
#include "ArrayList.h"

int main(void) {
    //  ArrayList 생성 및 초기화
    List list;
    int data;
    ListInit(&list);

    //  데이터 저장
    LInsert(&list, 60);
    LInsert(&list, 60);
    LInsert(&list, 80);
    LInsert(&list, 90);
    LInsert(&list, 100);

    //  저장된 데이터의 개수 출력 출력
    printf("현재 저장된 데이터의 개수: %d\n", LCount(&list));

    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);

        printf("\n\n");
    }

    //  숫자 60을 탐색하여 모두 삭제
    if(LFirst(&list, &data)) {
        if(data == 60)
            LRemove(&list);

        while(LNext(&list, &data)) {
            if(data == 60)
                LRemove(&list);
        }
    }

    //  삭제 후 남은 데이터 전체 출력
    printf("현재 데이터의 수: %d\n", LCount(&list));

    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
        
        printf("\n\n");
    }
    
    return 0;
}