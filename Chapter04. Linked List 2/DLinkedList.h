#ifndef D_LINKED_LIST_H
#define D_LINKED_LIST_H

//  참과 거짓을 표현하기 위한 매크로 정의
#define TRUE    1
#define FALSE   0

//  LData에 대한 typedef 선언
typedef int LData;

typedef struct _node {
    LData data;
    struct _node* next;
} Node;

typedef struct _linkedList {
    //  더미 노드를 가리키는 멤버
    Node* head;
    //  참조 및 삭제를 돕는 멤버
    Node* cur;
    //  삭제를 돕는 멤버
    Node* before;
    //  저장된 데이터의 개수를 기록하기 위한 멤버
    int numOfData;
    //  정렬의 기준을 등록하기 위한 멤버
    int (*comp)(LData d1, LData d2);
} LinkedList;

//  List에 대한 typedef 선언
typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List *plist, LData data);

int LFirst(List* plist, LData *pdata);
int LNext(List* plist, LData *data);

LData LRemove(List* plist);
int LCount(List* plist);
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));

#endif