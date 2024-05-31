#include "funcs.h"
#include "includes.h"

ListOptionsStruct *create_struct_of_options(ListOption *list_options, int length) {
	assert(list_options);
	assert(length);

	ListOptionsStruct *list_options_array = calloc(1, sizeof(ListOptionsStruct));
	list_options_array->list_options = list_options;
	list_options_array->length = length;
	return list_options_array;
}

void read_position(int *position) {
	assert(position);

	printf("Input position: ");
	scanf("%d", position);
}

int read_option() {
	int option;
	printf("Choose option: ");
	scanf("%d", &option);
	return option;
}

void print_options(const ListOptionsStruct *options) {
	assert(options);

	for (int i = 0; i < options->length; ++i) {
		printf("%d %s\n", ((options->list_options) + i)->type, ((options->list_options) + i)->label);
	}

}

void read_key(int *key) {
	assert(key);

	printf("Input key: ");
	scanf("%d", key);
}
