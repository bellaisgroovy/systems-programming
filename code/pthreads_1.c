/*
  This code _should_ print all of the characters in "Hello, world!"
  Modify `entry()` so that our threads print the characters they are passed as arguments.
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 14

void * entry(void * arg) {
}

int main() {

    char hw[] = "Hello, world!";
    pthread_t threads[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, entry, &hw[i]);
    }

    return 0;

}