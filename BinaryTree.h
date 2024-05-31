#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "Node.h"

typedef struct BinaryTree {
	Node *root;
} BinaryTree;

typedef void (*ExecutionNode)(Node *);

typedef void (*TreeIterator)(Node *, ExecutionNode);

/**
 * Creates a new binary tree.
 * @return A pointer to the newly created binary tree.
 */
BinaryTree *create_tree();

/**
 * Clears the binary tree by removing all nodes.
 * @param tree The binary tree to be cleared.
 */
void clear_tree(BinaryTree *tree);

/**
 * Deletes the binary tree and frees all allocated memory.
 * @param tree The binary tree to be deleted.
 */
void delete_tree(BinaryTree *tree);

/**
 * Prints the binary tree using the provided tree iterator.
 * @param tree The binary tree to be printed.
 * @param tree_iterator The function to be called for each node during traversal.
 */
void print_tree(BinaryTree *tree, TreeIterator tree_iterator);

/**
 * Inserts a node into the binary tree.
 * @param tree The binary tree where the node will be inserted.
 * @param node The node to be inserted.
 */
void insert_node_in_tree(BinaryTree *tree, Node *node);

/**
 * Performs a depth-first search (DFS) in the binary tree to find a node with the given key.
 * @param tree The binary tree to be searched.
 * @param key The key to be searched for.
 * @return A pointer to the node with the given key, or NULL if not found.
 */
Node *DFS(BinaryTree *tree, int key);

/**
 * Imports data from a file into the binary tree.
 * @param file The name of the file to be imported.
 * @param binary_tree The binary tree where the data will be imported.
 */
void import_data_from_file_in_binary_tree(const char *file, BinaryTree *binary_tree);

/**
 * Gets the height of a node in the binary tree.
 * @param binary_tree The binary tree.
 * @param target_key The key of the node whose height will be calculated.
 * @return The height of the node with the given key, or -1 if not found.
 */
int get_height_of_node_in_binary_tree(BinaryTree *binary_tree, int target_key);

/**
 * Gets the depth of a node in the binary tree by its key.
 * @param binary_tree The binary tree.
 * @param target_key The key of the node whose depth will be calculated.
 * @return The depth of the node with the given key, or -1 if not found.
 */
int get_depth_of_node_in_tree_by_key(BinaryTree *binary_tree, int target_key);

/**
 * Prints all the leaves of the binary tree.
 * @param binary_tree The binary tree.
 */
void print_tree_leaves(BinaryTree *binary_tree);

/**
 * Performs a depth-first search (DFS) traversal in the binary tree, starting from the root,
 * using the "SDV" (Standard Depth-First Search) order.
 * @param curent The current node being visited.
 * @param execution_node The function to be called for each node during traversal.
 */
void SDV_initiator(Node *curent, ExecutionNode execution_node);

/**
 * Performs a depth-first search (DFS) traversal in the binary tree, starting from the root,
 * using the "SVD" (Standard Depth-First Search) order.
 * @param curent The current node being visited.
 * @param execution_node The function to be called for each node during traversal.
 */
void SVD_initiator(Node *curent, ExecutionNode execution_node);

/**
 * Performs a depth-first search (DFS) traversal in the binary tree, starting from the root,
 * using the "VSD" (Standard Depth-First Search) order.
 * @param curent The current node being visited.
 * @param execution_node The function to be called for each node during traversal.
 */
void VSD_initiator(Node *curent, ExecutionNode execution_node);

/**
 * Inserts a new node into the binary tree at the appropriate position.
 * @param curent The current node being visited.
 * @param new_node The new node to be inserted.
 */
void insert_node(Node *curent, Node *new_node);

/**
 * Performs a breadth-first search (BFS) traversal in the binary tree.
 * @param binary_tree The binary tree.
 */
void BFS_Executor(BinaryTree *binary_tree);

/**
 * Mirrors the binary tree by swapping the left and right children of each node.
 * @param binary_tree The binary tree to be mirrored.
 */
void mirror_tree(BinaryTree *binary_tree);

/**
 * Balances the binary tree by rearranging the nodes to achieve a more balanced structure.
 * @param binary_tree The binary tree to be balanced.
 * @return A pointer to the newly balanced binary tree.
 */
BinaryTree *balance_tree(BinaryTree *binary_tree);

#endif //_BINARYTREE_H_
