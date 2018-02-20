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

void FInsert(List* plist, LData data) {
    //  새로운 노드 생성
    Node *newNode = (Node*) malloc(sizeof(Node));
    //  새로운 노드에 데이터 저장
    newNode->data = data;
    //  새로운 노드가 다른 노드를 가리키게 한다  
    newNode->next = plist->head->next;
    //  더미 노드가 새 노드를 가리키게 한다
    plist->head->next = newNode;
    //  저장된 노드의 수를 하나 증가
    (plist->numOfData)++;
}