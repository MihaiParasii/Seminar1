#include <stdlib.h>
#include "funcs.h"
#include "helpers_funcs.h"
#include "ex1_private.h"
#include "ex2_private.h"
#include "ex3_private.h"

void ex1() {
	Array array_with_length = {
		4, malloc(sizeof(int) * array_with_length.length)
	};
	array_with_length.array[0] = 100;
	array_with_length.array[1] = 1000;
	array_with_length.array[2] = 10000;
	array_with_length.array[3] = 100000;

	for (int i = 0; i < array_with_length.length; ++i) {
		Array current_array = {array_with_length.array[i], NULL};
		print_benchmark(bubble_sort, current_array);
		print_benchmark(quick_sort, current_array);
	}
	free(array_with_length.array);
}

void ex2() {
	Array array_with_length = {
		4, malloc(sizeof(int) * array_with_length.length)
	};

	array_with_length.array[0] = 100;
	array_with_length.array[1] = 1000;
	array_with_length.array[2] = 10000;
	array_with_length.array[3] = 100000;

	for (int i = 0; i < array_with_length.length; ++i) {
		Array current_array = {array_with_length.array[i], NULL};
		print_benchmark(_linear_search, current_array);
		print_benchmark(_binary_search, current_array);
	}
	free(array_with_length.array);
}

void ex3() {
	Array positions = {
		6, malloc(sizeof(int) * positions.length)
	};
	positions.array[0] = 50;
	positions.array[1] = 100;
	positions.array[2] = 1000;
	positions.array[3] = 10000;
	positions.array[4] = 100000;
	positions.array[5] = 300000;

	for (int i = 0; i < positions.length; ++i) {
		Array current_array = {positions.array[i], NULL};
		print_benchmark(print_fibonacci_number_by_position, current_array);
	}
	free(positions.array);
}