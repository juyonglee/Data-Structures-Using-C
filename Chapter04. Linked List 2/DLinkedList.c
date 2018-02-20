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

//  정렬 기준이 없는 경우의 데이터 삽입 기능
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

//  첫 데이터 참조 기능
int LFirst(List* plist, LData *pdata) {
    //  더미 노드가 NULL을 가리키는 경우
    if(plist->head->next==NULL){
        puts("데이터가 존재하지 않습니다.");
        //  반환할 데이터가 존재하지 않는다
        return FALSE;
    }
    //  before는 더미 노드를 가르킨다
    plist->before = plist->head;
    //  cur은 첫 번째 노드를 가르킨다
    plist->cur = plist->head->next;
    //  첫 번째 노드의 데이터를 전달
    *pdata = plist->head->next->data;
    //  데이터 반환 성공
    return TRUE;
}