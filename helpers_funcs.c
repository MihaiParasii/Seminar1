#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "helpers_funcs.h"

int _comparator_func(const void *a, const void *b) {
	return *(int *) a - *(int *) b;
}

void _swap(int *first, int *second) {
	assert(first);
	assert(second);

	int temp = *first;
	*first = *second;
	*second = temp;
}

void init_array_with_random_numbers(Array array) {
	assert(array.array);
	assert(array.length > 0);

	srand(time(NULL));
	for (int i = 0; i < array.length; ++i) {
		array.array[i] = rand() % 1000;
	}
}

void print_array(Array array) {
	assert(array.array);
	assert(array.length > 0);

	for (int i = 0; i < array.length; ++i) {
		printf("%d ", array.array[i]);
	}
	printf("\n");
}

void print_benchmark(void function(Array), Array array) {
	double start_time = clock();
	function(array);
	double end_time = clock();
	printf("Time: %f\n", (end_time - start_time) / CLOCKS_PER_SEC);
	printf("\n");
}

void init_array_with_increasing_numbers(Array array) {
	assert(array.array);
    assert(array.length > 0);

    for (int i = 0; i < array.length; ++i) {
        array.array[i] = i;
    }
}