
#include <stdio.h>

#define HEIGHT 5

int main(void) {
    for (int i = 1; i <= HEIGHT; i++) {

        // Вывод пробелов
        for (int j = 0; j < HEIGHT - i; j++) {
            printf(" ");
        }

        // Вывод символов
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
