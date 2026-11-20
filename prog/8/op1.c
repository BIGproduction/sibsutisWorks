#include <stdio.h>
#include <stdlib.h>
#include "myarrfunc.h"

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main(void) {
    int *arr = NULL;
    size_t size = 0;
    int *temp_indices = NULL;

    char cmd;

    while (1) {
        printf("\n--- меню ---\n");
        printf("a - задать размер массива\n");
        printf("b - заполнить массив\n");
        printf("c - представление массива (значения, адреса)\n");
        printf("d - [функция 1] индексы элементов > k\n");
        printf("e - [функция 2] индексы между min и max\n");
        printf("f - [функция 3] сумма элементов > k\n");
        printf("g - выход\n");
        printf("выберите пункт: ");

        if (scanf(" %c", &cmd) != 1) {
            if (feof(stdin)) {
                printf("\nEOF. Выход.\n");
                break;
            }
            clear_input_buffer();
            continue;
        }

        switch (cmd) {

            case 'a': {
                printf("введите новый размер массива: ");
                size_t new_size;
                if (scanf("%zu", &new_size) != 1 || new_size == 0) {
                    printf("некорректный размер\n");
                    clear_input_buffer();
                    break;
                }
                clear_input_buffer();

                if (arr != NULL) free(arr);
                if (temp_indices != NULL) free(temp_indices);

                arr = (int *)malloc(new_size * sizeof(int));
                temp_indices = (int *)malloc(new_size * sizeof(int));

                if (arr == NULL || temp_indices == NULL) {
                    printf("ошибка выделения памяти\n");
                    free(arr);
                    free(temp_indices);
                    return 1;
                }
                size = new_size;
                printf("массив размера %zu создан\n", size);
                break;
            }

            case 'b': {
                if (arr == NULL) {
                    printf("сначала задайте размер\n");
                    break;
                }
                printf("введите %zu целых чисел:\n", size);
                for (size_t i = 0; i < size; i++) {
                    if (scanf("%d", arr + i) != 1) {
                        printf("ошибка при вводе элемента\n");
                        clear_input_buffer();
                        break;
                    }
                }
                clear_input_buffer();
                printf("готово\n");
                break;
            }

            case 'c': {
                if (arr == NULL) {
                    printf("массив не создан\n");
                    break;
                }
                printf("индекс\tзначение\tадрес\n");
                for (size_t i = 0; i < size; i++) {
                    printf("%zu\t%d\t\t%p\n",
                           i, *(arr + i), (void *)(arr + i));
                }
                break;
            }

            case 'd': {
                if (arr == NULL) { printf("массив пуст\n"); break; }
                int k;
                printf("введите k: ");
                if (scanf("%d", &k) != 1) {
                    printf("некорректный ввод\n");
                    clear_input_buffer();
                    break;
                }
                clear_input_buffer();

                int count = find_indices_above_k(arr, size, k, temp_indices);
                if (count == -1) {
                    printf("ошибка (неверные аргументы)\n");
                } else if (count == 0) {
                    printf("элементов больше %d нет\n", k);
                } else {
                    printf("найдено %d индексов элементов > %d: ", count, k);
                    for (int i = 0; i < count; i++) {
                        printf("%d ", temp_indices[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 'e': {
                if (arr == NULL) { printf("массив пуст\n"); break; }

                int count = find_indices_between_min_max(arr, size, temp_indices);
                if (count == -1) {
                    printf("ошибка: массив слишком мал\n");
                } else if (count == 0) {
                    printf("между min и max нет элементов "
                           "(они соседние или совпадают)\n");
                } else {
                    printf("индексы элементов между min и max: ");
                    for (int i = 0; i < count; i++) {
                        printf("%d ", temp_indices[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 'f': {
                if (arr == NULL) { printf("массив пуст\n"); break; }
                int k;
                printf("введите k: ");
                if (scanf("%d", &k) != 1) {
                    printf("некорректный ввод\n");
                    clear_input_buffer();
                    break;
                }
                clear_input_buffer();

                long long sum = sum_elements_above_k(arr, size, k);
                printf("сумма элементов > %d = %lld\n", k, sum);
                break;
            }

            case 'g': {
                printf("выход\n");
                free(arr);
                free(temp_indices);
                return 0;
            }

            default:
                printf("неверный пункт '%c'\n", cmd);
                break;
        }
    }

    free(arr);
    free(temp_indices);
    return 0;
}