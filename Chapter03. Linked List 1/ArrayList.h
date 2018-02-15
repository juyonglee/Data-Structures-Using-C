#ifndef ARRAYLIST_H
#define ARRAYLIST_H

//  참과 거짓을 표현하기 위한 매크로 정의
#define TRUE    1
#define FALSE   0

#define LIST_LEN    100
//  LData에 대한 typedef 선언
typedef int LData;

//  배열기반 리스트를 정의한 구조체
typedef struct __ArrayList {
    //  리스트의 저장소인 배열
    LData arr[LIST_LEN];
    //  저장된 데이터의 수
    int numOfData;
    //  데이터 참조위치를 기록
    int curPosition;
} ArrayList

typedef ArrayList List;

//  초기화 기능
void ListInit(List *plist);
//  데이터 저장 기능
void LInsert(List *plist, LData data);
//  첫 데이터 참조 기능
int LFirst(List *plist, LData *pdata);
//  두 번째 이후 데이터 참조 기능
int LNext(List *plist, LData *pdata);
//  참조한 데이터 삭제 기능
LData LRemove(List *plist);
//  저장된 데이터의 개수 반환 기능
int LCount(List *plist);

#endif