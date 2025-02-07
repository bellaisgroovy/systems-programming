#include <stdlib.h>
#include <stdio.h>

int main() {
    int * x = (int *) malloc(sizeof(int));
    *x = 3;
    printf("%i\n", *x);

    free(x);
    free(x);
}