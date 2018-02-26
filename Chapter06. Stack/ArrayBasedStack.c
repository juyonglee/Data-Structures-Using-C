#include <stdio.h>
#include "ArrayBasedStack.h"

//  스택의 초기화 기능
void StackInit(Stack* pstack) {
    // -1은 Stack의 빈 상태를 의미
    pstack->topIndex = -1;
}

//  스택이 비어있는지 확인하는 기능
int SIsEmpty(Stack* pstack) {
    //  스택이 비어있다면
    if(pstack->topIndex == -1)
        return TRUE;
    return FALSE;
}

//  스택의 push 기능
void SPush(Stack* pstack, Data data) {
    if(pstack->topIndex < STACK_LEN) {
        pstack->stackArr[++(pstack->topIndex)] = data;
        return;
    }
    printf("더 이상 데이터를 저장할 수 없습니다.");
}

//  스택의 pop 기능
Data SPop(Stack* pstack) {
    if(SIsEmpty(pstack)) {
        puts("저장된 데이터가 존재하지 않습니다.");
        exit(-1);
    }
    Data data = pstack->stackArr[(pstack->topIndex)--];
    return data;
}

//  스택의 peek 기능
Data SPeek(Stack* pstack) {
    if(SIsEmpty(pstack)) {
        puts("저장된 데이터가 존재하지 않습니다.");
        exit(-1);
    }
    //  맨 위에 저장된 데이터 반환
    return pstack->stackArr[pstack->topIndex];
}