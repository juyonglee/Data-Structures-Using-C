#include <stdio.h>
#include "CLinkedList.h"

int main(void) {
    //  원형 연결 리스트의 생성 및 초기화
    List list;
    int data, nodeNum;
    ListInit(&list);

    //  리스트에 데이터를 저장
    LInsert(&list, 80);
    LInsert(&list, 70);
    LInsert(&list, 100);
    LInsert(&list, 90);
    LInsert(&list, 70);

    //  리스트에 저장된 데이터를 2번 출력 
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        for(int i=0; i<LCount(&list)*2-1; i++) {
            if(LNext(&list, &data)) {
                printf("%d ", data);
            }
        }
    }
    printf("\n");
    
    //  70을 찾아서 모두 삭제
    if(LCount(&list) != 0) {
        LFirst(&list, &data);
        if(data == 70)
            LRemove(&list);

        for(int i=0; i<LCount(&list); i++) {
            LNext(&list, &data);
            if(data == 70) 
                LRemove(&list);
        }  
    }
    
    //  전체 데이터 출력
    if(LFirst(&list, &data)) {
        printf("%d ", data);
        for(int i=0; i<LCount(&list)-1; i++) {
            LNext(&list, &data);
            printf("%d ", data);
        }
    }
    printf("\n");
    return 0;
}