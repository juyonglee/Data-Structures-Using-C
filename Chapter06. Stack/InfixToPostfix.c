#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

//  연산자의 연산 우선순위 정보를 반환
int GetOpPrec(char op) {
    switch(op) {
        case '*': 
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
            return 1;
    }
    return -1;
}