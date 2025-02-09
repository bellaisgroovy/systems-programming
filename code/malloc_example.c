#include <stdlib.h>
#include <stdio.h>

int main() {
    int * intArr = (int *) malloc(5 * sizeof(int));
    intArr[3] = 2;
    printf("%i\n", intArr[3]); // 2

    int * intPtr = malloc(sizeof(int));
    *intPtr = 6;
    printf("%i\n", *intPtr); // 6

    free(intArr);
    free(intPtr);
}