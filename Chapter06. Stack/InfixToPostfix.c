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