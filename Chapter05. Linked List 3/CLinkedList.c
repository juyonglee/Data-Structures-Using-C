#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

//  리스트의 초기화 기능
void ListInit(List* plist) {
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

//  새로운 노드를 머리에 추가하는 기능
void LInsertFront(List* plist, Data data) {
    //  새로운 노드 생성
    Node* newNode = (Node*) malloc(sizeof(Node));
    //  새로운 노드에 데이터 저장
    newNode->data = data;

    //  첫 번째 노드인 경우
    if(plist->tail == NULL) {
        //  tail이 새로만든 노드를 가리키게 한다.
        plist->tail == newNode;
        //  새로운 노드가 자신을 가리키게 한다.
        newNode->next = newNode;
    } else {
        //  새로운 노드를 추가
        newNode->next = plist->tail->next;
        //  마지막 노드와 새로운 노드를 연결
        plist->tail->next = newNode;
    }
    (plist->numOfData)++;
}

//  새로운 노드를 꼬리에 추가하는 기능
void LInsert(List* plist, Data data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    if(plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    } else {
        //  처음을 가르킨다
        // plist->tail->next
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        //  [LInsetFront 함수와 유일한 차이]
        //  꼬리에 추가하기 때문에 tail을 이동시켜줘야 한다.
        plist->tail = newNode;
    }
    (plist->numOfData)++;
}