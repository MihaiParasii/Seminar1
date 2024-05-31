#ifndef _FUNCS_H_
#define _FUNCS_H_

#include "struct.h"

/**
 * Prints the list of options to the console.
 *
 * @param options A pointer to the ListOptionsStruct containing the options to be printed.
 */
void print_options(const ListOptionsStruct *options);

/**
 * Creates a new ListOptionsStruct from an array of ListOption and its length.
 *
 * @param list_options An array of ListOption.
 * @param length The length of the list_options array.
 * @return A pointer to the newly created ListOptionsStruct.
 */
ListOptionsStruct *create_struct_of_options(ListOption *list_options, int length);

/**
 * Reads an integer position from the user input.
 *
 * @param position A pointer to the integer where the read position will be stored.
 */
void read_position(int *position);

/**
 * Reads an integer option from the user input.
 *
 * @return The integer option read from the user input.
 */
int read_option();

/**
 * Reads an integer key from the user input.
 *
 * @param key A pointer to the integer where the read key will be stored.
 */
void read_key(int *key);

#endif //_FUNCS_H_
