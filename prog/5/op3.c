#include <stdio.h>
#include <math.h>

int main() {
    int N;
    double S = 0.0;

    // 1. Запрос N с помощью цикла while (пока N <= 0)
    N = 0;
    while (N <= 0) {
        printf("Введите N (N > 0): ");
        scanf("%d", &N);
    }

    // 2. Вычисление суммы с помощью цикла for (от 1 до N)
    for (int i = 1; i <= N; i++) {
        
        // (-1)^i можно вычислить через pow. 
        // Если i четное — будет 1, если нечетное — -1.
        double numerator = pow(-1, i); 
        
        // Знаменатель: 2*i + 1
        double denominator = 2.0 * i + 1.0; 
        
        // Накапливаем сумму
        S = S + (numerator / denominator);
    }

    // 3. Вывод с 6 знаками после запятой
    printf("SUM: %.6f\n", S);

    return 0;
}