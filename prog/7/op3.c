#include <stdio.h>

double cube_of_sum(double a, double b) {
    double sum = a + b;

    return sum * sum * sum; 
}

int main(void) {
    double a, b;

    printf("Введите пары чисел (Ctrl+D для выхода):\n");
    
    while (scanf("%lf %lf", &a, &b) == 2) {
        double result = cube_of_sum(a, b);
        
        printf("Куб суммы (%.2f + %.2f) = %.4f\n", a, b, result);
    }

    if (!feof(stdin)) {
        printf("Ошибка ввода: ожидались два числа типа double.\n");
    }

    return 0;
}