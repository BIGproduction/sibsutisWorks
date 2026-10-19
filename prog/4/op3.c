#include <stdio.h>

const int MINUTES_IN_DEGREE = 60;

int main() {
    int total_minutes; // Базовая единица - минуты
    int degrees;
    int remaining_minutes;

    printf("Программа конвертации углов.\n");
    printf("Введите величину в минутах (для выхода введите 0 или отрицательное число, либо Ctrl+D):\n");

    // Организуем цикл while для многократного ввода
    // scanf возвращает количество успешно считанных элементов. 
    // Если ввод некорректен или достигнут EOF, цикл прервется.
    while (scanf("%d", &total_minutes) == 1 && total_minutes > 0) {
        
        /* 
         * Вычисляем градусы.
         * При целочисленном делении дробная часть отбрасывается, 
         * так как тип int не может хранить дробные значения. 
         * Это аналог математического "целого деления с остатком".
         */
        degrees = total_minutes / MINUTES_IN_DEGREE;
        
        // Вычисляем остаток минут
        remaining_minutes = total_minutes % MINUTES_IN_DEGREE;

        // Выводим результат в формате: [Градусы] град [Минуты] мин
        printf("%d град %d мин\n", degrees, remaining_minutes);
    }

    printf("Программа завершена.\n");
    return 0;
}