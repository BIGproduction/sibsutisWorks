#include <stdio.h>

double w_to_kw(double w) {
    const double W_IN_KW = 1000.0; 
    return w / W_IN_KW;
}

int main() {
    double value;

    printf("Введите значение в Ваттах: \n");

    while (scanf("%lf", &value) == 1) {

        double result = w_to_kw(value);
        printf("%.2f Вт = %.2f кВт\n", value, result);
    }

    return 0;
}
