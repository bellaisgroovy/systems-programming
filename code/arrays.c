#include <stdio.h>
#include <stdlib.h>

int main() {
    float fArr[5];
    float multiDim[5][5];
    multiDim[3][1] = 5.0;

    int * iArr = malloc(sizeof(int) * 2);
    iArr[1] = 3;

    int litArr[] = {1, 2, 3};
}