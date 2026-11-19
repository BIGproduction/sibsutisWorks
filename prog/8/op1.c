#include <stdio.h>
#include <stdlib.h>
#include "myarrfunc.h"

// Очистка буфера ввода для предотвращения зацикливания при некорректном вводе
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int *arr = NULL;
    size_t size = 0;
    int choice;
    int *temp_indices = NULL;

    while (1) {
        printf("\n--- МЕНЮ ---\n");
        printf("a - Задать размер массива\n");
        printf("b - Заполнить массив\n");
        printf("c - Представление массива (значения, адреса)\n");
        printf("d - [Функция 1] (Индексы элементов > k)\n");
        printf("e - [Функция 2] (Индексы между min и max)\n");
        printf("f - [Функция 3] (Сумма элементов > k)\n");
        printf("g - Выход\n");
        printf("Выберите пункт: ");

        if (scanf("%d", &choice) != 1) { // Проверка на корректность ввода
            if (feof(stdin)) break; // Обработка Ctrl+D
            printf("Ошибка ввода. Попробуйте снова.\n");
            clear_input_buffer();
            continue;
        }
        // Приведение int к char для switch (чтобы совпадало с пунктами меню)
        char cmd = (char)choice;

        switch (cmd) {
            case 'a': {
                printf("Введите новый размер массива: ");
                size_t new_size;
                if (scanf("%zu", &new_size) != 1 || new_size == 0) {
                    printf("Некорректный размер.\n");
                    clear_input_buffer();
                    break;
                }
                // Освобождаем старую память, если была
                if (arr != NULL) free(arr);
                if (temp_indices != NULL) free(temp_indices);

                arr = (int*)malloc(new_size * sizeof(int));
                temp_indices = (int*)malloc(new_size * sizeof(int)); // Буфер для индексов
                
                if (arr == NULL || temp_indices == NULL) {
                    printf("Ошибка выделения памяти.\n");
                    exit(1);
                }
                size = new_size;
                printf("Массив размера %zu создан (память выделена).\n", size);
                break;
            }

            case 'b': {
                if (arr == NULL) {
                    printf("Сначала задайте размер (пункт a).\n");
                    break;
                }
                printf("Введите %zu целых чисел:\n", size);
                for (size_t i = 0; i < size; i++) {
                    if (scanf("%d", arr + i) != 1) {
                        printf("Ошибка при вводе элемента.\n");
                        clear_input_buffer();
                        break;
                    }
                }
                printf("Массив заполнен.\n");
                break;
            }

            case 'c': {
                if (arr == NULL) {
                    printf("Массив не создан.\n");
                    break;
                }
                printf("Значение\tАдрес\n");
                for (size_t i = 0; i < size; i++) {
                    // Вывод значения и адреса
                    printf("%d\t\t%p\n", *(arr + i), (void*)(arr + i));
                }
                break;
            }

            case 'd': { // Функция 1
                if (arr == NULL) { printf("Массив пуст.\n"); break; }
                int k;
                printf("Введите число k: ");
                if (scanf("%d", &k) != 1) { clear_input_buffer(); break; }
                
                int count = find_indices_above_k(arr, size, k, temp_indices);
                
                if (count == 0) {
                    printf("Элементов больше %d нет.\n", k);
                } else {
                    printf("Индексы элементов > %d: ", k);
                    for (int i = 0; i < count; i++) {
                        printf("%d ", temp_indices[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 'e': { // Функция 2
                if (arr == NULL) { printf("Массив пуст.\n"); break; }
                
                int count = find_indices_between_min_max(arr, size, temp_indices);
                
                if (count == -1) {
                    printf("Ошибка или массив слишком мал.\n");
                } else if (count == 0) {
                    printf("Между min и max нет элементов (они соседние или совпадают).\n");
                } else {
                    printf("Индексы элементов между min и max: ");
                    for (int i = 0; i < count; i++) {
                        printf("%d ", temp_indices[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 'f': { // Функция 3
                if (arr == NULL) { printf("Массив пуст.\n"); break; }
                int k;
                printf("Введите число k: ");
                if (scanf("%d", &k) != 1) { clear_input_buffer(); break; }
                
                long long sum = sum_elements_above_k(arr, size, k);
                printf("Сумма элементов > %d равна: %lld\n", k, sum);
                break;
            }

            case 'g': {
                printf("Выход из программы.\n");
                if (arr) free(arr);
                if (temp_indices) free(temp_indices);
                return 0;
            }

            default:
                printf("Неверный пункт меню.\n");
                break;
        }
    }

    if (arr) free(arr);
    if (temp_indices) free(temp_indices);
    return 0;
}