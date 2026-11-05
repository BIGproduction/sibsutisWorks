#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num;
    
    int count1 = 0; 
    double sum1 = 0.0;
    
    int count2 = 0; 
    double sum2 = 0.0;

    printf("введите целые числа (0 для завершения):\n");

    while (1) {
        printf("число: ");
        if (scanf("%d", &num) != 1) {
            printf("ошибка ввода\n");
            break;
        }

        if (num == 0) {
            break;
        }

        int abs_num = abs(num);

        int units = abs_num % 10;
        int tens = (abs_num / 10) % 10;

        if (tens > units) {
            count1++;
            sum1 += num;
        } else if (tens < units) {
            count2++;
            sum2 += num;
        }

    }

    printf("\n--- результаты ---\n");

    if (count1 > 0) {
        printf("1) десятки > единиц:\n");
        printf("   количество: %d\n", count1);
        printf("   среднее арифметическое: %.1f\n", sum1 / count1);
    } else {
        printf("1) десятки > единиц: чисел не введено\n");
    }

    if (count2 > 0) {
        printf("2) десятки < единиц (наоборот):\n");
        printf("   количество: %d\n", count2);
        printf("   среднее арифметическое: %.1f\n", sum2 / count2);
    } else {
        printf("2) десятки < единиц: чисел не введено.\n");
    }

    return 0;
}