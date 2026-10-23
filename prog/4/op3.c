#include <stdio.h>

int main() {
    int N;
    int count = 1;
    int current_val = 0;

    printf("Введите количество элементов N: ");

    scanf("%d", &N);

    printf("Последовательность: ");

    while (count <= N) {
        printf("%d ", current_val);

        current_val += 60; 
        count++; 
    }
    printf("\n");

    return 0;
}

/* i++ сначала возвращает значение, потом увеличивает

   ++i сначала увеличивает, потом возвращает значение 
   важно, чтобы не нарушить логику кода, и не увеличивало значение до первой проверки */