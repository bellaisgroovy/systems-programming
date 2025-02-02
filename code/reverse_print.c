#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORDS_MAX 200

void reverse_print(char **p, int n); // prototype

int main(int argc, char *argv[]) { // number of arguements and content of arguments
    char *message[WORDS_MAX] = {"I", "think", "we", "have", "got", "our", "roles", "reversed"};

    int n;

    if (argc >= 2) {
        n = atoi(argv[1]); // string to integer conversions
    } else {
        n = 3;
    }

    reverse_print(message, n);
}

// prints last n elements of p in reverse order
void reverse_print(char **p, int n) {
    for (int wordIndex=n-1; wordIndex>=0; wordIndex--) {
        if (p[wordIndex] != NULL) {
            printf("%s ", p[wordIndex]);
        }
    }
    printf("\n");
}
