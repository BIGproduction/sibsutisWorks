#include <stdio.h>
#include <stdlib.h>

void print_binary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }
    int started = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (bit) started = 1;
        if (started) printf("%d", bit);
    }
}

int main(void) {
    int choice;
    char input[100];

    while (1) {
        printf("\n--- Меню ---\n");
        printf("1. dec -> hex\n");
        printf("2. dec -> oct\n");
        printf("3. dec -> bin\n");
        printf("4. hex -> dec\n");
        printf("0. Выход\n");
        printf("Выберите пункт: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Ошибка ввода!\n");
            continue;
        }

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1: {
                int num;
                printf("Введите десятичное число: ");
                scanf("%d", &num);
                printf("Результат: %X\n", num);
                break;
            }
            case 2: {
                int num;
                printf("Введите десятичное число: ");
                scanf("%d", &num);
                printf("Результат: %o\n", num);
                break;
            }
            case 3: {
                int num;
                printf("Введите десятичное число: ");
                scanf("%d", &num);
                printf("Результат: ");
                print_binary(num);
                printf("\n");
                break;
            }
            case 4: {
                printf("Введите шестнадцатеричное число (с 0x или без): ");
                scanf("%s", input);
                int num = (int)strtol(input, NULL, 16);
                printf("Результат: %d\n", num);
                break;
            }
            default: {
                printf("Неверный номер пункта. Повторите ввод.\n");
                continue;
            }
        }
    }

    return 0;
}