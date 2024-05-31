#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "struct.h"


void select_all(PersonStruct *personsStruct) {
    for (int i = 0; i < personsStruct->length; ++i) {
        printf("%s was %d years old and is %d cm tall\n",
               (((personsStruct)->list_of_person) + i)->name,
               (((personsStruct)->list_of_person) + i)->age,
               (((personsStruct)->list_of_person) + i)->height);
    }
}

void select_by_name(PersonStruct *personsStruct) {
    char name_to_search[100];
    printf("Input name that you want to search:\n");
    scanf(" %s", name_to_search);

    for (int i = 0; i < personsStruct->length; ++i) {
        if (strcmp(name_to_search, (((personsStruct)->list_of_person) + i)->name) == 0) {
            printf("First found object has index: %d\n", i);
            printf("%s | %d | %d\n",
                   (((personsStruct)->list_of_person) + i)->name,
                   (((personsStruct)->list_of_person) + i)->age,
                   (((personsStruct)->list_of_person) + i)->height);
            return;
        }
    }

    printf("Object with this name was not found.\n");
    return;
}

void select_by_age(PersonStruct *personsStruct) {
    int age_to_search;

    printf("Input age that you want to search:\n");
    scanf("%d", &age_to_search);

    for (int i = 0; i < personsStruct->length; ++i) {
        if (age_to_search == (((personsStruct)->list_of_person) + i)->age) {
            printf("First found object has index: %d\n", i);
            printf("%s | %d | %d\n",
                   (((personsStruct)->list_of_person) + i)->name,
                   (((personsStruct)->list_of_person) + i)->age,
                   (((personsStruct)->list_of_person) + i)->height);
            return;
        }
    }

    printf("Object with this age was not found.\n");
    return;
}

void select_by_height(PersonStruct *personsStruct) {
    int height_to_search;

    printf("Input height that you want to search:\n");
    scanf("%d", &height_to_search);

    for (int i = 0; i < personsStruct->length; ++i) {
        if (height_to_search == (((personsStruct)->list_of_person) + i)->height) {
            printf("First found object has index: %d\n", i);
            printf("%s | %d | %d\n",
                   (((personsStruct)->list_of_person) + i)->name,
                   (((personsStruct)->list_of_person) + i)->age,
                   (((personsStruct)->list_of_person) + i)->height);
            return;
        }
    }

    printf("Object with this height was not found.\n");
    return;
}

int get_count_of_rows_from(FILE *file) {
    char ch;
    int rows = 0;
    while (!feof(file)) {
        ch = fgetc(file);
        if (ch == '\n') {
            rows++;
        }
    }

    rewind(file);

    // ++ if file don't end with '\n'
    return ++rows;
}

void get_data_from(FILE *file, PersonStruct *personsStruct) {
    for (int i = 0; i < personsStruct->length; i++) {
        fscanf(file, "%s %d %d", (((personsStruct)->list_of_person) + i)->name,
               &(((personsStruct)->list_of_person) + i)->age,
               &(((personsStruct->list_of_person) + i)->height));
    }
}

void select_by(int type_of_search, PersonStruct *personsStruct) {
    if (option_is((enum MainOptionsEnum) BY_NAME, type_of_search)) {
        select_by_name(personsStruct);
        return;
    }
    if (option_is((enum MainOptionsEnum) BY_AGE, type_of_search)) {
        select_by_age(personsStruct);
        return;
    }
    if (option_is((enum MainOptionsEnum) BY_HEIGHT, type_of_search)) {
        select_by_height(personsStruct);
        return;
    }
    return;
}

void set_ex(int *ex) {
    printf("Choose ex: ");
    scanf("%d", ex);
}


// Ex 2


void sort_by_name(PersonStruct *personsStruct) {
    for (int i = 0; i < personsStruct->length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (strcmp(((personsStruct->list_of_person) + i)->name, ((personsStruct->list_of_person) + j)->name) < 0) {
                Person temp = *((personsStruct->list_of_person) + i);
                *((personsStruct->list_of_person) + i) = *((personsStruct->list_of_person) + j);
                *((personsStruct->list_of_person) + j) = temp;
            }
        }
    }
}

void sort_by_age(PersonStruct *personsStruct) {
    for (int i = 0; i < personsStruct->length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (((personsStruct->list_of_person) + i)->age < ((personsStruct->list_of_person) + j)->age) {
                Person temp = *((personsStruct->list_of_person) + i);
                *((personsStruct->list_of_person) + i) = *((personsStruct->list_of_person) + j);
                *((personsStruct->list_of_person) + j) = temp;
            }
        }
    }
}

void sort_by_height(PersonStruct *personsStruct) {
    for (int i = 0; i < personsStruct->length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (((personsStruct->list_of_person) + i)->height < ((personsStruct->list_of_person) + j)->height) {
                Person temp = *((personsStruct->list_of_person) + i);
                *((personsStruct->list_of_person) + i) = *((personsStruct->list_of_person) + j);
                *((personsStruct->list_of_person) + j) = temp;
            }
        }
    }
}

void sort_by(int type_of_sort, PersonStruct *personsStruct) {
    if (option_is((enum MainOptionsEnum) BY_NAME, type_of_sort)) {
        sort_by_name(personsStruct);
        return;
    }
    if (option_is((enum MainOptionsEnum) BY_AGE, type_of_sort)) {
        sort_by_age(personsStruct);
        return;
    }
    if (option_is((enum MainOptionsEnum) BY_HEIGHT, type_of_sort)) {
        sort_by_height(personsStruct);
        return;
    }
}

PersonStruct *insert_at_the_end(PersonStruct *personsStruct, Person *person_to_input) {
    personsStruct->length++;
    personsStruct->list_of_person = realloc(personsStruct->list_of_person, personsStruct->length * sizeof(Person));

    (personsStruct->list_of_person[personsStruct->length - 1]) = *person_to_input;

    return personsStruct;
}

PersonStruct *insert_at_the_start(PersonStruct *personsStruct, Person *person_to_input) {
    personsStruct->length++;
    personsStruct->list_of_person = realloc(personsStruct->list_of_person, personsStruct->length * sizeof(Person));

    for (int i = personsStruct->length - 1; i > 0; --i) {
        (personsStruct->list_of_person[i]) = (personsStruct->list_of_person[i - 1]);
    }

    (personsStruct->list_of_person[0]) = *person_to_input;
    return personsStruct;
}

PersonStruct *insert_at_the_x_pos(PersonStruct *personsStruct, Person *person_to_input, int position) {
    personsStruct->length++;
    personsStruct->list_of_person = realloc(personsStruct->list_of_person, personsStruct->length * sizeof(Person));

    for (int i = personsStruct->length - 1; i > position; --i) {
        (personsStruct->list_of_person[i]) = (personsStruct->list_of_person[i - 1]);
    }

    (personsStruct->list_of_person[position - 1]) = *person_to_input;
    return personsStruct;
}


PersonStruct *insert_into(PersonStruct *personsStruct, Person *person_to_input, int type_of_insert) {
    if (option_is((enum MainOptionsEnum) END, type_of_insert)) {
        personsStruct = insert_at_the_end(personsStruct, person_to_input);
        return personsStruct;
    }
    if (option_is((enum MainOptionsEnum) START, type_of_insert)) {
        personsStruct = insert_at_the_start(personsStruct, person_to_input);
        return personsStruct;
    }
    if (option_is((enum MainOptionsEnum) X_POS, type_of_insert)) {
        int position;
        set_position(&position);
        if (!is_valid_pos(position, personsStruct->length)) {
            system("clear");
            printf("You choose wrong position\n");
            return personsStruct;
        }
        personsStruct = insert_at_the_x_pos(personsStruct, person_to_input, position);
        return personsStruct;
    }
    return personsStruct;
}

void set_person_attributes(Person *person_to_input) {
    printf("Input name: ");
    scanf("%s", (person_to_input)->name);
    printf("Input age: ");
    scanf("%d", &(person_to_input->age));
    printf("Input height: ");
    scanf("%d", &(person_to_input->height));
}

void set_position(int *position) {
    printf("Input position: ");
    scanf("%d", position);
}

bool is_valid_pos(int position, int count_rows) {
    return ((position > 0) && (position <= count_rows));
}

PersonStruct *delete_object_at_the_x_pos(PersonStruct *personsStruct, int position) {
    for (int i = position; i < personsStruct->length - 1; ++i) {
        *(personsStruct->list_of_person + i) = *(personsStruct->list_of_person + i + 1);
    }

    --(personsStruct->length);
    personsStruct->list_of_person = realloc(personsStruct->list_of_person, (personsStruct->length) * sizeof(Person));
    return personsStruct;
}

void print_options(MainOptionsStruct *list, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d — %s\n", list[i].type, list[i].label);
    }
}

int set_option() {
    int option;
    printf("Choose option: ");
    scanf("%d", &option);
    return option;
}

bool option_is(enum MainOptionsEnum value, int option) {
    return option == value;
}