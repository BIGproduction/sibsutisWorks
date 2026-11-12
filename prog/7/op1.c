#include <stdio.h>

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {

        if (c >= 'a' && c <= 'z') {
            putchar(c - 32);
        } 
        else if (c >= 'A' && c <= 'Z') {
            putchar(c + 32);
        } 
        else {
            putchar(c);
        }
    }
    return 0;
}