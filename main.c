#include <stdlib.h>
#include <stdbool.h>
#include "funcs.h"

int main() {
	const ListOption _main_options[] = {{"Print all data",             MAIN_PRINT_ALL},
	                                    {"Print by value of field",    MAIN_PRINT_BY_FIELD},
	                                    {"Sort by",                    MAIN_SORY_BY},
	                                    {"Insert in list",             MAIN_PUSH_IN_LIST},
	                                    {"Delete element by position", MAIN_DELETE_BY_POSITION},
	                                    {"Reverse linked list",        MAIN_REVERSE_LIST},
	                                    {"EXIT",                       MAIN_EXIT}};

	const ListOption _field_options[] = {{"By name",          BY_NAME},
	                                     {"By age",           BY_AGE},
	                                     {"By height",        BY_HEIGHT},
	                                     {"By year of birth", BY_YEAR_OF_BIRTH},
	                                     {"By occupation",    BY_OCCUPATION}};

	const ListOption _insert_options[] = {{"At the start", START},
	                                      {"At position",  BY_POS},
	                                      {"At the end",   END}};

	ListOptionsStruct *main_options = create_struct_of_options(_main_options,
	                                                           sizeof(_main_options) / sizeof(ListOption));
	ListOptionsStruct *select_or_sort_options = create_struct_of_options(_field_options,
	                                                                     sizeof(_field_options) / sizeof(ListOption));
	ListOptionsStruct *insert_options = create_struct_of_options(_insert_options,
	                                                             sizeof(_insert_options) / sizeof(ListOption));

	int choice;
	int type_of_select_or_sort;
	int type_of_push;
	bool execution = true;

	List *linked_list = create_list();
	import_data_from_file_in_linked_list("/Users/admin/Downloads/UTM/SDA/Laborator/Lab2/persons.txt", linked_list);

	system("clear");
	while (execution) {
		print_options(main_options);
		choice = read_option();
		system("clear");

		switch (choice) {
			case MAIN_PRINT_ALL: {
				print_list(linked_list);
				break;
			}
			case MAIN_PRINT_BY_FIELD: {
				print_options(select_or_sort_options);
				type_of_select_or_sort = read_option();
				select_by(type_of_select_or_sort, linked_list);
				break;
			}
			case MAIN_SORY_BY: {
				print_options(select_or_sort_options);
				type_of_select_or_sort = read_option();
				sort_by(type_of_select_or_sort, linked_list);
				break;
			}
			case MAIN_PUSH_IN_LIST: {
				print_options(insert_options);
				type_of_push = read_option();

				Person *person = create_person();
				set_person_attributes(person);

				switch (type_of_push) {
					case END: {
						push_back(linked_list, person);
						break;
					}
					case START: {
						push_front(linked_list, person);
						break;
					}
					case BY_POS: {
						int position;
						read_position(&position);

						if (push_by_pos(linked_list, person, position) == -1) {
							printf("You set wrong position\n");
						}
						break;
					}
					default: {
						break;
					}
				}
				break;
			}
			case MAIN_DELETE_BY_POSITION: {
				int position;
				read_position(&position);
				if (pop_object_by_pos(linked_list, position) == -1) {
					printf("You set wrong position\n");
				}
				break;
			}
			case MAIN_REVERSE_LIST: {
				reverse_list(linked_list);
				break;
			}
			case MAIN_EXIT: {
				execution = false;
				printf("EXIT\n");
				break;
			}
			default: {
				system("clear");
				printf("You choose wrong option\n");
			}
		}
	}
	print_count_allocated_persons();
	print_allocated_memory();
	free_list_nodes(linked_list);
	print_allocated_memory();
	my_free(linked_list);
	print_allocated_memory();
	my_free(main_options);
	print_allocated_memory();
	my_free(insert_options);
	print_allocated_memory();
	my_free(select_or_sort_options);
	print_allocated_memory();
	print_count_allocated_persons();
	return 0;
}
