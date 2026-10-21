#include <stdio.h>

int main() {
    int N;
    int count = 1;
    int current_val = 0;

    printf("Введите количество элементов N: ");
    
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Ошибка: введите положительное целое число.\n");
        return 1;
    }

    printf("Последовательность: ");

    while (count <= N) {
        printf("%d ", current_val);

        current_val += 60; 
        count++; 
    }
    printf("\n");

    return 0;
}