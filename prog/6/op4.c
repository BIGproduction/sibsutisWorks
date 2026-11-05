#include <stdio.h>

int main() {
    double volume;
    double total_cost = 0.0;

    printf("введите объем хранилища ГБ: ");
    if (scanf("%lf", &volume) != 1 || volume < 0) {
        printf("ошибка, введите положительное число\n");
        return 1;
    }
    if (volume <= 10.0) {
        total_cost = volume * 1.0;
        printf("первая ступень: %.1f\n", volume, total_cost);
    } 
    else if (volume <= 60.0) {
        double cost_part1 = 10.0 * 1.0;
        double remaining_volume = volume - 10.0;
        double cost_part2 = remaining_volume * 0.8;
        
        total_cost = cost_part1 + cost_part2;
        
        printf("первая ступень: %.1f\n", cost_part1);
        printf("третя ступень: %.1f\n", remaining_volume, cost_part2);
    } 
    else {
        double cost_part1 = 10.0 * 1.0;
        double cost_part2 = 50.0 * 0.8;
        double remaining_volume = volume - 60.0;
        double cost_part3 = remaining_volume * 0.5;
        
        total_cost = cost_part1 + cost_part2 + cost_part3;
        
        printf("первая ступень: %.1f\n", cost_part1);
        printf("вторая ступень: %.1f\n", cost_part2);
        printf("третья ступень: %.1f\n", remaining_volume, cost_part3);
    }

    printf("---------------------------\n");
    printf("итого: %.1f\n", total_cost);

    return 0;
}