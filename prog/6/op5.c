#include <stdio.h>

double coren(double n) {
    if (n < 0) return -1.0;
    if (n == 0) return 0;
    
    double x = n;
    for (int i = 0; i < 20; i++) {
        x = 0.5 * (x + n / x);
    }
    return x;
}

double stepen(double x) {
    return x * x;
}

double calc(double a, double b) {
    double sum_of_squares = stepen(a) + stepen(b);
    
    double result = coren(sum_of_squares);
    return result;
}

int main() {
    double a, b;

    printf("Введите пары чисел a и b: \n");

    while (scanf("%lf %lf", &a, &b) == 2) {
        double res = calc(a, b);

        printf("результат calc(%.1f, %.1f) = %.4f\n", a, b, res);
    }
    return 0;
}