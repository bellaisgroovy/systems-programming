#include <stdio.h>
#include <string.h>

#define WORDS_MAX 8

void reverse_print(char **p, int n); // prototype
void _reverse_print_word(char *word);

int main() {
    char *message[WORDS_MAX] = {"I", "think", "we", "have", "got", "our", "roles", "reversed"};

    reverse_print(message, 3);
}

// take an array of strings p and a number of words n. 
// It should then print the first n strings(words) in reverse order.
void reverse_print(char **p, int n ) {
    int wordIndex = 0;
    while (wordIndex < n) {
        _reverse_print_word(p[wordIndex]);
        wordIndex++;
    }
    printf("\n");
    return;
}

// print word in reverse order
void _reverse_print_word(char *word) {
    printf("%s\n", word);
    for (int letterIndex = strlen(word); letterIndex > 0; letterIndex--) {
        printf("%c", word[letterIndex]);
    }
    return;
}

