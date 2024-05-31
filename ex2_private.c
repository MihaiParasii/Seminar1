#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ex2_private.h"
#include "helpers_funcs.h"

void _linear_search(Array array) {

	assert(array.length);

	array.array = malloc(array.length * sizeof(int));
	init_array_with_increasing_numbers(array);
	int target_element = array.length * 0.75;

	printf("Linear search, nr_of_elements: %d\n", array.length);

	for (int i = 0; i < 10000; ++i) {
		for (int j = 0; j < array.length; ++j) {
			if (array.array[j] == target_element) {
				break;
			}
		}
	}

	free(array.array);
}

void _binary_search(Array array) {
	assert(array.length > 0);

	array.array = malloc(array.length * sizeof(int));
	init_array_with_increasing_numbers(array);
	int target_element = array.length * 0.75;

	printf("Binary search, nr_of_elements: %d\n", array.length);

	for (int i = 0; i < 10000; ++i) {
		bsearch(&target_element, array.array, array.length, sizeof(int), _comparator_func);
	}

	free(array.array);
}