#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    //  데이터를 담을 변수
    int data;
    //  연결의 도구(Node형 구조체 변수를 가르킬 수 있다.)
    struct _node* next;
} Node;

int main(void) {
    //  리스트의 머리를 가리키는 포안터
    Node* head = NULL;
    //  리스트의 꼬리를 가리키는 포안터
    Node* tail = NULL;
    //  저장된 데이터 조회에 사용하기 위한 포인터 변수
    Node* cur = NULL;

    Node* newNode = NULL;
    int readData;

    //  데이터를 입력 받는 기능
    while(1) {
        printf("자연수 입력: ");
        scanf("%d", &readData);
        if(readData<1) 
            break;
        //  노드의 생성
        newNode = (Node*) malloc(sizeof(Node));
        //  노드에 데이터 저장
        newNode->data = readData;
        //  노드의 next를 NULL로 초기화
        newNode->next = NULL;
        
        //  첫 번째 노드인 경우
        if(head == NULL) {
            //  head가 첫 번째 노드를 가리킴
            head = newNode;
        } else {
            //  두 번째 이후 노드인 경우
            tail->next = newNode;
        } 
        //  노드의 끝을 tail이 가리킴
        tail = newNode;
    }
    printf("\n");

    //  입력 받은 데이터의 출력 기능
    puts("[입력 받은 데이터의 전체출력!]");
    //  head가 가리키는 노드가 없는 경우
    if(head == NULL) {
        puts("저장된 자연수가 존재하지 않습니다.");
    } else {
        //  cur이 리스트의 첫 번째 노드를 가리키게 한다
        cur = head;
        //  첫 번째 데이터 출력
        printf("%d ", cur->data);
        //  연결된 노드가 존재하는 경우
        while(cur->next != NULL) {
            //  cur이 다음 노드를 가리키게 함
            cur = cur->next;
            //  cur이 가리키는 노드를 출력
            printf("%d ", cur->data);
        }
    }
    printf("\n\n");

    //  메모리 해제과정
    //  head가 가리키는 노드가 없는 경우
    if(head == NULL) {
        puts("삭제할 데이터가 존재하지 않습니다.");
        return 0;
    } else {
        Node* delNode = head; 
        Node* delNextNode = head->next;
        //  삭제된 데이터 출력
        printf("%d을(를) 삭제합니다.\n", delNode->data);
        //  첫 번째 노드 삭제
        free(delNode);
        while(delNode->next != NULL) {
            delNode = delNextNode;
            delNextNode = delNode->next;
            //  삭제된 데이터 출력
            printf("%d을(를) 삭제합니다.\n", delNode->data);
            //  두 번째 이후 노드 삭제
            free(delNode);
        }
    }
}