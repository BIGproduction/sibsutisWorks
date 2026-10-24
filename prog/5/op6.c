#include <stdio.h>

int main() {
    int num1;
    int num2;

    printf("Ведите любые числа для сложения: \n");
    scanf("%d %d", num1, num2);

    int result = (num1 + num2);

    printf("ты посчитал: ", result);

    return 0;
}