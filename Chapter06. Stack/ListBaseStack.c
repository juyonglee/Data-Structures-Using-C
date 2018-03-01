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