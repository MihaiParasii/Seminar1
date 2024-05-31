#include "includes.h"
#include "Node.h"

Node *create_node(Person *person) {
	Node *tree_node = calloc(sizeof(Node), 1);
	tree_node->person = person;
	return tree_node;
}
void delete_tree_node(Node *tree_node) {
	if (tree_node) {
		free(tree_node);
	}
}

void delete_all_tree_nodes_from_node(Node *curent) {
	if (curent) {
		delete_all_tree_nodes_from_node(curent->left);
		delete_all_tree_nodes_from_node(curent->right);
		delete_tree_node(curent);
	}
}

void insert_node(Node *curent, Node *new_node) {
	assert(curent);

	if (curent->key > new_node->key) {
		if (curent->left) {
			insert_node(curent->left, new_node);
		} else {
			curent->left = new_node;
		}
	} else {
		if (curent->right) {
			insert_node(curent->right, new_node);
		} else {
			curent->right = new_node;
		}
	}

}

void print_node(Node *node) {
	assert(node);
	print_person(node->person);
}

void free_node(Node *node) {
	assert(node);

	free_person(node->person);
	free(node);
}