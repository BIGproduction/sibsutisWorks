#include <stdio.h>

double my_sqrt(double n) {
    if (n < 0) return -1.0;
    if (n == 0) return 0;
    
    double x = n;
    for (int i = 0; i < 20; i++) {
        x = 0.5 * (x + n / x);
    }
    return x;
}

double my_pow_2(double x) {
    return x * x;
}

double calc(double a, double b) {
    double sum_of_squares = my_pow_2(a) + my_pow_2(b);
    
    double result = my_sqrt(sum_of_squares);
    return result;
}

int main() {
    double a, b;

    printf("Введите пары чисел a и b (для выхода введите любой символ вместо числа):\n");

    while (scanf("%lf %lf", &a, &b) == 2) {
        double res = calc(a, b);

        printf("результат calc(%.1f, %.1f) = %.4f\n", a, b, res);
    }
    return 0;
}