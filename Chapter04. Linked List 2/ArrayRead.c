#include <stdio.h>

int main(void) {
    int arr[10];
    int readCount = 0;
    int readData;

    while(1) {
        if(readCount == 10) {
            puts("배열은 메모리의 특성이 정적이어서 메모리의 길이를 변경하는 것이 불가능하다!");
            break;
        }
        printf("자연수 입력: ");
        scanf("%d", &readData);
        if(readData <=0) 
            break;
        arr[readCount++] = readData;
    }

    for(int i=0; i<readCount; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}