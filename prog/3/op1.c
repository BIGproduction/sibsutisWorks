#include<string.h>
#include<stdio.h>

int main(void) {
    char str[20];

    strcpy(str, "SibSUITS");
    size_t size = sizeof(str);
    size_t len = strlen(str);
    size_t bytes = size - (len + 1);

    printf("SIZEOF: %zu\n", size);
    printf("STRLEN: %zu\n", len);
    printf("FREE_BYTES %zu\n", bytes);

    printf("\n--- Повтор со строкой 'СибСУТИС' ---\n\n");

    strcpy(str, "СибСУИТС");
    size_t size_ru = sizeof(str);
    size_t len_ru = strlen(str);
    size_t bytes_ru = size_ru - (len_ru + 1);

    printf("SIZEOF: %zu\n", size_ru);
    printf("STRLEN: %zu\n", len_ru);
    printf("FREE_BYTES %zu\n", bytes_ru);

    return 0;
}