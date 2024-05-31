#ifndef _PERSON_H_
#define _PERSON_H_

#define MAX_SIZE_STRING 100

typedef struct Person {
	char *name;
	unsigned int age;
	unsigned int height;
	unsigned int year_of_birth;
	char *occupation;
} Person;

/**
 * Prints the details of a person.
 *
 * @param person A pointer to the person structure to be printed.
 * @return void
 */
void print_person(const Person *person);

/**
 * Frees the memory allocated for a person structure.
 *
 * @param person A pointer to the person structure to be freed.
 * @return void
 */
void free_person(Person *person);

/**
 * Creates a new person structure and initializes its fields.
 *
 * @return A pointer to the newly created person structure.
 */
Person *create_person();

#endif //_PERSON_H_
