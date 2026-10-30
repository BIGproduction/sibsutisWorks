#include <stdio.h>

double stepen(double x) {
    double result = 1.0;
    int steps = (int)x;

    for (int i = 0; i < steps; i++) {
        result *= 2.0;
    }
    return result;
}

int main() {
    double A = 0.0;
    double B = 5.0;
    double H = 1.0;

    double x;

    printf("Показательная функция 2^x \n");

    for (x = A; x <= B + H / 2.0; x += H) {
        double y = stepen(x);

        printf("%5.1f | %10.2f \n", x, y);
    }
    return 0;
}