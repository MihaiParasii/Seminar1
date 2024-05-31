#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

#ifndef LAB1_FUNCTIONS_H
#define LAB1_FUNCTIONS_H

void select_all(PersonStruct *personsStruct);

void select_by_name(PersonStruct *personsStruct);

void select_by_age(PersonStruct *personsStruct);

void select_by_height(PersonStruct *personsStruct);

int get_count_of_rows_from(FILE *file);

void get_data_from(FILE *file, PersonStruct *personsStruct);

void select_by(int type_of_search, PersonStruct *personsStruct);

void set_ex(int *ex);

void sort_by_name(PersonStruct *personsStruct);

void sort_by_age(PersonStruct *personsStruct);

void sort_by_height(PersonStruct *personsStruct);

void sort_by(int type_of_sort, PersonStruct *personsStruct);

PersonStruct *insert_at_the_end(PersonStruct *personsStruct, Person *person_to_input);

PersonStruct *insert_at_the_start(PersonStruct *personsStruct, Person *person_to_input);

PersonStruct *insert_at_the_x_pos(PersonStruct *personsStruct, Person *person_to_input, int position);

PersonStruct *insert_into(PersonStruct *personsStruct, Person *person_to_input, int type_of_insert);

PersonStruct *delete_object_at_the_x_pos(PersonStruct *personsStruct, int position);

void set_person_attributes(Person *person_to_input);

void set_position(int *position);

bool is_valid_pos(int position, int count_rows);

void print_options(MainOptionsStruct *list, int length);

int set_option();

bool option_is(enum MainOptionsEnum value, int option);

#endif //LAB1_FUNCTIONS_H
