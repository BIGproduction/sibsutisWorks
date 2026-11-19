#ifndef MYARRFUNC_H
#define MYARRFUNC_H

#include <stddef.h>

int find_indices_above_k(int *arr, size_t n, int k, int *indices);
int find_indices_between_min_max(int *arr, size_t n, int *indices);
long long sum_elements_above_k(int *arr, size_t n, int k);

#endif