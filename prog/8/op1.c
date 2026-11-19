#include <stdio.h>
#include <stdlib.h>
#include "myarrfunc.h"

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
        printf("\n--- меню ---\n");
        printf("a - задать размер массива\n");
        printf("b - заполнить массив\n");
        printf("c - представление массива (значения, адреса)\n");
        printf("d - [функция 1] (индексы элементов > k)\n");
        printf("e - [функция 2] (индексы между min и max)\n");
        printf("f - [функция 3] (сумма элементов > k)\n");
        printf("g - выход\n");
        printf("выберите пункт: ");

        if (scanf("%d", &choice) != 1) {
            if (feof(stdin)) break;
            printf("ошибка ввода\n");
            clear_input_buffer();
            continue;
        }

        char cmd = (char)choice;

        switch (cmd) {
            case 'a': {
                printf("введите новый размер массива: ");
                size_t new_size;
                if (scanf("%zu", &new_size) != 1 || new_size == 0) {
                    printf("некорректный размер\n");
                    clear_input_buffer();
                    break;
                }
                if (arr != NULL) free(arr);
                if (temp_indices != NULL) free(temp_indices);

                arr = (int*)malloc(new_size * sizeof(int));
                temp_indices = (int*)malloc(new_size * sizeof(int));
                
                if (arr == NULL || temp_indices == NULL) {
                    printf("ошибка выделения памяти\n");
                    exit(1);
                }
                size = new_size;
                printf("массив размера %zu создан\n", size);
                break;
            }

            case 'b': {
                if (arr == NULL) {
                    printf("сначала задайте размер (пункт a)\n");
                    break;
                }
                printf("Введите %zu целых чисел:\n", size);
                for (size_t i = 0; i < size; i++) {
                    if (scanf("%d", arr + i) != 1) {
                        printf("ошибка при вводе элемента\n");
                        clear_input_buffer();
                        break;
                    }
                }
                printf("массив заполнен\n");
                break;
            }

            case 'c': {
                if (arr == NULL) {
                    printf("массив не создан\n");
                    break;
                }
                printf("значение\tадрес\n");
                for (size_t i = 0; i < size; i++) {
                    printf("%d\t\t%p\n", *(arr + i), (void*)(arr + i));
                }
                break;
            }

            case 'd': { // функция 1
                if (arr == NULL) { printf("массив пуст\n"); break; }
                int k;
                printf("введите число k: ");
                if (scanf("%d", &k) != 1) { clear_input_buffer(); break; }
                
                int count = find_indices_above_k(arr, size, k, temp_indices);
                
                if (count == 0) {
                    printf("элементов больше %d нет\n", k);
                } else {
                    printf("индексы элементов > %d: ", k);
                    for (int i = 0; i < count; i++) {
                        printf("%d ", temp_indices[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 'e': { // функция 2
                if (arr == NULL) { printf("массив пуст\n"); break; }
                
                int count = find_indices_between_min_max(arr, size, temp_indices);
                
                if (count == -1) {
                    printf("ошибка или массив слишком мал\n");
                } else if (count == 0) {
                    printf("между min и max нет элементов\n");
                } else {
                    printf("Индексы элементов между min и max: ");
                    for (int i = 0; i < count; i++) {
                        printf("%d ", temp_indices[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 'f': { // функция 3
                if (arr == NULL) { printf("массив пуст\n"); break; }
                int k;
                printf("введите число k: ");
                if (scanf("%d", &k) != 1) { clear_input_buffer(); break; }
                
                long long sum = sum_elements_above_k(arr, size, k);
                printf("сумма элементов > %d равна: %lld\n", k, sum);
                break;
            }

            case 'g': {
                printf("выход из программы\n");
                if (arr) free(arr);
                if (temp_indices) free(temp_indices);
                return 0;
            }

            default:
                printf("неверный пункт меню\n");
                break;
        }
    }

    if (arr) free(arr);
    if (temp_indices) free(temp_indices);
    return 0;
}