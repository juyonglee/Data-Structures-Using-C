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
    //  저장된 데이터가 하나도 없는 경우
    if(plist->numOfData == 0) {
        puts("저장된 데이터가 존재하지 않습니다.");
        return FALSE;
    }
    //  참조 위치 초기화
    plist->curPosition = 0;
    //  pdata가 가리키는 공간에 데이터 저장
    *pdata = plist->arr[0];
    return TRUE;
}

//  [두 번째 이후 데이터 참조 기능]
int LNext(List *plist, LData *pdata) {
    //  더 이상 참조할 데이터가 없는 경우
    if(plist->curPosition == (plist->numOfData)-1 {
        puts("데이터에 끝에 도달하여 탐색을 중단합니다.");
        return false;
    }
    //  참조 위치 증가
    (plist->curPosition)++;
    //  pdata가 가리키는 공간에 데이터 저장
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}

//  [참조한 데이터 삭제 기능]
LData LRemove(List *plist) {
    //  삭제할 데이터를 임시로 저장
    LData data = plist->arr[plist->curPosition];
    //  삭제를 위한 데이터의 이동을 진행하는 반복문
    for(int i=position; i<(plist->numOfData)-1; i++) {
        plist->arr[i] = plist->arr[i+1];
    }
    //  마지막 데이터를 0으로 초기화
    plist->arr[plist->curPosition] = 0;
    //  데이터의 수 감소
    (plist->numOfData)--;
    //  참조 위치를 하나 되돌림
    (plist->curPosition)--;
    //  삭제된 데이터를 반환
    return data;
}