//
// Created by Misha on 23.02.2024.
//

#ifndef SEM1_FUNCTIONS_H
#define SEM1_FUNCTIONS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"

int get_count_rows_from_file(FILE *file);

void get_data_from_file(FILE *file, Sale_unit *sale_unit);

void print_data(Sale_unit *sale_unit);

void _print_line(Unit *unit);

void calculate_the_total_cost(Sale_unit *sale_unit);

void print_top_5_by_total_cost(Sale_unit *sale_unit);

void print_count_sales_per_category(Sale_unit *sale_unit);

void print_city_with_biggest_nr_of_sales_by_country(Sale_unit *sale_unit);

void print_monthly_revenue_by_year(Sale_unit *sale_unit);

void print_monthly_revenue_by_subcategory(Sale_unit *sale_unit);

int read_option();

List_options_struct *create_struct_of_options(List_option *list_options, int length);

void print_options(const List_options_struct *options);

#endif //SEM1_FUNCTIONS_H
