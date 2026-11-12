#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;
    long total = 0;
    long total_hex = 0;

    while ((c = getchar()) != EOF) {
        total++;

        if (isxdigit(c)) {
            total_hex++;
        }
    }
    printf("\n--- Статистика ---\n");
    printf("общее количество обработанных символов: %ld\n", total);
    printf("количество шестнадцатеричных цифр (0-9, a-f, A-F): %ld\n", total_hex);

    return 0;
}