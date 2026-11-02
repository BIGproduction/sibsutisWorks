#include <stdio.h>
#include <ctype.h>

int main() {
    int ch;
    int max_ascii = -1;

    while ((ch = getchar()) != '#' && ch != EOF) {
        if (ch > max_ascii) {
            max_ascii = ch;
        }
    }

    if (max_ascii != -1) {
        printf("Максимальный ASCII-код: %d\n", max_ascii);
        printf("Символ: %c\n", max_ascii);
    } else {
        printf("Символы не введены\n");
    }
    
    return 0;
}