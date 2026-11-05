#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    int max_ascii = -1;
    int has_chars = 0;

    printf("введите текст (для завершения введите '#'):\n");

    while ((ch = getchar()) != '#') {
        
        if (ch == EOF) {
            break;
        }

        if (ch == '\n') {
            continue;
        }
        has_chars = 1;

        if (ch > max_ascii) {
            max_ascii = ch;
        }
    }

    printf("\n--- результаты ---\n");
    if (has_chars) {
        printf("максимальный ASCII-код: %d\n", max_ascii);
        
        if (isprint(max_ascii)) {
            printf("символ с этим кодом: '%c'\n", max_ascii);
        } else {
            printf("символ с этим кодом не является печатным.\n");
        }
    } else {
        printf("символы для анализа не введены (сразу введен '#').\n");
    }
    return 0;
}