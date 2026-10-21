#include <stdio.h>

int main() {
    int N;
    int accumulator = 1;
    int i = 0;

    printf("Введите число N: ");

    if (scanf("%d", &N) != 1) {
        printf("Ошибка ввода.\n");
        return 1;
    }
    
    if (N < 2) {
        printf("Для вычисления A(N, 2) число N должно быть >= 2.\n");
        return 1;
    }

    while (i < 2) {
        accumulator *= (N - i);
        i++;
    }

    printf("Число размещений A(%d, 2) = %d\n", N, accumulator);

    return 0;
}