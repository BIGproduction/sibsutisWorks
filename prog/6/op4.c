#include <stdio.h>

int main(void) {
    double gb, cost, total;

    printf("Введите объем трафика (ГБ): ");
    scanf("%lf", &gb);

    if (gb < 10) {
        cost = 1.0;
    } else if (gb <= 60) {
        cost = 0.8;
    } else {
        cost = 0.5;
    }

    total = gb * cost;

    printf("Итоговая стоимость: %.1f тугрика\n", total);

    return 0;
}