//
// Created by Misha on 23.02.2024.
//

//#include "exercitions.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "functions.h"
#include "exercises.h"

void ex1() {
    int choice;
    int type_of_select;

    const MainOptionsStruct mainOption[] = {{"SELECT * FROM Persons",                         1},
                                            {"SELECT * FROM Persons WHERE ___ = ___ LIMIT 1", 2},
                                            {"EXIT",                                          0}};

    const SelectOrSortOptionsStruct selectOrSortOptions[] = {{"BY NAME",   1},
                                                             {"BY AGE",    2},
                                                             {"BY HEIGHT", 3}};


    PersonStruct *person_list = calloc(1, sizeof(person_list));

    int main_option_length = sizeof(mainOption) / sizeof(mainOption[0]);
    int select_or_sort_option_length = sizeof(selectOrSortOptions) / sizeof(selectOrSortOptions[0]);

    FILE *file = fopen("/Users/admin/Downloads/UTM/SDA/Laborator/Lab1/persons.txt", "r");
    int count_of_rows = get_count_of_rows_from(file);

    person_list->length = count_of_rows;
    person_list->list_of_person = (Person *) calloc(person_list->length, sizeof(Person));

    get_data_from(file, person_list);
    fclose(file);

    while (true) {
        print_options(mainOption, main_option_length);
        choice = set_option();
        system("clear");

        if (option_is(EXIT, choice)) {
            printf("EXIT\n");
            break;
        }

        if (option_is(SELECT_ALL, choice)) {
            select_all(person_list);
            continue;
        }

        if (option_is(SELECT_WHERE, choice)) {
            print_options((MainOptionsStruct *) selectOrSortOptions, select_or_sort_option_length);
            type_of_select = set_option();
            select_by(type_of_select, person_list);
            continue;
        }
        system("clear");
        printf("You choose wrong option\n");
    }

    free(person_list->list_of_person);
    free(person_list);
}

void ex2() {
    /*
     * TODO
     * YES — array of structures
     * YES — struct ... label(text), type(CONST/enum)
     * YES — all types must be in an enum
     *
     * YES — is_exit(), is_select_all(), is_select_with_search(), ... -> option_is_of_type(option, "array_of_structures" enum.exit)
     *
     * YES — set_option(), get_type_of_search(), get_type_of_sort() -> printf() : for int i = 0; i in enum: printf(enum.i)  // scan
     *
     * NO — remove all lengths
     * NO — func to calc length
     */

    const MainOptionsStruct main_options[] = {{"SELECT * FROM Persons",                         1},
                                              {"SELECT * FROM Persons WHERE ___ = ___ LIMIT 1", 2},
                                              {"SORT BY",                                       3},
                                              {"INSERT INTO",                                   4},
                                              {"DELETE FROM",                                   5},
                                              {"EXIT",                                          0}};

    const SelectOrSortOptionsStruct select_or_sort_options[] = {{"BY NAME",   1},
                                                                {"BY AGE",    2},
                                                                {"BY HEIGHT", 3}};

    const InsertOptionsStruct insert_options[] = {{"AT THE START", 1},
                                                  {"AT THE X POS", 2},
                                                  {"AT THE END",   3}};


    int choice;
    int position;
    int type_of_select_or_sort;
    int type_of_insert;

    int main_option_length = sizeof(main_options) / sizeof(main_options[0]);
    int select_or_sort_option_length = sizeof(select_or_sort_options) / sizeof(select_or_sort_options[0]);

    PersonStruct *persons_list = calloc(1, sizeof(PersonStruct));

    FILE *file = fopen("/Users/admin/Downloads/UTM/SDA/Laborator/Lab1/persons.txt", "r");

    persons_list->length = get_count_of_rows_from(file);
    persons_list->list_of_person = (Person *) calloc(persons_list->length, sizeof(Person));

    get_data_from(file, persons_list);
    fclose(file);

    while (true) {
        system("clear");
        print_options(main_options, main_option_length);
        choice = set_option();
        system("clear");

        if (option_is(EXIT, choice)) {
            printf("EXIT\n");
            break;
        }

        if (option_is(SELECT_ALL, choice)) {
            select_all(persons_list);
            continue;
        }

        if (option_is(SELECT_WHERE, choice)) {
            print_options((MainOptionsStruct *) select_or_sort_options, select_or_sort_option_length);
            type_of_select_or_sort = set_option();
            select_by(type_of_select_or_sort, persons_list);
            continue;
        }

        if (option_is(SORT_BY, choice)) {
            print_options((MainOptionsStruct *) select_or_sort_options, select_or_sort_option_length);
            type_of_select_or_sort = set_option();
            sort_by(type_of_select_or_sort, persons_list);
            continue;
        }

        if (option_is(INSERT_INTO, choice)) {
            print_options((MainOptionsStruct *) insert_options, select_or_sort_option_length);
            type_of_insert = set_option();
            Person person1;
            set_person_attributes(&person1);
            persons_list = insert_into(persons_list, &person1, type_of_insert);
            continue;
        }

        if (option_is(DELETE_FROM, choice)) {
            set_position(&position);
            persons_list = delete_object_at_the_x_pos(persons_list, position);
            continue;
        }
        system("clear");
        printf("You choose wrong option\n");
    }

    free(persons_list->list_of_person);
    free(persons_list);
}