//
// Created by Misha on 28.03.2024.
//

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "funcs.h"
#include <assert.h>

uint64_t ALLOCATED_MEMORY = 0;
int64_t COUNT_ALOCATED_PERSONS = 0;

void print_count_allocated_persons() {
	printf("Count allocated persons: %lld\n", COUNT_ALOCATED_PERSONS);
}

void *my_malloc(uint64_t memory_size) {
	ALLOCATED_MEMORY += memory_size;
	uint64_t *result_memory = malloc(memory_size + sizeof(uint64_t));
	*result_memory = memory_size;
	return result_memory + 1;
}

void *my_calloc(uint64_t block_size, uint64_t blocks_count) {
	uint64_t memory_size = block_size * blocks_count;
	void *result_memory = my_malloc(memory_size);
	char *clear_ptr = result_memory;
	while (memory_size-- > 0) {
		*clear_ptr++ = 0;
	}
	return result_memory;
}

void my_free(void *memory) {
	uint64_t *memory_ptr = memory;
	uint64_t memory_size = *(--memory_ptr);
	ALLOCATED_MEMORY -= memory_size;
	free(memory_ptr);
}

void print_allocated_memory() {
	printf("Allocated memory %lld\n", ALLOCATED_MEMORY);
}

ListOptionsStruct *create_struct_of_options(const ListOption *list_options, int length) {
	assert(list_options);
	assert(length);

	ListOptionsStruct *list_options_array = my_calloc(1, sizeof(ListOptionsStruct));
	list_options_array->list_options = list_options;
	list_options_array->length = length;
	return list_options_array;
}

Person *create_person() {
	Person *person = my_calloc(1, sizeof(Person));
	++COUNT_ALOCATED_PERSONS;
	person->name = my_calloc(MAX_SIZE_STRING, sizeof(char));
	person->occupation = my_calloc(MAX_SIZE_STRING, sizeof(char));
	return person;
}

void *_read_person_form_file(FILE *file) {
	assert(file);

	Person *person = create_person();

	fscanf(file, "%s %u %u %u %s",
	       person->name,
	       &(person->age),
	       &(person->height),
	       &(person->year_of_birth),
	       person->occupation);

	return person;
}

int _compare_persons_by_name(const Person *first, const Person *second) {
	assert(first);
	assert(second);
	return strcmp(first->name, second->name);
}

int _compare_persons_by_age(const Person *first, const Person *second) {
	assert(first);
	assert(second);
	return (first->age - second->age);
}

int _compare_persons_by_height(const Person *first, const Person *second) {
	assert(first);
	assert(second);
	return (first->height - second->height);
}

int _compare_persons_by_year_of_birth(const Person *first, const Person *second) {
	assert(first);
	assert(second);
	return (first->year_of_birth - second->year_of_birth);
}

int _compare_persons_by_occupation(const Person *first, const Person *second) {
	assert(first);
	assert(second);

	return strcmp(first->occupation, second->occupation);
}

void _swap_persons(Person *first, Person *second) {
	assert(first);
	assert(second);

	Person temp = *first;
	*first = *second;
	*second = temp;
}

void free_person(Person *person) {
	assert(person);

	my_free(person->name);
	my_free(person->occupation);
	my_free(person);
	--COUNT_ALOCATED_PERSONS;
}

void free_node(Node *node) {
	assert(node);

	free_person(node->person);
	my_free(node);
}

List *create_list() {
	List *list = my_calloc(1, sizeof(List));
	return list;
}

Node *create_node(Person *person) {
	assert(person);

	Node *node = my_calloc(1, sizeof(Node));
	node->person = person;
	return node;
}

void push_front(List *list, void *element) {
	assert(list);
	assert(element);

	Node *new_node = create_node(element);
	new_node->next = list->head;
	list->head = new_node;
}

void push_back(List *list, void *element) {
	assert(list);
	assert(element);

	Node *new_node = create_node(element);

	if (list->head == NULL) {
		list->head = new_node;
		new_node->next = NULL;
		return;
	}

	Node *current_node = list->head;
	while (current_node->next) {
		current_node = current_node->next;

	}
	current_node->next = new_node;
}

int push_by_pos(List *list, void *element, int position) {
	assert(list);
	assert(element);
	assert(position);

	Node *new_node = create_node(element);
	int counter = 0;
	for (Node *current_node = list->head; current_node; current_node = current_node->next) {
		++counter;
		if (counter == position) {
			new_node->next = current_node->next;
			current_node->next = new_node;
			return counter;
		}
	}
	return -1;
}

void print_node(const Person *person) {
	assert(person);

	printf("%s | %d | %d | %hu | %s\n",
	       person->name, person->age,
	       person->height, person->year_of_birth,
	       person->occupation);
}

void print_list(const List *list) {
	assert(list);

	if (list->head == NULL) {
		printf("\nLista este vida! \n");
		return;
	}
	printf("\nElementele listei: \n");
	for (Node *current_node = list->head; current_node; current_node = current_node->next) {
		print_node(current_node->person);
	}
	printf("\n");
}

int
find_first_element_from_list_by_value_of_field_generic(const List *list, const Person *person, PersonComparatorPointer comparator) {
	assert(comparator);
	assert(list);
	assert(person);

	if (!list->head) {
		return -1;
	}

	int counter = 0;
	for (Node *current_node = list->head; current_node; current_node = current_node->next) {
		++counter;
		if (comparator(person, current_node->person) == 0) {
			return counter;
		}
	}

	return -1;
}

void import_data_from_file_in_linked_list(const char *file, List *list) {
	assert(file);
	assert(list);

	FILE *file_ptr = fopen(file, "r");

	assert(file_ptr);

	while (!feof(file_ptr)) {
		Person *person = _read_person_form_file(file_ptr);
		push_back(list, person);
	}

	fclose(file_ptr);
}

void select_by(const int type_of_search, const List *list) {
	assert(list);
	assert(type_of_search);

	Person *person = my_calloc(1, sizeof(Person));
	int position = -1;

	switch (type_of_search) {
		case BY_NAME: {
			person->name = my_calloc(MAX_SIZE_STRING, sizeof(char));
			printf("Input name that you want to search:\n");
			scanf(" %s", person->name);

			position = find_first_element_from_list_by_value_of_field_generic(list, person, _compare_persons_by_name);
			my_free(person->name);
			break;
		}
		case BY_AGE: {
			printf("Input age that you want to search:\n");
			scanf("%u", &person->age);

			position = find_first_element_from_list_by_value_of_field_generic(list, person, _compare_persons_by_age);
			break;
		}
		case BY_HEIGHT: {
			printf("Input height that you want to search:\n");
			scanf("%u", &person->height);

			position = find_first_element_from_list_by_value_of_field_generic(list, person, _compare_persons_by_height);
			break;
		}
		case BY_YEAR_OF_BIRTH: {
			printf("Input year of birth that you want to search:\n");
			scanf("%u", &person->year_of_birth);

			position = find_first_element_from_list_by_value_of_field_generic(list, person,
			                                                                  _compare_persons_by_year_of_birth);
			break;
		}
		case BY_OCCUPATION: {
			person->occupation = my_calloc(MAX_SIZE_STRING, sizeof(char));
			printf("Input height that you want to search:\n");
			scanf("%s", person->occupation);

			position = find_first_element_from_list_by_value_of_field_generic(list, person, _compare_persons_by_occupation);
			my_free(person->occupation);
			break;
		}
		default: {
            break;
        }
	}

	if (position != -1) {
		print_element_by_position(list, position);
	} else {
		printf("Person with this field was not found\n");
	}

	my_free(person);
	return;
}

void print_element_by_position(const List *list, const int position) {
	assert(list);
	assert(position);

	int counter = 0;
	for (Node *current_node = list->head; current_node; current_node = current_node->next) {
		++counter;
		if (position == counter) {
			print_node(current_node->person);
		}
	}
}

void sort_list_elements_generic(List *list, PersonComparatorPointer comparator) {
	assert(list);
	assert(comparator);

	for (Node *first_node = list->head; first_node; first_node = first_node->next) {
		for (Node *second_node = first_node; second_node; second_node = second_node->next) {
			if (comparator(first_node->person, second_node->person) > 0) {
				_swap_persons(first_node->person, second_node->person);
			}
		}
	}
}

void sort_by(const int type_of_sort, List *list) {
	assert(list);
	assert(type_of_sort);

	if (type_of_sort == BY_NAME) {
		sort_list_elements_generic(list, _compare_persons_by_name);
		return;
	}
	if (type_of_sort == BY_AGE) {
		sort_list_elements_generic(list, _compare_persons_by_age);
		return;
	}
	if (type_of_sort == BY_HEIGHT) {
		sort_list_elements_generic(list, _compare_persons_by_height);
		return;
	}
	if (type_of_sort == BY_YEAR_OF_BIRTH) {
		sort_list_elements_generic(list, _compare_persons_by_year_of_birth);
		return;
	}
	if (type_of_sort == BY_OCCUPATION) {
		sort_list_elements_generic(list, _compare_persons_by_occupation);
		return;
	}
}

void set_person_attributes(Person *person) {
	assert(person);

	printf("Input name: ");
	scanf("%9s", person->name);
	printf("Input age: ");
	scanf("%u", &(person->age));
	printf("Input height: ");
	scanf("%u", &(person->height));
	printf("Input year of birth: ");
	scanf("%u", &(person->year_of_birth));
	printf("Input function: ");
	scanf("%9s", person->occupation);
}

void read_position(int *position) {
	assert(position);

	printf("Input position: ");
	scanf("%d", position);
}

int pop_object_by_pos(List *list, const int position) {
	assert(list);
	assert(position);

	if (!list->head) {
		return -1;
	}

	int counter = 0;
	for (Node *current_node = list->head; current_node; current_node = current_node->next) {
		counter++;
		if (counter == position) {

			// Ca să nu pierdem adresa la următorul element
			Node *node_to_pop = current_node->next;
			current_node->next = node_to_pop->next;

			free_node(node_to_pop);
			return position;
		}
	}
	return -1;
}

int read_option() {
	int option;
	printf("Choose option: ");
	scanf("%d", &option);
	return option;
}

void reverse_list(List *list) {
	assert(list);

	if (!list->head) {
		return;
	}
	Node *prev_node = NULL;
	Node *current_node = list->head;
	Node *next_node = NULL;

	while (current_node) {
		next_node = current_node->next;
		current_node->next = prev_node;
		prev_node = current_node;
		current_node = next_node;
	}
	list->head = prev_node;
}

void free_list_nodes(List *list) {
	assert(list);

	if (!list->head) {
		return;
	}

	Node *temp_node;
	while (list->head) {
		temp_node = list->head;
		list->head = temp_node->next;
		free_node(temp_node);
	}
}

void print_options(const ListOptionsStruct *options) {
	assert(options);

	for (int i = 0; i < options->length; ++i) {
		printf("%d %s\n", ((options->list_options) + i)->type, ((options->list_options) + i)->label);
	}
}

