#include <stdio.h>

int main() {
    int N;
    double S = 0.0;

    N = 0;
    while (N <= 0) {
        printf("Введите N (N > 0): ");
        scanf("%d", &N);
    }

    for (int i = 1; i <= N; i++) {

        double numerator = 1.0;
        for (int j = 0; j < i; j++) {
            numerator *= -1.0;
        }
        
        double denominator = 2.0 * i + 1.0;

        S = S + (numerator / denominator);
    }
    printf("SUM: %.6f\n", S);

    return 0;
}