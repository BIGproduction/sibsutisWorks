#include <stdio.h>

const int MINUTES_IN_DEGREE = 60;

int main() {
    int total_min;
    int degrees;
    int remaining_min;

    printf("Программа конвертации углов \n");
    printf("Введите величину в минутах: \n");

    while (scanf("%d", &total_min) == 1 && total_min > 0) {
        
        degrees = total_min / MINUTES_IN_DEGREE;
        remaining_min = total_min % MINUTES_IN_DEGREE;

        printf("%d град %d мин\n", degrees, remaining_min);
    }

    printf("Программа завершена.\n");
    return 0;
}