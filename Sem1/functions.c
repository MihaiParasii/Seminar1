//
// Created by Misha on 23.02.2024.
//

#include "functions.h"

int get_count_rows_from_file(FILE *file) {
	const int buffer_size = 500;
	char buffer[buffer_size];
	int lines = 0;
	while (fgets(buffer, buffer_size, file)) {
		lines++;
	}
	rewind(file);
	return lines ? lines : 0;

}

void get_data_from_file(FILE *file, Sale_unit *sale_unit) {
	for (int i = 0; i < sale_unit->length; i++) {
		fscanf(file, " %[^,],%d,%[^,],%[^,],%[^,],%f,%d,%[^,],%[^\n]",
		       ((sale_unit->array) + i)->date,
		       &(((sale_unit->array) + i)->id),
		       ((sale_unit->array) + i)->product_name,
		       ((sale_unit->array) + i)->product_category,
		       ((sale_unit->array) + i)->product_subcategory,
		       &(((sale_unit->array) + i)->unit_price),
		       &(((sale_unit->array) + i)->quantity_sold),
		       ((sale_unit->array) + i)->sale_country,
		       ((sale_unit->array) + i)->sale_city);
	}
}

void _print_line(Unit *unit) {
	printf("%s %8d %15s %15s %15s %.2f %4.1d %7.3f %50s %30s\n",
	       unit->date,
	       unit->id,
	       unit->product_name,
	       unit->product_category,
	       unit->product_subcategory,
	       unit->unit_price,
	       unit->quantity_sold,
	       unit->total_cost,
	       unit->sale_country,
	       unit->sale_city
	);
}

void print_data(Sale_unit *sale_unit) {
	for (int i = 0; i < 5; ++i) {
		_print_line((sale_unit->array) + i);
	}
}

void calculate_the_total_cost(Sale_unit *sale_unit) {
	for (int i = 0; i < sale_unit->length; ++i) {
		(sale_unit->array + i)->total_cost =
			(sale_unit->array + i)->quantity_sold * (sale_unit->array + i)->unit_price;

	}
}

void _swap_elements(Unit *unit1, Unit *unit2) {
	Unit temp = *unit1;
	*unit1 = *unit2;
	*unit2 = temp;
}

void print_top_5_by_total_cost(Sale_unit *sale_unit) {
	for (int i = 0; i < sale_unit->length - 1; ++i) {
		for (int j = 0; j < sale_unit->length - i - 1; ++j) {
			if (((sale_unit->array) + j)->total_cost > ((sale_unit->array) + j + 1)->total_cost) {
				_swap_elements(((sale_unit->array) + j), ((sale_unit->array) + j + 1));
			}
		}
		if (i == 5) {
			break;
		}

		_print_line(((sale_unit->array) + (sale_unit->length) - i - 1));
	}
}

int search_in_list(List *list, Data *data) {
	int position = 0;

	for (Node *current_node = list->head; current_node; current_node = current_node->next) {
		if (current_node->data == data) {
			return position;
		}
		++position;
	}

	return -1;
}

List *create_list() {
	List *list = calloc(1, sizeof(List));
	list->head = NULL;
	return list;
}

Node *create_node(Data *data) {
	Node *node = calloc(1, sizeof(Node));
	node->data = data;
	return node;
}

void push_back(List *list, Data *data) {
	Node *new_node = create_node(data);

	if (list->head == NULL) {
		list->head = new_node;
		new_node->next = NULL;
		return;
	}

	for (Node *current_node = list->head; current_node; current_node = current_node->next) {
		if (current_node->next == NULL) {
			current_node->next = new_node;
			new_node->next = NULL;
			return;
		}
	}

	// Varianta 2
	/*
	Node *current_node = list->head;
	while (current_node->next) {
		current_node = current_node->next;
	}
	current_node->next = new_node;
	 */
}

void push_front(List *list, Data *data) {
	Node *new_node = create_node(data);
	new_node->next = list->head;
	list->head = new_node;
}

void _free_node(Node *node) {
	free(node);
}

void free_list_nodes(List *list) {
	Node *temp_node;
	while (list->head) {
		temp_node = list->head;
		list->head = temp_node->next;
		_free_node(temp_node);
	}
}

List *get_monthly_sales_by_fields(Sale_unit *sale_unit, int year, char *subcategory) {
	List *list = create_list();
	char year_month[8];
	for (int i = 1; i <= 12; ++i) {
		Data *data = calloc(1, sizeof(Data));
		int count_sales_per_month = 0;
		float sum_per_month = 0;

		if (i < 10) {
			sprintf(year_month, "%d-0%d", year, i);
		}
		else {
			sprintf(year_month, "%d-%d", year, i);
		}

		for (int j = 0; j < sale_unit->length; ++j) {
			if (strncmp(((sale_unit->array) + j)->date, year_month, 7) != 0) {
				continue;
			}

			if (strcmp(subcategory, "") != 0) {
				if (strcmp(((sale_unit->array) + j)->product_subcategory, subcategory) != 0) {
					continue;
				}
			}
			count_sales_per_month += ((sale_unit->array) + j)->quantity_sold;
			sum_per_month += ((sale_unit->array) + j)->total_cost;
		}
		data->count_sales = count_sales_per_month;
		data->revenue = sum_per_month;

		push_back(list, data);

	}

	return list;
}

void print_monthly_revenue_by_subcategory(Sale_unit *sale_unit) {
	char subcategory[100];
	int year;
	int index = 0;
	printf("Input year: ");
	scanf("%d", &year);

	printf("Input subcategory: ");
	scanf(" %[^\n]s", subcategory);

	List *list = get_monthly_sales_by_fields(sale_unit, year, subcategory);

	printf("Here is statistic about count sales of subcategory %s in %d:\n\n", subcategory, year);

	printf("Month:\tCount Sales:\n");
	for (Node *current_node = list->head; current_node; current_node = current_node->next) {
		printf("%2.d\t—\t%2.d \n", ++index, current_node->data->count_sales);
	}

	free_list_nodes(list);
	free(list);
}

void print_monthly_revenue_by_year(Sale_unit *sale_unit) {
	int year;
	int index = 0;
	printf("Input year: ");
	scanf("%d", &year);

	List *list = get_monthly_sales_by_fields(sale_unit, year, "");


	printf("Here is statistic about total revenue for each month in %d:\n\n", year);
	printf("Month:\tMonthly Revenue:\n");
	for (Node *current_node = list->head; current_node; current_node = current_node->next) {
		printf("%2.d\t—\t%.2f \n", ++index, current_node->data->revenue);
	}

	free_list_nodes(list);
	free(list);
}

int get_count_sales_by_category(Sale_unit *sale_unit, char *category) {
	int count_sales = 0;
	for (int i = 0; i < sale_unit->length; ++i) {
		if (strcmp(((sale_unit->array) + i)->product_category, category) == 0) {
//			_print_line(sale_unit->list + i);
			count_sales += ((sale_unit->array) + i)->quantity_sold;
		}
	}
	return count_sales;
}

void print_count_sales_per_category(Sale_unit *sale_unit) {
	char sale_category[100];

	printf("Input category: ");
	scanf(" %[^\n]s", sale_category);

	int sum = get_count_sales_by_category(sale_unit, sale_category);

	printf("In category %s are sold %d products\n", sale_category, sum);
}

City_struct *get_city_with_max_nr_of_sales_by_country(Sale_unit *sale_unit, char country[100]) {
	City_struct *city_struct_to_return = calloc(1, sizeof(City_struct));

	city_struct_to_return->nr_of_sales = 0;

	for (int i = 0; i < sale_unit->length; ++i) {
		int nr_of_sales = 0;

		if (strcmp(((sale_unit->array) + i)->sale_country, country) != 0) {
			continue;
		}
		for (int j = i; j < sale_unit->length; ++j) {
			if (strcmp(((sale_unit->array) + j)->sale_country, country) != 0) {
				continue;
			}
			if (strcmp(((sale_unit->array) + i)->sale_city, ((sale_unit->array) + j)->sale_city) != 0) {
				continue;
			}
			nr_of_sales += ((sale_unit->array) + j)->quantity_sold;
		}

		if (city_struct_to_return->nr_of_sales < nr_of_sales) {
			city_struct_to_return->nr_of_sales = nr_of_sales;
			strcpy(city_struct_to_return->city, ((sale_unit->array) + i)->sale_city);
		}

	}

	return city_struct_to_return;
}

void print_city_with_biggest_nr_of_sales_by_country(Sale_unit *sale_unit) {
	char country[100];
	printf("Input country: ");
	scanf(" %[^\n]s", country);

	City_struct *city_struct = get_city_with_max_nr_of_sales_by_country(sale_unit, country);

	printf("From %s, the city with maximum sales is %s and have %d sales\n",
	       country, city_struct->city, city_struct->nr_of_sales);

	free(city_struct);
}

int read_option() {
	int option;
	printf("Choose option: ");
	scanf("%d", &option);
	return option;
}

List_options_struct *create_struct_of_options(List_option *list_options, int length) {
	List_options_struct *list_options_array = calloc(1, sizeof(List_options_struct));
	list_options_array->list_options = list_options;
	list_options_array->length = length;
	return list_options_array;
}

void print_options(const List_options_struct *options) {
	printf("\n\n");
	for (int i = 0; i < options->length; ++i) {
		printf("%d — %s\n", ((options->list_options) + i)->type, ((options->list_options) + i)->label);
	}
}







