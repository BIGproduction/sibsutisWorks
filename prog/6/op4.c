#include <stdio.h>

int main(void) {
    double volume;
    double total_cost = 0.0;
    
    double cost1 = 0.0, cost2 = 0.0, cost3 = 0.0;

    printf("Введите объем хранилища в ГБ: ");
    if (scanf("%lf", &volume) != 1) {
        printf("Ошибка ввода данных.\n");
        return 1;
    }

    if (volume < 0) {
        printf("Объем не может быть отрицательным.\n");
        return 1;
    }

    if (volume <= 10.0) {

        cost1 = volume * 1.0;
        total_cost = cost1;
        
    } else if (volume <= 60.0) {

        cost1 = 10.0 * 1.0;
        cost2 = (volume - 10.0) * 0.8;
        total_cost = cost1 + cost2;
        
    } else {
        cost1 = 10.0 * 1.0;
        cost2 = 50.0 * 0.8;
        cost3 = (volume - 60.0) * 0.5;
        total_cost = cost1 + cost2 + cost3;
    }

    printf("\n--- Расчет стоимости хранения ---\n");
    printf("Исходный объем: %.2f ГБ\n\n", volume);
    
    printf("Разбивка по ступеням:\n");
    
    if (volume > 0) {
        if (cost1 > 0) {
            double vol1 = (volume < 10.0) ? volume : 10.0;
            printf(" - %.2f ГБ по тарифу 1.0 руб/ГБ = %.2f руб.\n", vol1, cost1);
        }
        if (cost2 > 0) {
            double vol2 = (volume < 60.0) ? (volume - 10.0) : 50.0;
            printf(" - %.2f ГБ по тарифу 0.8 руб/ГБ = %.2f руб.\n", vol2, cost2);
        }
        if (cost3 > 0) {
            double vol3 = volume - 60.0;
            printf(" - %.2f ГБ по тарифу 0.5 руб/ГБ = %.2f руб.\n", vol3, cost3);
        }
    }
    printf("\nИТОГОВАЯ СТОИМОСТЬ: %.2f руб.\n", total_cost);

    return 0;
}