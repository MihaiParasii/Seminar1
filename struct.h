#ifndef LAB1_STRUCT_H
#define LAB1_STRUCT_H

typedef struct {
    char name[100];
    int age;
    int height;
} Person;

enum MainOptionsEnum {
    EXIT = 0, SELECT_ALL = 1, SELECT_WHERE = 2, SORT_BY = 3, INSERT_INTO = 4, DELETE_FROM = 5
};

enum SelectOrSortOptionsEnum {
    BY_NAME = 1, BY_AGE = 2, BY_HEIGHT = 3
};

enum InsertOptionsEnum {
    START = 1, X_POS = 2, END = 3
};

typedef struct {
    char *label;
    enum MainOptionsEnum type;
} MainOptionsStruct;

typedef struct {
    char *label;
    enum SelectOrSortOptionsEnum type;
} SelectOrSortOptionsStruct;

typedef struct {
    char *label;
    enum InsertOptionsEnum type;
} InsertOptionsStruct;

typedef struct {
    Person *list_of_person;
    int length;
} PersonStruct;


#endif //LAB1_STRUCT_H
