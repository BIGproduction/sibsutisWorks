#include <stdio.h>
#include <math.h>

int main() {
    int N;
    double S = 0.0;

    N = 0;
    while (N <= 0) {
        printf("Введите N (N > 0): ");
        scanf("%d", &N);
    }

    for (int i = 0; i <= N; i++) {
        
        double numerator = pow(-1, i); 
        double denominator = 2.0 * i + 1.0; 
        
        S = S + (numerator / denominator);
    }
    printf("SUM: %.6f\n", S);

    return 0;
}