#include "myarrfunc.h"
#include <stddef.h>

// Функция 1: Индексы элементов > k
int find_indices_above_k(int *arr, size_t n, int k, int *indices) {
    if (arr == NULL || indices == NULL) return -1;
    
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        // Использование указательной арифметики: *(arr + i)
        if (*(arr + i) > k) {
            *(indices + count) = (int)i; // Сохраняем индекс
            count++;
        }
    }
    return count;
}

// Функция 2: Индексы элементов между min и max
int find_indices_between_min_max(int *arr, size_t n, int *indices) {
    if (arr == NULL || indices == NULL || n < 2) return -1;

    int min_val = *arr;
    int max_val = *arr;
    size_t min_idx = 0;
    size_t max_idx = 0;

    // Поиск минимума и максимума
    for (size_t i = 1; i < n; i++) {
        if (*(arr + i) < min_val) {
            min_val = *(arr + i);
            min_idx = i;
        }
        if (*(arr + i) > max_val) {
            max_val = *(arr + i);
            max_idx = i;
        }
    }

    // Определение границ (кто левее, а кто правее)
    size_t start = (min_idx < max_idx) ? min_idx : max_idx;
    size_t end = (min_idx < max_idx) ? max_idx : min_idx;

    // Если между ними нет элементов
    if (end - start <= 1) return 0;

    int count = 0;
    // Сбор индексов
    for (size_t i = start + 1; i < end; i++) {
        *(indices + count) = (int)i;
        count++;
    }
    return count;
}

// Функция 3: Сумма элементов > k
long long sum_elements_above_k(int *arr, size_t n, int k) {
    if (arr == NULL) return 0;
    
    long long sum = 0;
    for (size_t i = 0; i < n; i++) {
        if (*(arr + i) > k) {
            sum += *(arr + i);
        }
    }
    return sum;
}