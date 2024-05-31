#ifndef _HELPERS_FUNCS_H_
#define _HELPERS_FUNCS_H_

#include "struct.h"

void print_array(Array array);

void init_array_with_random_numbers(Array array);

void _swap(int *first, int *second);

int _comparator_func(const void *a, const void *b);

void print_benchmark(void function(Array), Array array);

void init_array_with_increasing_numbers(Array array);

#endif //_HELPERS_FUNCS_H_
