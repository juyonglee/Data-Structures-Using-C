#include <stdio.h>

int factorial(int num) {
    if(num<=0)
        return 1;
    return num * factorial(num-1);
}

int main(void) {
    printf("6! = %d\n", factorial(0));
    return 0;
}