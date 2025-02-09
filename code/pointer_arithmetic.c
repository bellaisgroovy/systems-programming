#include <stdio.h>

int main() {
    int x = 3;
    int * xPtr = &x;

    int y = 4;
    int * yPtr = &y;

    printf("%p\n", xPtr);

    long zPtr = xPtr - yPtr;

    long isMore = xPtr * 5;

    printf("%ld \n", more);

    printf("%ld \n", zPtr);
}