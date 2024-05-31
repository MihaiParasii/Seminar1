#include "Person.h"
#include "includes.h"

Person *create_person() {
	Person *person = calloc(1, sizeof(Person));
	person->name = calloc(MAX_SIZE_STRING, sizeof(char));
	person->occupation = calloc(MAX_SIZE_STRING, sizeof(char));
	return person;
}

void free_person(Person *person) {
	assert(person);

	free(person->name);
	free(person->occupation);
	free(person);
}

void print_person(const Person *person) {
	assert(person);

	printf("%s | %d | %d | %hu | %s\n",
	       person->name, person->age, person->height, person->year_of_birth, person->occupation);
}

