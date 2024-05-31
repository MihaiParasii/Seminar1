#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "helpers_funcs.h"
#include "ex1_private.h"

void bubble_sort(Array array) {
	assert(array.length > 0);

	array.array = (int *) malloc(array.length * sizeof(int));
	init_array_with_random_numbers(array);

	printf("Bubble sort, nr_of_elements: %d\n", array.length);

	for (int i = 0; i < array.length; ++i) {
		for (int j = 0; j < i; ++j) {
			if (array.array[i] < array.array[j]) {
				_swap(&array.array[i], &array.array[j]);
			}
		}
	}
	free(array.array);
}

void quick_sort(Array array) {
	assert(array.length > 0);

	array.array = (int *) malloc(array.length * sizeof(int));
	init_array_with_random_numbers(array);

	printf("Quick sort, nr_of_elements: %d\n", array.length);

	qsort(array.array, array.length, sizeof(int), _comparator_func);
	free(array.array);
}