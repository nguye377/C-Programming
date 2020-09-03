#ifndef __HUFFMAN_H_V1__
#define __HUFFMAN_H_V1__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "priority_queue.h"
#include "frequencies.h"
#include "bit_writer.h"

typedef struct TreeNode {
    uchar character;
    size_t frequency; 
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

Node* make_huffman_pq(Frequencies freq);
TreeNode* make_huffman_tree(Node* head);
void destroy_huffman_tree(TreeNode** a_root);
//void _helper_print(TreeNode* tree, uchar* bin, int i);
void _helper_print(TreeNode* tree);
void write_coding_table(TreeNode* root, BitWriter* a_writer);

#endif
