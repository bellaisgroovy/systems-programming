#include <stdlib.h>
#include <stdio.h>

int main() {
    int intArr[20];
    long int longArr[20];

    printf("%p, %p\n", &intArr[0], &intArr[1]);
    printf("%p, %p\n", &longArr[0], &longArr[1]);
}