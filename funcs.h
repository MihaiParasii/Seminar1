//
// Created by Misha on 28.03.2024.
//

#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>
#include <stdint.h>
#include "struct.h"

void print_count_allocated_persons();

void *my_malloc(uint64_t memory_size);

void *my_calloc(uint64_t block_size, uint64_t blocks_count);

void my_free(void *memory);

void print_allocated_memory();

ListOptionsStruct *create_struct_of_options(const ListOption *list_options, int length);

/**
 * @DESCRIPTION
 * \b create_list() will create the head of linked list.
 * \n\b This function allocate a block of memory in HEAP with size of List * and set the list->head with NULL.
 * \n\n   The allocated memory is filled with bytes of value zero.
 *
 *
 * @RETURN__VALUES
 * This function will return a pointer of type  \b List \b * to the allocated memory.
 * \n
 */
List *create_list();

/**
 *
 * @param person *person
 *
 * @DESCRIPTION \b *create_node() will create a node for linked list data structure
 * and puts in it into new created object person.
 * @RETURN__VALUE This function will return a pointer of type  \b Node \b * to the allocated memory.
 * \n
 */
Node *create_node(Person *person);

void print_list(const List *list);

int
find_first_element_from_list_by_value_of_field_generic(const List *list, const Person *person, PersonComparatorPointer comparator);

void print_element_by_position(const List *list, const int position);

Person *create_person();

/**
 *
 * @param file Full path of \a .txt file.
 * @param list Linked list
 *
 * @DESCRIPTION \b import_data_from_file_in_linked_list() read a line at a time from the given file,
 * and puts it into new created object person and push back in given linked list.
 * @RETURN__VALUE This function will return count of rows successfully read from file.
 */
void import_data_from_file_in_linked_list(const char *file, List *list);

void select_by(const int type_of_search, const List *list);

void sort_list_elements_generic(List *list, PersonComparatorPointer comparator);

void sort_by(const int type_of_sort, List *list);

void push_back(List *list, void *element);

void push_front(List *list, void *element);

/**
 *
 * @param list The head of linked list
 * @param element Person to input in linked list
 * @param position  Position where input person
 *
 * @DESCRIPTION
 * This function will push the given value in linked list at the given position.
 * \n If the position is not founded, the element won't be pushed.
 * @RETURN__VALUE
 * Function will return position where element was pushed.
 * \n If position is not valid will return -1.
 */
int push_by_pos(List *list, void *element, int position);

int pop_object_by_pos(List *list, const int position);

void set_person_attributes(Person *person);

void read_position(int *position);

void print_options(const ListOptionsStruct *options);

int read_option();

void reverse_list(List *list);

void free_list_nodes(List *list);

#endif //_FUNCS_H_
