#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void * printInfo(void * arg) {
    // Why do we need (char *) before arg?
    char * user_input = (char *) arg;

    // Why does len have to be malloc-d?
    long int * len = malloc(sizeof(long int *));
    *len = strlen(user_input);
    printf("Argument %s has length %ld\n", user_input, *len);

    // What will this do?
    pthread_exit(len);
}

int main(int argc, char * argv[]) {

    // What do we use pthread_t values for?
    pthread_t * threads = malloc(argc * sizeof(pthread_t));
    int i;
    for (i = 0; i < argc; i++) {
        // Explain each argument to the pthread_create call, 
        // including which arguments have to be pointers to values _and why_.
        pthread_create(&threads[i], NULL, printInfo, argv[i]);
    }

    // Why should this be a **?
    long int ** lengths = malloc(argc * sizeof(int *));

    for (i = 0; i < argc; i++) {
        // Explain each argument to the pthread_join call,
        // especially why the (void*) and & are needed in the second arg.
        pthread_join(threads[i], (void *)&lengths[i]);
    }
    
    long int total = 0;
    for (i = 0; i < argc; i++) {
        total += *lengths[i];
    }
    printf("\n\nTotal length is %ld\n", total);

    // We have malloc'd a lot, but we have not free-d at all.
    // Free all necessary pointers here.

    return 0;

}
