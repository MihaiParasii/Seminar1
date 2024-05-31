#include <time.h>
#include "BinaryTree.h"
#include "includes.h"

BinaryTree *create_tree() {
	BinaryTree *local = calloc(sizeof(BinaryTree *), 1);
	return local;
}

void clear_tree(BinaryTree *tree) {
	assert(tree);

	if (tree->root) {
		delete_all_tree_nodes_from_node(tree->root);
		tree->root = NULL;
	}
}

void delete_tree(BinaryTree *tree) {
	assert(tree);

	clear_tree(tree);
	free(tree);
}

void insert_node_in_tree(BinaryTree *tree, Node *node) {
	if (!tree) {
		return;
	}

	if (tree->root) {
		insert_node(tree->root, node);
	} else {
		tree->root = node;
	}

}

void print_tree(BinaryTree *tree, TreeIterator tree_iterator) {
	assert(tree);
	assert(tree_iterator);

	if (tree->root) {
		printf("\n Elementele arborelui:\n");
		tree_iterator(tree->root, print_node);
	} else {
		printf("Arborele este vid");
	}
}

Node *DFS_helper(Node *current, int key) {
	if (!current) {
		return NULL;
	}

	if (current->key == key) {
		return current;
	}

	Node *tmp = DFS_helper(current->left, key);
	return tmp ? tmp : DFS_helper(current->right, key);
}

Node *DFS(BinaryTree *tree, int key) {
	if (!tree) {
		return NULL;
	}
	if (!tree->root) {
		return NULL;
	}

	return DFS_helper(tree->root, key);
}

void *_read_person_form_file(FILE *file) {
	assert(file);

	Person *person = create_person();

	fscanf(file, "%10s %u %u %u %10s",
	       person->name,
	       &(person->age),
	       &(person->height),
	       &(person->year_of_birth),
	       person->occupation);

	return person;
}

void import_data_from_file_in_binary_tree(const char *file, BinaryTree *binary_tree) {
	assert(file);
	assert(binary_tree);

	FILE *file_ptr = fopen(file, "r");

	assert(file_ptr);

	srand(time(NULL));

	int key;
//	int key = 0;
//	int start = 1;

	while (!feof(file_ptr)) {
		key = rand() % 100;
		printf("key: %d\n", key);
//		if (start == 1) {
//			key = 0;
//			start++;
//		}
		Person *person = _read_person_form_file(file_ptr);
		Node *new_node = create_node(person);
		new_node->key = key;
		insert_node_in_tree(binary_tree, new_node);

	}

	fclose(file_ptr);
}

int get_depth_of_node_in_tree_by_key_helper(Node *node, int target_key) {
	if (node == NULL)
		return -1;

	int depth = -1;

	if (node->key == target_key) {
		return depth + 1;
	}

	depth = get_depth_of_node_in_tree_by_key_helper(node->left, target_key);
	if (depth >= 0) {
		return depth + 1;
	}

	depth = get_depth_of_node_in_tree_by_key_helper(node->right, target_key);
	if (depth >= 0) {
		return depth + 1;
	}

	return -1;
}

int get_depth_of_node_in_tree_by_key(BinaryTree *binary_tree, int target_key) {
	return get_depth_of_node_in_tree_by_key_helper(binary_tree->root, target_key);
}

int find_height_of_node_in_binary_tree_helper(Node *node, int target_key, int *height_to_target_node) {
	if (node == NULL) {
		return -1;
	}

	int left_height = find_height_of_node_in_binary_tree_helper(node->left, target_key, height_to_target_node);

	int right_height = find_height_of_node_in_binary_tree_helper(node->right, target_key, height_to_target_node);

	int current_height;

	if (left_height > right_height) {
		current_height = left_height + 1;
	} else {
		current_height = right_height + 1;
	}

	if (node->key == target_key) {
		*height_to_target_node = current_height;
	}

	return current_height;
}

int get_height_of_node_in_binary_tree(BinaryTree *binary_tree, int target_key) {
	int height_to_target_node = -1;

	find_height_of_node_in_binary_tree_helper(binary_tree->root, target_key, &height_to_target_node);

	return height_to_target_node;
}

void show_tree_leaves_helper(Node *node) {
	if (!node) {
		return;
	}

	if (!node->left && !node->right) {
		print_node(node);
		return;
	}

	show_tree_leaves_helper(node->left);
	show_tree_leaves_helper(node->right);
}

void print_tree_leaves(BinaryTree *binary_tree) {
	printf("\nLeaves of binary tree:\n");
	show_tree_leaves_helper(binary_tree->root);
}

void SDV_initiator(Node *curent, ExecutionNode execution_node) {
	if (curent) {
		SDV_initiator(curent->left, execution_node);
		SDV_initiator(curent->right, execution_node);
		execution_node(curent);
	}
}

void SVD_initiator(Node *curent, ExecutionNode execution_node) {
	if (curent) {
		SVD_initiator(curent->left, execution_node);
		execution_node(curent);
		SVD_initiator(curent->right, execution_node);
	}
}

void VSD_initiator(Node *curent, ExecutionNode execution_node) {

	if (curent) {
		execution_node(curent);
		VSD_initiator(curent->left, execution_node);
		VSD_initiator(curent->right, execution_node);
	}
}

void bfs_traversal_helper(Node *node) {
	if (node == NULL)
		return;

	Node *queue[1000];
	int front = 0;
	int rear = 0;
	queue[rear++] = node;

	while (front < rear) {
		Node *current = queue[front++];
		print_node(current);

		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
}

void BFS_Executor(BinaryTree *binary_tree) {
	printf("BFS transversal:\n");
	bfs_traversal_helper(binary_tree->root);
}

void mirror_tree_helper(Node *root) {
	if (root == NULL)
		return;

	Node *temp = root->left;
	root->left = root->right;
	root->right = temp;

	mirror_tree_helper(root->left);
	mirror_tree_helper(root->right);
}

void mirror_tree(BinaryTree *binary_tree) {
	mirror_tree_helper(binary_tree->root);
}

int get_height(Node *node) {
	if (node == NULL) {
		return 0;
	}
	return node->height;
}

void update_height(Node *node) {
	int left_height = get_height(node->left);
	int right_height = get_height(node->right);
	node->height = (left_height > right_height ? left_height : right_height);
}

int get_balance_factor(Node *node) {
	if (node == NULL) {
		return 0;
	}
	return get_height(node->left) - get_height(node->right);
}

Node *left_rotate(Node *node) {
	Node *y = node->right;
	Node *T2 = y->left;

	y->left = node;
	node->right = T2;

	update_height(node);
	update_height(y);

	return y;
}

Node *right_rotate(Node *node) {
	Node *x = node->left;
	Node *T2 = x->right;

	x->right = node;
	node->left = T2;

	update_height(node);
	update_height(x);

	return x;
}

Node *balance_node(Node *node) {
	update_height(node);

	int balance = get_balance_factor(node);

	if (balance > 1) {
		if (get_balance_factor(node->left) >= 0)
			return right_rotate(node);
		else {
			node->left = left_rotate(node->left);
			return right_rotate(node);
		}
	}
	if (balance < -1) {
		if (get_balance_factor(node->right) <= 0)
			return left_rotate(node);
		else {
			node->right = right_rotate(node->right);
			return left_rotate(node);
		}
	}
	return node;
}

BinaryTree *balance_tree(BinaryTree *binary_tree) {
	if (binary_tree->root == NULL) {
        return binary_tree;
    }

    Node *new_root = balance_node(binary_tree->root);
    binary_tree->root = new_root;

    return binary_tree;
}
