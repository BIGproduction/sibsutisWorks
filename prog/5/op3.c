#include <stdio.h>
#include <math.h>

int main() {
    int N;
    double S = 0.0;
    N = 0;
    
    while (N <= 0) {
        printf("Введите количество слагаемых N (N > 0): ");
        scanf("%d", &N);
    }

    for (int i = 1; i <= N; i++) {
        
        double term = 1.0 / i; 
        S = S + term;
    }

    printf("Сумма S = %.6f\n", S);

    return 0;
}