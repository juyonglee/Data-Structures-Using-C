#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

//  초기화 기능
void ListInit(List* plist) {
    plist->head = (Node*) malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData =0;
}