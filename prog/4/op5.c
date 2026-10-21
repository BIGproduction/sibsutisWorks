#include <stdio.h>

double w_to_kw(double w) {

    const double WATTS_IN_KILOWATT = 1000.0; 
    
    return w / WATTS_IN_KILOWATT;
}

int main() {
    double value;

    printf("Конвертер Ватт -> Киловатт \n");
    printf("Введите значение в Ваттах \n");

    while (scanf("%lf", &value) == 1) {

        double result = w_to_kw(value);
        printf("%.2f Вт = %.2f кВт\n", value, result);
    }

    printf("Программа завершена \n");
    return 0;
}