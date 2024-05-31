//
// Created by Misha on 28.03.2024.
//

#ifndef _STRUCT_H_
#define _STRUCT_H_

#define MAX_SIZE_STRING 100

typedef struct Person {
	char *name;
	unsigned int age;
	unsigned int height;
	unsigned int year_of_birth;
	char *occupation;
} Person;

typedef struct Node {
	Person *person;
	struct Node *next;
} Node;

typedef struct List {
	Node *head;
} List;

enum MainOptionsEnum {
	MAIN_EXIT = 0,
	MAIN_PRINT_ALL = 1,
	MAIN_PRINT_BY_FIELD = 2,
	MAIN_SORY_BY = 3,
	MAIN_PUSH_IN_LIST = 4,
	MAIN_DELETE_BY_POSITION = 5,
	MAIN_REVERSE_LIST = 6,
};

enum ComparatorsEnum {
	BY_NAME = 1,
	BY_AGE = 2,
	BY_HEIGHT = 3,
	BY_YEAR_OF_BIRTH = 4,
	BY_OCCUPATION = 5,
};

enum PositionsEnum {
	START = 1,
	BY_POS = 2,
	END = 3,
};

typedef union OptionsType {
	enum PositionsEnum position_option;
	enum ComparatorsEnum comparator_option;
	enum MainOptionsEnum main_option;
} OptionsType;

typedef struct ListOption {
	char *label;
	OptionsType type;
} ListOption;

typedef struct ListOptionsStruct {
	ListOption *list_options;
	int length;
} ListOptionsStruct;

typedef int (*PersonComparatorPointer)(const Person *, const Person *);

#endif //_STRUCT_H_
