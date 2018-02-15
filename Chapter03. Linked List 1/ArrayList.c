#include <stdio.h>
#include "ArrayList.h"

//  [초기화 기능 구현]
void ListInit(List *plist) {
    //  리스트에 저장된 데이터의 수를 0으로 초기화
    plist->numOfData = 0;
    //  배열의 인덱스 값으로 사용할 것이므로 0이 아닌 -1로 초기화
    plist->curPosition = -1;
}

//  [데이터 저장 기능 구현]
void LInsert(List *plist, LData data) {
    if(plist->numOfData == LIST_LEN) {
        puts("저장공간이 부족해 더 이상 저장할 수 없습니다.");
        return;
    }
    //  데이터 저장
    plist->arr[plist->numOfData] = data;
    //  저장된 데이터의 수 증가
    (plist->numOfData)++;
}

//  [시작 데이터 참조 기능]
int LFirst(List *plist, LData *pdata) {
    if(plist->numOfData == 0) {
        puts("저장된 데이터가 존재하지 않습니다.");
        return FALSE;
    }
    plist->curPosition = 0;
    *pdata = plist->arr[0];
    return TRUE;
}