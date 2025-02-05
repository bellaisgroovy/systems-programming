#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>  // gives us sleep(). Replace with windows.h for compiling on windows!

#define NUM_THREADS 20

typedef struct _threadinfo {
    bool * keepRunning;
    int * total;
} threadinfo_t;

void * getInput(void * arg) {
    // cast from general void * for meaningful datatype
    threadinfo_t * args = (threadinfo_t *) arg;
    bool * keepRunning = (bool *) arg;

    int * total = malloc(sizeof(int));
    *total = 0;
    
    int currInput; // initialise currInput so its not done each iteration
    printf("Input as much as you can --- you have 10 seconds!\n");
    while (*keepRunning) { // checks value at keeprunning (stored elsewhere is true)
        printf("Add another number!  : ");
        scanf("%d", &currInput); // gets number input from console
        *total+= currInput; // adds input to total
    }
    pthread_exit(total);
}

int main() {

    pthread_t thread;
    bool keepRunning = true; 
    int total = 0;
    threadinfo_t args = {&keepRunning, &total}; // stores value on this stack to pass to thread

    pthread_create(&thread, NULL, getInput, &keepRunning); // start thread with getInput and arguments from this stack frame

    sleep(3); // sleep for 10 secs
    keepRunning = false; // set keepRunning which thread has reference to false so it stops

    int * total2;
    pthread_join(thread, (void *) &total2); 
    printf("\n\nYou managed to enter a total of: %d!\n", *total2);

    pthread_exit(NULL);

}
