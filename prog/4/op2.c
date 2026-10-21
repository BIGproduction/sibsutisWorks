#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t n1, n2;
    float result;

    printf("Введите два значения типа uint16_t (n1 и n2):\n");
    
    if (scanf("%hu %hu", &n1, &n2) != 2) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    if (n1 + n2 == 0) {
        printf("Ошибка: деление на ноль (n1 + n2 = 0).\n");
        return 1;
    }

    result = (float)n1 / (n1 + n2);

    printf("Результат: %f\n", result);

    printf("Размер типа uint16_t: %llu байт\n", (unsigned long long)sizeof(uint16_t));
    printf("Размер типа float: %llu байт\n", (unsigned long long)sizeof(float));
    
    printf("Размер переменной n1: %llu байт\n", (unsigned long long)sizeof(n1));
    printf("Размер переменной result: %llu байт\n", (unsigned long long)sizeof(result));

    return 0;
}