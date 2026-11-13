#include <stdio.h>
#include <stdbool.h>

bool reverse_iter(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool reverse_rec(int n, int divisor) {

    if (divisor * divisor > n) {
        return true;
    }
    if (n % divisor == 0) {
        return false;
    }

    return reverse_rec(n, divisor + 1);
}

bool reverse_rec_main(int n) {
    if (n <= 1) return false;
    return reverse_rec(n, 2);
}

int main(void) {
    int num;
    
    printf("введите целое число для проверки на простоту: ");
    
    if (scanf("%d", &num) != 1) {
        printf("ошибка ввода\n");
        return 1;
    }

    bool res_iter = reverse_iter(num);
    bool res_rec  = reverse_rec_main(num);

    printf("итеративный метод: %s\n", res_iter ? "простое" : "составное");
    printf("рекурсивный метод: %s\n", res_rec ? "простое" : "составное");

    return 0;
}