#include <stdbool.h>
#include <stdio.h>
#include "funcs.h"
#include "BinaryTree.h"

int main() {
	ListOption _main_options[] = {{"Print binary tree",        MAIN_PRINT_TREE},
	                              {"Print tree leaves",        MAIN_PRINT_LEAVES},
	                              {"Search node by key",       MAIN_SEARCH_NODE},
	                              {"Print get_height of tree", MAIN_HEIGHT_OF_TREE},
	                              {"Print depth of node",      MAIN_DEPTH_OF_NODE},
	                              {"Print get_height of node", MAIN_HEIGHT_OF_NODE},
	                              {"Balance binary tree",      MAIN_BALANCE_TREE},
	                              {"Mirror binary tree",       MAIN_MIRROR_TREE},
	                              {"EXIT",                     MAIN_EXIT}};

	ListOption _crossing_tree_options[] = {{"LEFT NODE RIGHT", INORDER},
	                                       {"LEFT RIGHT NODE", POSTORDER},
	                                       {"NODE LEFT RIGHT", PREORDER},
	                                       {"IN INPUT ORDER",  IN_INPUT_ORDER},
	                                       {"BFS",             BFS}};

	const ListOptionsStruct *main_options = create_struct_of_options(_main_options,
	                                                                 sizeof(_main_options) / sizeof(ListOption));
	const ListOptionsStruct *crossing_tree_options = create_struct_of_options(_crossing_tree_options,
	                                                                          sizeof(_crossing_tree_options)
	                                                                          / sizeof(ListOption));

	int choice;
	int type_of_crossing_tree;
	bool execution = true;

	BinaryTree *binary_tree = create_tree();
	import_data_from_file_in_binary_tree("/Users/admin/Downloads/UTM/SDA/Laborator/Lab3/persons.txt", binary_tree);

	while (execution) {
		print_options(main_options);
		choice = read_option();
		switch (choice) {
			case MAIN_PRINT_TREE: {
				print_options(crossing_tree_options);
				type_of_crossing_tree = read_option();
				switch (type_of_crossing_tree) {
					case INORDER: {
						print_tree(binary_tree, SVD_initiator);
						break;
					}
					case POSTORDER: {
						print_tree(binary_tree, SDV_initiator);
						break;
					}
					case PREORDER: {
						print_tree(binary_tree, VSD_initiator);
						break;
					}
					case BFS: {
						BFS_Executor(binary_tree);
                        break;
					}
					default: {
						printf("You choose wrong type of crossing tree\n");
						break;
					}
				}
				break;
			}
			case MAIN_HEIGHT_OF_TREE: {
				int height = get_height_of_node_in_binary_tree(binary_tree, binary_tree->root->key);
				printf("Height of tree: %d\n", height);

				break;
			}
			case MAIN_DEPTH_OF_NODE: {
				int node_key;
				read_key(&node_key);
				int height = get_depth_of_node_in_tree_by_key(binary_tree, node_key);
				printf("Depth of node with key %d: %d\n", node_key, height);
				break;
			}
			case MAIN_HEIGHT_OF_NODE: {
				int node_key;
				read_key(&node_key);
				int height = get_height_of_node_in_binary_tree(binary_tree, node_key);
				printf("Height of node with key %d: %d\n", node_key, height);
				break;
			}
			case MAIN_SEARCH_NODE: {
				int node_key;
				read_key(&node_key);
				const Node *node = DFS(binary_tree, node_key);
				if (node) {
					printf("Node with key %d found\n", node_key);
					print_node(node);
				} else {
					printf("Node with key %d not found\n", node_key);
				}
				break;
			}
			case MAIN_PRINT_LEAVES: {
				print_tree_leaves(binary_tree);
				break;
			}
			case MAIN_BALANCE_TREE: {
				balance_tree(binary_tree);
				break;
			}
			case MAIN_EXIT: {
				execution = false;
				break;
			}
			default: {
				printf("You choose wrong option\n");
			}
		}
	}

	delete_tree(binary_tree);
}