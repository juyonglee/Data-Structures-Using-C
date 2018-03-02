#include <stdio.h>
#include <stdib.h>
#include "ListBaseStack.h"

//  스택 초기화 기능
void StackInit(Stack* pstack) {
    pstack->head = NULL;
}

//  스택이 비어있는지 확인하는 기능
int SIsEmpty(Stack* pstack) {
    if(pstack->head == NULL)
        return TRUE;
    return FALSE;
}

//  스택의 push 기능
void SPush(Stack* pstack, Data data) {
    //  새로운 노드 생성
    Node* newNode = (Node*) malloc(sizeof(Node));
    //  새로운 노드에 데이터 저장
    newNode->data = data;
    //  세로운 노드가 최근에 추가된 노드를 가리킨다.
    newNode->next = pstack->head;
    //  head가 새로운 노드를 가리킨다.
    pstack->head = newNode;
}

//  스택의 pop 기능
Data SPop(Stack* pstack) {
    if(SIsEmpty(pstack)) {
        puts("Stack Memory Error!");
        exit(-1);
    }
    Node* nextNode = pstack->head->next;
    //  삭제할 노드의 데이터를 저장
    Data data = pstack->head->data;
    //  head가 가리키는 노드 삭제
    free(pstack->head);
    //  head가 다음 노드를 가리킴
    pstack->head = nextNode;
    //  삭제된 노드의 데이터 반환
    return data;
}

//  스택의 peek 기능
Data SPeek(Stack* pstack) {
    if(SIsEmpty(pstack)) {
        puts("Stack Memory Error!");
        exit(-1);
    }
    //  head가 가리키는 노드에 저장된 데이터 반환
    return pstack->head->data;
}