#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

//  리스트의 초기화 기능
void ListInit(List* plist) {
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}