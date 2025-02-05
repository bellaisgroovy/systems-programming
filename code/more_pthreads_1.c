#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 20

void * fizzbuzz(void * arg) {

    // Convert the int at arg to a string
    int * number = (int *) arg;

    char * fizz_buzz;

    // ("fizz" if divides by 3, "Buzz" if divides by 5, 'no div' if divides by neither.)
    if (*number % 3 == 0) {
        fizz_buzz = "fizz";
    } else if (*number % 5 == 0) {
        fizz_buzz = "Buzz";
    } else {
        fizz_buzz = "no div";
    }

    //printf("%i: %s\n", *number, fizz_buzz);

    // You will need to make use of the strcpy function of C's standard 
    // String library (string.h)
    // 
    //     char* strcpy(char* destination, const char* source);
    //     e.g. strcpy(strToReturn, "fizz");
    // 
    // to get these string literals into allocated heap memory
    char * strToReturn = malloc(sizeof(fizz_buzz));

    strcpy(strToReturn, fizz_buzz);

    // return the string for the val.
    return strToReturn;
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
