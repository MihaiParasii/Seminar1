#ifndef _STRUCT_H_
#define _STRUCT_H_

enum MainOptionsEnum {
	MAIN_EXIT = 0,
	MAIN_PRINT_TREE = 1,
	MAIN_PRINT_LEAVES = 2,
	MAIN_SEARCH_NODE = 3,
	MAIN_HEIGHT_OF_TREE = 4,
	MAIN_DEPTH_OF_NODE = 5,
	MAIN_HEIGHT_OF_NODE = 6,
	MAIN_BALANCE_TREE = 7,
	MAIN_MIRROR_TREE = 8,
};

enum TypeCrossingTreeEnum {
	INORDER = 1,
	POSTORDER = 2,
	PREORDER = 3,
	IN_INPUT_ORDER = 4,
	BFS = 5,
};

typedef union OptionsType {
	enum TypeCrossingTreeEnum type_crossing_tree_enum;
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

#endif //_STRUCT_H_
