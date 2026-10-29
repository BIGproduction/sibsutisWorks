#include <stdio.h>

int main() {
    double arr[8];
    double sum = 0.0;

    arr[0] = 0.0;
    arr[1] = 1.0;

    for (int i = 2; i < 8; i++) {
        arr[i] = arr[i - 1] + 2.0 * arr[i - 2];
    }

    printf("Исходный массив: ");
    for (int i = 0; i < 8; i++) {
        printf("%.1f ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < 8; i++) {
        sum += arr[i];
    }
    printf("Сумма элементов массива = %.1f\n", sum);

    return 0;
}