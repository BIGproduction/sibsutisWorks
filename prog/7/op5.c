#include <stdio.h>
#include <stdbool.h>

bool is_prime_iterative(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_prime_recursive_helper(int n, int divisor) {

    if (divisor * divisor > n) {
        return true;
    }
    if (n % divisor == 0) {
        return false;
    }

    return is_prime_recursive_helper(n, divisor + 1);
}

bool is_prime_recursive(int n) {
    if (n <= 1) return false;
    return is_prime_recursive_helper(n, 2);
}

int main(void) {
    int number;
    
    printf("введите целое число для проверки на простоту: ");
    
    if (scanf("%d", &number) != 1) {
        printf("ошибка ввода\n");
        return 1;
    }

    bool res_iter = is_prime_iterative(number);
    bool res_rec  = is_prime_recursive(number);

    printf("итеративный метод: %s\n", res_iter ? "простое" : "составное");
    printf("рекурсивный метод: %s\n", res_rec ? "простое" : "составное");

    return 0;
}