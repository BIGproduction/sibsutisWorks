#include <stdio.h>

int main() {
    int ch;
    int max_ascii = -1;

    while ((ch = getchar()) != '#' && ch != EOF) {
        if (ch > max_ascii) {
            max_ascii = ch;
        }
    }

    if (max_ascii != -1) {
        printf("максимальный ASCII-код: %d\n", max_ascii);
        printf("символ: %c\n", max_ascii);
    } else {
        printf("символы не введены\n");
    }
    
    return 0;
}