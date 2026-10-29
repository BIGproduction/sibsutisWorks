#include <stdio.h>
#include <math.h>

int main() {
    int N = 0;
    double S = 0.0; // Инициализация вещественным нулем

    // 1. Запрос N с помощью while (пока N <= 0)
    while (N <= 0) {
        printf("Введите N (N > 0): ");
        scanf("%d", &N);
    }

    // 2. Вычисление суммы в цикле for
    for (int i = 1; i <= N; i++) {
        // Вычисляем (-1)^i
        double sign = (i % 2 == 0) ? 1.0 : -1.0;
        
        // Вычисляем член ряда: (-1)^i / (2i + 1)
        double term = sign / (2.0 * i + 1.0);
        
        S += term;
    }

    // 3. Вывод с 6 знаками после запятой
    printf("SUM: %.6f\n", S);

    return 0;
}