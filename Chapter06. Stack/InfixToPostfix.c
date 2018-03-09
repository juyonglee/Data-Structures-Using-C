#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

//  연산자의 연산 우선순위 정보를 반환
int GetOpPrec(char op) {
    switch(op) {
        //  가장 높은 연산의 우선순위
        case '*': 
        case '/':
            return 5;
        //  *, / 보다 낮은 연산의 우선순위
        case '+':
        case '-':
            return 3;
        //  가장 낮은 연산의 우선순위
        case '(':
            return 1;
    }
    //  등록되지 않은 연산자인 경우 -1을 반환
    return -1;
}

//  두 연산자의 우선순위를 비교하는 기능
int WhoPrecOp(char op1, char op2) {
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);
    //  op1의 우선순위가 높은 경우 1을 반환
    if(op1 > op2)
        return 1;
    //  op2의 우선순위가 높은 경우 -1을 반환
    else if(op1 < op2)
        return -1;
    //  op1과 op2의 우선순위가 같다면 0을 반환
    else
        return 0;
}

//  후위 표기법으로 바꿔주는 기능
void ConvToRPNExp(char exp[]) {
    Stack stack;
    int expLen = strlen(exp);
    char* convExp = (char*) malloc(sizeof(expLen)+1);
    //  할당된 배열을 0으로 초기화
    memset(convExp, 0, sizeof(char)*expLen+1);
    StackInit(&stack);

    int idx = 0;
    //  tok는 입력한 식에서 하나씩 분리한 문자!!
    char tok, popOp;

    for(int i=0; i<expLen; i++) {
        //  변수 exp로 전달된 수식을 한 문자씩 tok 변수에 저장
        tok = exp[i];
        if(isdigit(tok)) {
            convExp[idx++] = tok;
        } else {
            //  연산자인 경우
            switch(tok) {
                //  (인 경우
                case '(':
                    //  스택에 쌓는다
                    SPush(&stack, tok);
                    break;
                //  )인 경우
                case ')':
                    while(1) {
                        char popOp = SPop(&stack);
                        if(popOp == '(')
                            break;
                        convExp[idx++] = popOp;
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    //  stack의 있는 연산자의 우선순위가 더 높은 경우 or 같은 경우
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
                        convExp[idx++] = SPop(&stack);
                    SPush(&stack, tok);
                    break;
            }
        }
    }

    while(!SIsEmpty(&stack))
        convExp[idx++] = SPop(&stack);
    
    strcpy(exp, convExp);
    free(convExp);
}