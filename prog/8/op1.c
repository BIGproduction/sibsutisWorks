#include <stdio.h>
#include <stdlib.h>
#include "myarrfunc.h"

#define MAX_SIZE 1000

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main(void) {
    int arr[MAX_SIZE];
    int temp_indices[MAX_SIZE];
    size_t size = 0;
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
            if (feof(stdin)) { printf("\nEOF. выход.\n"); break; }
            clear_input_buffer();
            continue;
        }

        switch (cmd) {

            case 'a': {
                printf("введите размер массива (1..%d): ", MAX_SIZE);
                size_t new_size;
                if (scanf("%zu", &new_size) != 1 || new_size == 0) {
                    printf("некорректный размер.\n");
                    clear_input_buffer();
                    break;
                }
                clear_input_buffer();

                if (new_size > MAX_SIZE) {
                    printf("слишком большой размер (макс %d).\n", MAX_SIZE);
                    break;
                }
                size = new_size;
                printf("размер массива = %zu.\n", size);
                break;
            }

            case 'b': {
                if (size == 0) {
                    printf("сначала задайте размер (пункт a).\n");
                    break;
                }
                printf("введите %zu целых чисел:\n", size);
                for (size_t i = 0; i < size; i++) {
                    if (scanf("%d", arr + i) != 1) {
                        printf("ошибка при вводе элемента.\n");
                        clear_input_buffer();
                        break;
                    }
                }
                clear_input_buffer();
                printf("готово.\n");
                break;
            }

            case 'c': {
                if (size == 0) { printf("массив не создан.\n"); break; }
                printf("индекс\tзначение\tадрес\n");
                for (size_t i = 0; i < size; i++) {
                    printf("%zu\t%d\t\t%p\n",
                           i, *(arr + i), (void *)(arr + i));
                }
                break;
            }

            case 'd': {
                if (size == 0) { printf("массив пуст.\n"); break; }
                int k;
                printf("введите k: ");
                if (scanf("%d", &k) != 1) { clear_input_buffer(); break; }
                clear_input_buffer();

                int count = find_indices_above_k(arr, size, k, temp_indices);
                if (count == -1) {
                    printf("ошибка (неверные аргументы).\n");
                } else if (count == 0) {
                    printf("элементов больше %d нет.\n", k);
                } else {
                    printf("найдено %d индексов > %d: ", count, k);
                    for (int i = 0; i < count; i++) printf("%d ", temp_indices[i]);
                    printf("\n");
                }
                break;
            }

            case 'e': {
                if (size == 0) { printf("массив пуст.\n"); break; }

                int count = find_indices_between_min_max(arr, size, temp_indices);
                if (count == -1) {
                    printf("ошибка: массив слишком мал.\n");
                } else if (count == 0) {
                    printf("между min и max нет элементов.\n");
                } else {
                    printf("индексы между min и max: ");
                    for (int i = 0; i < count; i++) printf("%d ", temp_indices[i]);
                    printf("\n");
                }
                break;
            }

            case 'f': {
                if (size == 0) { printf("массив пуст.\n"); break; }
                int k;
                printf("введите k: ");
                if (scanf("%d", &k) != 1) { clear_input_buffer(); break; }
                clear_input_buffer();

                long long sum = sum_elements_above_k(arr, size, k);
                printf("сумма элементов > %d = %lld\n", k, sum);
                break;
            }

            case 'g':
                printf("выход.\n");
                return 0;

            default:
                printf("неверный пункт '%c'.\n", cmd);
                break;
        }
    }
    return 0;
}
