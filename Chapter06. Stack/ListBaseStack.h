#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TURE    1
#define FALSE   0

typedef int Data;

typedef struct _node {
    Data data;
    struct _node* next;
} Node;

typedef struct _listStack {
    Node* head;
} ListStack;

typedef ListStack Stack;

//  스택 초기화 기능
void StackInit(Stack* pstack);
//  스택이 비어있는지 확인하는 기능
int SIsEmpty(Stack* pstack);
//  스택의 push 연산
void SPush(Stack* pstack, Data data);
//  스택의 pop 연산
Data SPop(Stack* pstack);
//  스택의 peek 연산
Data SPeek(Stack* pstack);

#endif