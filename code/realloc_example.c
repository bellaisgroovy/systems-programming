#include <stdlib.h>
#include <stdio.h>

int main() {
    int * intArr = malloc(5 * sizeof(int));
    intArr[3] = 2;
    printf("%i\n", intArr[3]); // 2

    intArr = realloc(intArr, 8 * sizeof(int));
    intArr[7] = 5;
    printf("%i, %i\n", intArr[3], intArr[7]); // 2, 5

    free(intArr);
}