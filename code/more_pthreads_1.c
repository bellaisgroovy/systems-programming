#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 20

void * fizzbuzz(void * arg) {
    // Convert the int at arg to a string
    // ("fizz" if divides by 3, "Buzz" if divides by 5, 'no div' if divides by neither.)

    // You will need to make use of the strcpy function of C's standard 
    // String library (string.h)
    // 
    //     char* strcpy(char* destination, const char* source);
    //     e.g. strcpy(strToReturn, "fizz");
    // 
    // to get these string literals into allocated heap memory

    // return the string for the val.
}

int main() {

    pthread_t threads[20];
    int nums[20];

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        nums[i] = i+1;
        pthread_create(&threads[i], NULL, fizzbuzz, &nums[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        char * returnedStr;
        pthread_join(threads[i], (void *) &returnedStr);
        printf("%d -> %s\n", i+1, returnedStr);
        free(returnedStr);
    }

    pthread_exit(NULL);

}
