#ifndef __SORTS_H__
#define __SORTS_H__
#include <stdlib.h>
#include <stdio.h>

typedef struct BST_Node{
	int value;
	struct BST_Node* left;
	struct BST_Node* right;
} BSTNode;

typedef struct {
	int size;
	BSTNode* root;

} BST;

void tree_sort_array(int* array, size_t size);
void quick_sort_array(int* array, size_t size);
BST create_bst(const int* array, int size);
void empty_bst(BST* bst);

#endif
