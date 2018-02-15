#include <stdio.h>
#include "ArrayList.h"

//  초기화 기능 구현
void ListInit(List *plist) {
    //  리스트에 저장된 데이터의 수를 0으로 초기화
    plist->numOfData = 0;
    //  배열의 인덱스 값으로 사용할 것이므로 0이 아닌 -1로 초기화
    plist->curPosition = -1;
}