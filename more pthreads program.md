```c
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// the rest is up to you! Implement a program which starts _two_ pthreads.
// One reads input from the user, and adds numbers to a total.
// the other prints the current total value every 3 seconds.
// After 30 seconds, the main thread sets a bool to false that signals
// to both threads that they should join, just like in 3.c.
// You can use sleep(int seconds) from unistd.h/windows.h to make your
// threads sleep.

typedef struct _threadinfo {
    bool * keepRunning;
    int * total;
} threadinfo_t;

void * addInputs(void * arg) {
    threadinfo_t * args = (threadinfo_t *) arg;

    int currentInput = 0;

    while(*args->keepRunning) {
        printf("Add another number!  : ");
        scanf("%d", &currentInput);
        *args->total += currentInput;
    }

    pthread_exit(NULL);
}

void * printTotal(void * arg) {
    threadinfo_t * args = (threadinfo_t *) arg;

    while(*args->keepRunning) {
        printf("total: %i\n", *args->total);
        sleep(3);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t adder;
    pthread_t printer;

    bool keepRunning = true;
    int total = 0;
    threadinfo_t arg = {&keepRunning, &total};

    adder = pthread_create(&adder, NULL, addInputs, &arg);
    printer = pthread_create(&adder, NULL, printTotal, &arg);

    sleep(10);

    keepRunning = false;

    pthread_exit(NULL);
}
```