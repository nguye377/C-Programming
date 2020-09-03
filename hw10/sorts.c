#include <stdlib.h>
#include <stdio.h>
#include "sorts.h"

//Helper functions
int _comparation_helper(const void *, const void *);
BSTNode* _create_new_node(int data);
void _insert_BST_Node(BSTNode**, int); 
void _helper_free_tree(BSTNode**);
void _inorder_traversal_store(BSTNode**, int*, int* );
//------------------------------------------------------


int _comparation_helper(const void *left_int, const void *right_int) {
    return ( *(int*)left_int - *(int*)right_int );
}

void quick_sort_array(int* array, size_t size) {
    qsort(array, size, sizeof(array[0]), _comparation_helper);
}

void tree_sort_array(int* array, size_t size) {
    //Copy element from Array to Binary Tree
	int ind = 0; 
    BST bs_tree = create_bst(array, size);
	//_store_array(&bs_tree.root, array, &ind);
    _inorder_traversal_store(&bs_tree.root, array, &ind);
	empty_bst(&bs_tree);
	return;
}

//This function does traverse in BST and store in array
void _inorder_traversal_store(BSTNode** Root, int* array, int *index_ptr) {
	if (*Root == NULL) {
		return;
	}
    //Update the left subtre --Recursion
	if ((*Root) -> left != NULL) {
	    _inorder_traversal_store(&(*Root) -> left, array, index_ptr);
	}
    //Update array and  increase pointer
	array[*index_ptr] = (*Root) -> value;
	*index_ptr = *index_ptr + 1;
    //Update the right subtre --Recursion
	if ((*Root) -> right != NULL) {
	    _inorder_traversal_store(&(*Root) -> right, array, index_ptr);
	}
	return;
}

BST create_bst(const int* array, int size) {
	BST bs_tree = { .root = NULL, .size = size};
	if (size == 0) {
		return bs_tree;
	}
	else {
        int i = 0;
        while (i<size) {
            _insert_BST_Node(&bs_tree.root, array[i]); 
            i++; 
        }
	return bs_tree;
	}
}


BSTNode* _create_new_node(int data) {
	BSTNode* temp_node = malloc(sizeof(*temp_node));
	temp_node -> value = data;
	temp_node -> left = NULL;
	temp_node -> right = NULL;
	return temp_node;
}

void _insert_BST_Node(BSTNode** node, int key) {
	if (*node == NULL) {
		*node = _create_new_node(key);
		return;
	}
	if (key > (*node) -> value) {
		_insert_BST_Node(&((*node) -> right), key);
	}
	else if (key <= (*node) -> value) {
		_insert_BST_Node(&((*node) -> left), key);
    }
}

void empty_bst(BST* bst) {
    //do something
    _helper_free_tree(&bst -> root );
    //return;
}

void  _helper_free_tree(BSTNode** node) {
    if(*node != NULL) {
        _helper_free_tree(&(*node) -> left);
        _helper_free_tree(&(*node) -> right);
        // *node -> left  = NULL;
        // *node-> right = NULL;
        free(*node);
        *node = NULL;
    }
}

