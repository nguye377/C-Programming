#ifndef __HUFFMAN_H_V1__
#define __HUFFMAN_H_V1__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "priority_queue.h"
#include "frequencies.h"

typedef struct TreeNode {
    uchar character;
    size_t frequency; 
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

Node* make_huffman_pq(Frequencies freq);

#endif