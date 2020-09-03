#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "priority_queue.h"
#include "frequencies.h"
#include "huffman.h"
#include "mmintrin.h"

static void _destroy(void* head){ 
    free(head);
}
int main(int argc, char* argv[]) {
    Frequencies freqs = {0};
    const char* path = "expected.txt";
    const char* a_error = "abc";
    //compute the frequencies to return th value
    calc_frequencies(freqs, path, &a_error);
    Node* head = make_huffman_pq(freqs);
    for(Node* temp = head; temp != NULL; temp = temp -> next) {
        TreeNode* value = temp ->a_value;
        //print the char and the frequencies
        printf("%c: %ld\n", value->character, value->frequency);
    }
    destroy_list(&head, _destroy);
    return EXIT_SUCCESS;
}