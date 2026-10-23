#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t n1, n2;
    float result;

    printf("Введите два значения типа uint16_t (n1 и n2):\n");
    
    scanf("%hu %hu", &n1, &n2);

    result = (float)n1 / (n1 + n2);
    printf("Результат: %f\n", result);

    printf("Размер типа uint16_t: %llu байт\n", (unsigned long long)sizeof(uint16_t));
    printf("Размер типа float: %llu байт\n", (unsigned long long)sizeof(float));

    return 0;
}