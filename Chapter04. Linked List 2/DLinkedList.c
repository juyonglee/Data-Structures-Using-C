#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

//  초기화 기능
void ListInit(List* plist) {
    plist->head = (Node*) malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
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

//  정렬 기준이 있는 경우의 데이터 삽입 기능  
void SInsert(List* plist, LData data) {
    //  새로운 노드 생성
    Node* newNode = (Node*) malloc(sizeof(Node));
    //  pred는 더미 노드를 의미
    Node* pred = plist->head;
    //  새로운 노드에 데이터 저장
    newNode->data = data;
    //  새 노드가 들어갈 위치를 찾기 위한 반복문
    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
        //  다음 노드로 이동
        pred = pred->next;
    }
    //  세 노드의 뒤를 연결
    newNode->next = pred->next;
    //  새 노드의 앞을 연결
    pred->next = newNode;
    //  저장된 데이터의 수 하나 증가
    (plist->numOfData)++;
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
    *pdata = plist->cur->data;
    //  데이터 반환 성공
    return TRUE;
}

//  두 번째 이후 데이터 참조 기능
int LNext(List* plist, LData *pdata) {
    //  더미 노드가 NULL을 가리키는 경우
    if(plist->cur->next == NULL)
        return FALSE;
    //  cur이 가리키던 것을 before가 가리킴
    plist->before = plist->cur;
    //  cur은 그 다움 노드를 가리킴
    plist->cur = plist->cur->next;
    //  cur이 가리키는 노드의 데이터 전달
    *pdata = plist->cur->data;
    return TRUE;
}

//  참조한 데이터 삭제 기능
LData LRemove(List *plist) {
    //  삭제할 노드의 주소 값을 rPos에 저장
    Node* rPos = plist->cur;
    //  삭제할 노드의 데이터를 rData에 저장
    LData rData = rPos->data;
    //  삭제할 노드를 리스트에서 제거
    plist->before->next = plist->cur->next;
    //  cur이 가리키는 위치를 재조정
    plist->cur = plist->before;
    //  리스트에서 제거된 노드 소멸
    free(rPos);
    //  저장된 데이터의 수 하나 감소
    (plist->numOfData)--;
    //  삭제된 노드의 데이터 반환
    return rData;
}

//  저장된 데이터의 개수 반환 기능
int LCount(List* plist) {
    return plist->numOfData;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)) {
    plist->comp = comp;
}