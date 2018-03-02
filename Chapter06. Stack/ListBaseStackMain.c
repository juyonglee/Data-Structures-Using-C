#include <stdio.h>
#include "ListBaseStack.h"

int main(void) {
    //  Stack의 생성 및 초기화
    Stack stack;
    StackInit(&stack);

    //  데이터 넣기
    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);
    SPush(&stack, 5);
    SPush(&stack, 6);
    SPush(&stack, 7);
    SPush(&stack, 8);
    SPush(&stack, 9);
    SPush(&stack, 10);

    // 데이터 꺼내기
    while(!SIsEmpty(&stack)) {   
        printf("%d ", SPop(&stack));
    }
    printf("\n");

    return 0;
}