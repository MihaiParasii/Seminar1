//
// Created by Misha on 23.02.2024.
//

#ifndef SEM1_STRUCT_H
#define SEM1_STRUCT_H


enum Options_enum {
	PRINT_REVENUE_PER_MONTH = 1,
	PRINT_TOP_5_BY_TOTAL_COST = 2,
	PRINT_SALES_BY_CATEGORY = 3,
	PRINT_CITY_WITH_MAX_SALES_BY_COUNTRY = 4,
	PRINT_TRENDS_BY_SUBCATEGORY = 5,
	EXIT = 0,

};

typedef struct {
	char date[10];
	int id;
	char product_name[100];
	char product_category[100];
	char product_subcategory[100];
	float unit_price;
	int quantity_sold;
	char sale_country[100];
	char sale_city[100];
	float total_cost;
} Unit;

typedef struct {
	Unit *array;
	int length;
} Sale_unit;

typedef struct {
	char city[100];
	int nr_of_sales;
} City_struct;

typedef struct {
	float revenue;
	int count_sales;
} Data;

typedef struct Node {
	struct Node *next;
	Data *data;
} Node;

typedef struct {
	Node *head;
} List;


typedef struct List_option {
	char *label;
	enum Options_enum type;
} List_option;

typedef struct List_options_struct {
	List_option *list_options;
	size_t length;
} List_options_struct;

typedef int (*ComparatorPointer)(Unit *, Unit *);

#endif //SEM1_STRUCT_H
