#include <stdio.h>

int main() {
    double volume;      // Объем хранилища (в ГБ)
    double total_cost = 0.0;

    // 1. Запрос данных у пользователя
    printf("Введите объем хранилища (в ГБ): ");
    // Проверяем, что ввод корректный
    if (scanf("%lf", &volume) != 1 || volume < 0) {
        printf("Ошибка: введите положительное число.\n");
        return 1;
    }

    printf("\n--- Детализация расчета ---\n");

    // 2. Вычисление с помощью цепочки if...else if...else согласно тарифной сетке
    // Тариф: 1/ГБ до 10ГБ, 0.8/ГБ от 10 до 60ГБ, 0.5/ГБ свыше
    
    if (volume <= 10.0) {
        // Тариф 1: до 10 ГБ (включительно)
        total_cost = volume * 1.0;
        printf("Тариф: 1.0 за ГБ (до 10 ГБ)\n");
        printf("Начислено за %.2f ГБ: %.2f\n", volume, total_cost);
    } 
    else if (volume <= 60.0) {
        // Тариф 2: от 10 до 60 ГБ
        // Первые 10 ГБ стоят по 1.0
        double cost_part1 = 10.0 * 1.0;
        // Остаток объема (свыше 10 ГБ) стоит по 0.8
        double remaining_volume = volume - 10.0;
        double cost_part2 = remaining_volume * 0.8;
        
        total_cost = cost_part1 + cost_part2;
        
        printf("Тариф: 1.0 за ГБ (первые 10 ГБ) + 0.8 за ГБ (остаток)\n");
        printf("Начислено за 10 ГБ: %.2f\n", cost_part1);
        printf("Начислено за %.2f ГБ: %.2f\n", remaining_volume, cost_part2);
    } 
    else {
        double cost_part1 = 10.0 * 1.0;

        double cost_part2 = 50.0 * 0.8;

        double remaining_volume = volume - 60.0;
        double cost_part3 = remaining_volume * 0.5;
        
        total_cost = cost_part1 + cost_part2 + cost_part3;
        
        printf("Тариф: 1.0 за ГБ (первые 10 ГБ) + 0.8 за ГБ (следующие 50 ГБ) + 0.5 за ГБ (остаток)\n");
        printf("Начислено за 10 ГБ: %.2f\n", cost_part1);
        printf("Начислено за 50 ГБ: %.2f\n", cost_part2);
        printf("Начислено за %.2f ГБ: %.2f\n", remaining_volume, cost_part3);
    }

    // 3. Вывод итоговой суммы
    printf("---------------------------\n");
    printf("ИТОГОВАЯ СУММА: %.2f\n", total_cost);

    return 0;
}