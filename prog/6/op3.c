#include <stdio.h>
#include <math.h>

int main(void) {
    int num;
    
    int count1 = 0; 
    double sum1 = 0.0;
    
    int count2 = 0; 
    double sum2 = 0.0;

    printf("Введите целые числа (0 для завершения):\n");

    while (1) {
        printf("Число: ");
        if (scanf("%d", &num) != 1) {
            printf("Ошибка ввода. Завершение.\n");
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

    printf("\n--- Результаты ---\n");

    if (count1 > 0) {
        printf("1) Десятки > Единиц:\n");
        printf("   Количество: %d\n", count1);
        printf("   Среднее арифметическое: %.2f\n", sum1 / count1);
    } else {
        printf("1) Десятки > Единиц: чисел не введено.\n");
    }

    if (count2 > 0) {
        printf("2) Десятки < Единиц (наоборот):\n");
        printf("   Количество: %d\n", count2);
        printf("   Среднее арифметическое: %.2f\n", sum2 / count2);
    } else {
        printf("2) Десятки < Единиц: чисел не введено.\n");
    }

    return 0;
}