#include <stdio.h>
#include <stdlib.h>

int main() {
    char * str = "12345";
    int num = atoi(str);
    num--;
    printf("%i\n", num);
}