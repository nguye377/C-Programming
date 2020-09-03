#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "priority_queue.h"
#include "frequencies.h"
#include "huffman.h"

static int _cmp_int(const void* value1, const void* value2) {
    int val_1 = ((TreeNode*) value1)-> frequency;
    int val_2 = ((TreeNode*) value2)-> frequency;
    if(val_1 != val_2){
        return val_1 -  val_2;        
    }
    else {
        int char_1 = ((TreeNode*) value1) -> character;
        int char_2 = ((TreeNode*) value2) -> character;
	    if(char_1 == '\0') {
		    return 1;
	    }
        return char_1 - char_2;//return 0
    }
}

Node* make_huffman_pq(Frequencies freq) {
    // if(freq == NULL) {
    //     return NULL;
    // }
    Node* head = NULL;
    for(int i = 0; i<256; i++){
        if(freq[i] != 0){
            TreeNode* new_node =  malloc(sizeof(*new_node));
            // if(new_node == NULL) {
            //     return NULL;
            // }
            *new_node = (TreeNode) {.character = i, 
                                    .frequency = freq[i], 
                                    .left= NULL, 
                                    .right = NULL};
            pq_enqueue(&head, new_node, _cmp_int); 
        }
    }
    return head;
}

TreeNode* make_huffman_tree(Node* head) {
	// if(head == NULL) {
	// 	return NULL;
	// }
    	while(head -> next != NULL) {
        Node* left = pq_dequeue(&head);
        Node* right = pq_dequeue(&head);
        TreeNode* left_tree = left -> a_value;
        TreeNode* right_tree = right -> a_value;
        TreeNode* parent  = malloc(sizeof(*parent));
	    // if(parent == NULL) {
		//     return NULL;
	    // }
        *parent = (struct TreeNode) {.character = '\0',
                                     .frequency = (left_tree -> frequency)+ (right_tree -> frequency),
                                     .left = left_tree,
                                     .right = right_tree}; 
        free(left);
	    free(right);
        pq_enqueue(&head, parent, _cmp_int);
        //head = head -> next;    
    }
    TreeNode* a_head = a_head = head -> a_value;
    free(head);
    
    return a_head;
}

void destroy_huffman_tree(TreeNode** a_root) {
    if((*a_root) == NULL) {
        free((*a_root));
        return;
    }
    destroy_huffman_tree(&(*a_root)->left);
    destroy_huffman_tree(&(*a_root)->right);
    free(*a_root);
    *a_root = NULL;
    return;
}

void _helper_print(TreeNode* tree) {
    if(tree == NULL){
        return;
     }
    _helper_print(tree->left);
    _helper_print(tree->right);
    if(tree -> character != 0) {
        printf("%c: %ld\n", tree->character, tree -> frequency);
    }
}

