#include <stdio.h>

void sort_three(double *a, double *b, double *c) {
    double temp;

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c) {
        temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
}

int main(void) {
    double x = 5.5, y = 2.1, z = 8.4;

    printf("исходные значения:\n");
    printf("x = %.1f, y = %.1f, z = %.1f\n\n", x, y, z);

    sort_three(&x, &y, &z);

    printf("отсортированные значения по возрастанию:\n");
    printf("x = %.1f, y = %.1f, z = %.1f\n", x, y, z);

    return 0;
}