#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ex3_private.h"

Number _calculate_sum_of_2_numbers(Number number1, Number number2) {
	assert(number1.length);
	assert(number2.length);
	assert(number1.number);
	assert(number2.number);

	bool need_increment = false;
	Number result = {number1.length > number2.length ? number1.length : number2.length,
	                 calloc(result.length, sizeof(short))};

	for (int i = 0; i < result.length; ++i) {
		if ((number2.length > number1.length) && (i >= number1.length)) {
			result.number[i] += number2.number[i];
		} else if ((number1.length > number2.length) && (i >= number2.length)) {
			result.number[i] += number1.number[i];
		} else {
			result.number[i] += number1.number[i] + number2.number[i];
		}

		if (result.number[i] >= 10) {
			if (i == result.length - 1) {
				result.number = realloc(result.number, (result.length + 1) * sizeof(short));
				need_increment = true;
			}
			result.number[i] -= 10;
			result.number[i + 1] += 1;
		}
	}

	result.length += need_increment;

	return result;
}

void _print_num_status(const Number number, const int position) {
	assert(position);
	assert(number.length);
	assert(number.number);

	printf("Fibonacci %dth number | Number length: %d\n", position, number.length);
//	for (int i = number.length - 1; i >= 0; --i) {
//		printf("%d", number.number[i]);
//	}
}

Number _get_fibonacci_number_by_position(int position) {
	assert(position);

	Number number1 = {1, calloc(number1.length, sizeof(short))};
	Number number2 = {1, calloc(number2.length, sizeof(short))};

	number1.number[0] = 0;
	number2.number[0] = 1;

	for (int i = 0; i < position; ++i) {
		Number result = _calculate_sum_of_2_numbers(number1, number2);
//		print_num_status(result);
		number1 = number2;
		number2 = result;
	}
	return number2;
}

void print_fibonacci_number_by_position(Array position) {
	assert(position.length);

	_print_num_status(_get_fibonacci_number_by_position(position.length), position.length);
}