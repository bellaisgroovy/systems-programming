```c
#include <stdio.h>
#include <string.h>

typedef struct VowelCounter {
    int a;
    int e;
    int i;
    int o;
    int u;
} VowelCounter;

// take a string composed of multiple sentences and print each sentence on a separate line.
// print the character count
// stops when it finds two identical characters in succession
// keep count of each vowel (a,e,i,o,u) that appears in the text, and print these counts after the total character count
int main() {
    char* sentence = "Were all on the same page. Youre the smartest guy Ive ever met. The funs over. Im not saying its not bad. Its bad. But it could be worse.";
    
    int charCount = 0;

    //initialise vowelcounter
    VowelCounter vc;
    vc.a = 0;
    vc.e = 0;
    vc.i = 0;
    vc.o = 0;
    vc.u = 0;

    char lastLetter = '\0'; // set to end of string indicator, char can't be NULL

    for (int letterIndex = 0; letterIndex < strlen(sentence); letterIndex++) {
        // if two letters in a row, then stop counting and printing
        if (sentence[letterIndex] == lastLetter) {

            printf("\n");
            break;

        } else {
            lastLetter = sentence[letterIndex];
        }

        // keep total of each vowel
        switch(sentence[letterIndex]) {
            case 'a':
                vc.a++;
                break; // breaks out of switch statement - not loop
            case 'e':
                vc.e++;
                break;
            case 'i':
                vc.i++;
                break;
            case 'o':
                vc.o++;
                break;
            case 'u':
                vc.u++;
                break;
        }

        // if end of sentence, make new line, otherwise print letter
        if (sentence[letterIndex] == '.') {
            printf(".\n");

        } else {
            printf("%c", sentence[letterIndex]);
        }

        charCount++;
    }

    printf("character count: %i\n", charCount);
    printf("vowel count: a:%i, e:%i, i:%i, o:%i, u:%i\n", vc.a, vc.e, vc.i, vc.o, vc.u);
}
```