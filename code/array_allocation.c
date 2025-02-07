#include <stdlib.h>
#include<stdio.h>

int* allocateArray(int arr[], int len) {
    if (arr) {
        free(arr);
        arr = NULL;
    }

    arr = (int *)malloc(len * sizeof(int));
    return arr;
}

int main() {
    int size = 8;int *array = allocateArray(NULL, size);

    // store some values in the array
    for (int i = 0; i < size; i++) {
        array[i] = i*i;
    }

    // attempt to change the array size
    size = 10;
    array = allocateArray(array, size);
    free(array);
    array = NULL;

    printf("ran all the way");
}