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
    if(val_1 == val_2){
        int char_1 = ((TreeNode*) value1) -> character;
        int char_2 = ((TreeNode*) value2) -> character;
        return char_1 - char_2;
        
    }
    else
    {
        return val_1 - val_2;
    }
}
Node* make_huffman_pq(Frequencies freq) {
    Node* head = NULL;
    for(int i = 0; i<256; i++){
        if(freq[i] != 0){
            TreeNode* new_node =  malloc(sizeof(*new_node));
            *new_node = (TreeNode) {.character = i, .frequency = freq[i], .left= NULL, .right = NULL};
            pq_enqueue(&head, new_node, _cmp_int); 
        }
    }
    return head;
}