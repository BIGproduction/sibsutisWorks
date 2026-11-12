#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;
    long total_chars = 0;
    long hex_digits_count = 0;

    while ((c = getchar()) != EOF) {
        total_chars++;

        if (isxdigit(c)) {
            hex_digits_count++;
        }
    }
    printf("\n--- Статистика ---\n");
    printf("Общее количество обработанных символов: %ld\n", total_chars);
    printf("Количество шестнадцатеричных цифр (0-9, a-f, A-F): %ld\n", hex_digits_count);

    return 0;
}