#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

//  초기화 기능
void ListInit(List* plist) {
    plist->head = (Node*) malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData =0;
}

//  데이터 삽입 기능
void LInsert(List *plist, LData data) {
    //  정렬의 기준이 마련되지 않은 경우
    if(plist->comp == NULL) {
        //  머리에 노드를 추가
        FInsert(plist, data);
    } else {
        //  정렬 기준에 따라 노드를 추가
        SInsert(plist, data);
    }
}