#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRAYSIZE 1000000
#define NUMTHREADS 100
#define RANDLIMIT 50 // biggest number allowed from random gen ( +1 )
#define RANDINT() rand()%RANDLIMIT // this will work for us!

typedef struct _chunk {
    int * firstArr, * secondArr; // arrays to compute the product of
    int start, end; // beginning and end of the chunk we want to compute
    long double * result;  // to hold the result
    // Q2: you will need a mutex here...!
    pthread_mutex_t * resultMutex;
} chunk_t;

void * dotProd(void * arg) {
    // Q2: introduce locking to avoid a race condition, _inside_ the for loop
    chunk_t * toCompute = (chunk_t *)arg;

    int index, multAtIndex;
    for (index = toCompute->start; index < toCompute->end; index++) {
        // compute the dot product, one index at a time!
        multAtIndex = (toCompute->firstArr[index] * toCompute->secondArr[index]);
        *toCompute->result = *toCompute->result + multAtIndex;
    }

    pthread_exit(NULL);
}

void printArgs(chunk_t arg) {
    printf("arr1:\t%p\narr2:\t%p\nstart:\t%d\nend:\t%d\n\n",
    arg.firstArr,
    arg.secondArr,
    arg.start,
    arg.end);
}

int main() {
    int arr1[ARRAYSIZE], arr2[ARRAYSIZE];
    int i;

    // prepoluate the arrays with random numbers
    for (i = 0; i < ARRAYSIZE; i++) {
        // I have taken care of the random integer logic above
        arr1[i] = RANDINT(); 
        arr2[i] = RANDINT();
    }

    // produce a sensible argument array
    pthread_mutex_t resultMutex; // a mutex to write the result
    pthread_mutex_init(&resultMutex, NULL); // initialise the mutex

    chunk_t args[NUMTHREADS]; // NUMTHREADS arguments, one for each of the threads we will start

    long double calculationResult[NUMTHREADS]; // to hold the result of our calculations
    
    int chunk_size = ARRAYSIZE/NUMTHREADS; // How much of the array should each chunk calculate on?
    for (i = 0; i < NUMTHREADS; i++) {
        args[i].firstArr = arr1;
        args[i].secondArr = arr2;
        args[i].start = i*chunk_size;
        args[i].end = (i+1)*chunk_size;

        calculationResult[i] = 0;
        args[i].result = &calculationResult[i];

        args[i].resultMutex = &resultMutex;
        printArgs(args[i]);
    }
    
    pthread_t threads[NUMTHREADS];

    for (i = 0; i < NUMTHREADS; i++) {
        pthread_create(&threads[i], NULL, dotProd, (void *) &args[i]);
    }

    long double total = 0;
    for (i = 0; i < NUMTHREADS; i++) {
        pthread_join(threads[i], NULL);

        total += calculationResult[i];
    }

    printf("The dot product for our random arrays works out as %Lf.\n", total);

    return 0;

}
