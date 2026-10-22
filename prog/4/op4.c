#include <stdio.h>

int main() {
    int N = 0;
    int accumulator = 1;
    int i = 0;

    printf("Введите число N: ");

    int is_valid_input = (scanf("%d", &N) == 1);
    int is_valid_range = (N >= 2);
    int canary = is_valid_input * is_valid_range;

    printf("%.*s", (1 - is_valid_input) * 100, "Ошибка ввода \n");
    printf("%.*s", (1 - is_valid_range) * 100, "Для вычисления A(N, 2) число N должно быть >= 2 \n");

    accumulator *= canary;

    while (i < canary * 2) {
        accumulator *= (N - i);
        i++;
    }
    printf("Число размещений A(%2d, 2) = %2d\n", N, accumulator);

    return 0;
}

/* += (сумма): Аккумулятор начинается с 0, берем то, что уже накопили, и прибавляем новое слагаемое

   *= (произведение): Аккумулятор начинается с 1 (нейтральный элемент умножения)
   берем текущий результат и умножаем на новый множитель (prod = prod * x)
   если бы начали с 0, всё произведение обнулилось бы                                               */