#include <stdbool.h>
//#include "../../Laborator/MY_TOP_LIB/library.c"
#include "functions.h"
#include "defines.h"

int main() {
	const List_option _main_options[] = {{"Print revenue for each month",                 PRINT_REVENUE_PER_MONTH},
	                                     {"Print top 5 products with the max total cost", PRINT_TOP_5_BY_TOTAL_COST},
	                                     {"Print sales by category",                      PRINT_SALES_BY_CATEGORY},
	                                     {"Print city with the max sales in country",     PRINT_CITY_WITH_MAX_SALES_BY_COUNTRY},
	                                     {"Print monthly trends by subcategory",          PRINT_TRENDS_BY_SUBCATEGORY},
	                                     {"EXIT",                                         EXIT}};

	List_options_struct *main_options = create_struct_of_options(_main_options,
	                                                           sizeof(_main_options) / sizeof(List_option));

	Sale_unit *sale_unit = calloc(1, sizeof(Sale_unit));
	FILE *file = fopen("/Users/admin/Downloads/UTM/SDA/Seminar/Sem1/sale.txt", "r");
	sale_unit->length = get_count_rows_from_file(file);
	sale_unit->array = (Unit *) calloc(sale_unit->length, sizeof(Unit));
	get_data_from_file(file, sale_unit);
	calculate_the_total_cost(sale_unit);

	int choice;

	do {
		print_options(main_options);
		choice = read_option();
		system(CLEARSCREEN);

		if (choice == PRINT_REVENUE_PER_MONTH) {
			print_monthly_revenue_by_year(sale_unit);
			continue;
		}

		if (choice == PRINT_TOP_5_BY_TOTAL_COST) {
			print_top_5_by_total_cost(sale_unit);
			continue;
		}

		if (choice == PRINT_SALES_BY_CATEGORY) {
			print_count_sales_per_category(sale_unit);
			continue;
		}

		if (choice == PRINT_CITY_WITH_MAX_SALES_BY_COUNTRY) {
			print_city_with_biggest_nr_of_sales_by_country(sale_unit);
			continue;
		}

		if (choice == PRINT_TRENDS_BY_SUBCATEGORY) {
			print_monthly_revenue_by_subcategory(sale_unit);
			continue;
		}

		if (choice == EXIT) {
			break;
		}
	}
	while (true);


//    print_top_5_by_total_cost(sale_unit);

//    print_data(sale_unit);

//	print_monthly_revenue_by_year(sale_unit);


//	print_monthly_revenue_by_subcategory(sale_unit);

//	print_count_sales_per_category(sale_unit);


//	print_city_with_biggest_nr_of_sales_by_country(sale_unit);




	printf("\n");

	free(sale_unit->array);
	free(sale_unit);
	return 0;
}
