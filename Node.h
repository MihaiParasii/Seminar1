#ifndef _NODE_H_
#define _NODE_H_

#include "Person.h"

typedef struct Node {
	int key;
	Person *person;
	struct Node *left;
	struct Node *right;
	int height;
} Node;

/**
 * Frees the memory allocated for a node and its associated person data.
 *
 * @param node The node to be freed.
 */
void free_node(Node *node);

/**
 * Creates a new node with the given person data.
 *
 * @param person The person data to be associated with the new node.
 * @return A pointer to the newly created node.
 */
Node *create_node(Person *person);

/**
 * Deletes a node from the tree and frees its memory.
 *
 * @param tree_node The node to be deleted.
 */
void delete_tree_node(Node *tree_node);

/**
 * Prints the data associated with a node.
 *
 * @param node The node whose data is to be printed.
 */
void print_node(Node *node);

/**
 * Deletes all nodes from the given node and its descendants, freeing their memory.
 *
 * @param current The node from which to start deleting.
 */
void delete_all_tree_nodes_from_node(Node *current);

#endif //_NODE_H_
