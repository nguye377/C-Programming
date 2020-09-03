#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "priority_queue.h"
#include "frequencies.h"
#include "huffman.h"
#include "mmintrin.h"
#include "bit_writer.h"
#include "clog.h"
// //-----This function is used for HW13 to delete the linked list---------
// static void _destroy(void* head){ 
//     free(head);
// }
// //----------------------------------------------------------------------

int main(int argc, char* argv[]) {
    Frequencies freqs = {0};
    const char* path = "expected.txt";
    const char* a_error = "abc";
    //compute the frequencies to return th value
    calc_frequencies(freqs, path, &a_error);
	for (int i = 0; i < 256; i++)
	{
		if(freqs[i]!=0);
		//printf("Character: %c: %ld\n", i, freqs[i]);
	}
    Node* head = make_huffman_pq(freqs);
    for(Node* temp = head; temp != NULL; temp = temp -> next) {
        TreeNode* value = temp ->a_value;
        //print the char and the frequencies
		
        printf("%c: %ld\n", value->character, value->frequency);
    }

    printf("Huffman Tree\n");
    printf("-------------------\n");
    TreeNode* tree_head = NULL;
    tree_head = make_huffman_tree(head);

    // //-----The line below to print and test the huffman tree-------
    // _helper_print(tree_head);
    // //-------------------------------------------------------------

    // //-----This line for freeing the linked-list in HW13-----------
    // destroy_list(&head, _destroy); 
    // //-------------------------------------------------------------
    // //------This line for freeing the Huffman tree in HW14---------
    // destroy_huffman_tree(&tree_head); 
    // //-------------------------------------------------------------

    //-----Testing for HW16-------------------------------------------
    BitWriter writer = open_bit_writer("output_test");
    write_coding_table(tree_head, &writer);
    close_bit_writer(&writer);

    FILE* fp = fopen("output_test", "r");
    if(fp == NULL) {
        printf("Cannot open the file\n");
        exit(0);
    }
    //Open the file and check
    fclose(fp);
    destroy_huffman_tree(&tree_head); 
    return EXIT_SUCCESS;
}
