#include <stdio.h>
#include <math.h>

double calc(double a, double b) {
    double result = sqrt(pow(a, 2) + pow(b, 2));
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