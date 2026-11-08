#include <stdio.h>

int main(void)
{
    int x = 10;
    int *p;
    p = &x;
    
    // Создаем буфер (строку), куда запишем адрес
    char buffer[32];
    
    // Записываем адрес в строку buffer вместо вывода на экран
    sprintf(buffer, "%p", (void*)p);
    
    // Выводим строку, пропуская первые 2 символа (то есть "0x")
    printf("%s\n", buffer + 2);
    
    return 0;
}