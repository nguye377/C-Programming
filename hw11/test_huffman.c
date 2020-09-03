#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"
/*
// int _cmp_int(const void* value1, const void* value2){
// 	char a = *(const int *)(value1);
// 	char b = *(const int *)(value2);	
// 	return a-b;	
// }

static int _cmp_int(const void* p1, const void* p2)
{
	return *(const int*)p1 - *(const int*)p2;
}

static int _cmp_string(const void* a_val1, const void* a_val2) {
	size_t len1 = strlen(a_val1); // No typecast needed!  Never use typedcast unless:
	size_t len2 = strlen(a_val2); // (a) necessary, (b) safe, and (c) well-understood.
	return len1 - len2; // shortest string comes forst
}

static char* _copy_str(const char* src_string) {
	size_t num_chars = strlen(src_string);
	char* dst_string = malloc(sizeof(*dst_string) * (num_chars + 1));
	return strcpy(dst_string, src_string);
}
static int* _copy_integer(const int scr_integer) {
	int* len_int = malloc(sizeof(*len_int));
	*len_int = (int) scr_integer;
	return len_int;
}

static void _destroy_string(void* string) {
	free(string);
}

int main(int argc, char* argv[]) {
	// Create a priority queue of four strings, ordered by length (ascending).
	Node* head = NULL;  // size 0
	// pq_enqueue(&head, _copy_string("potato"), _cmp_strings);  // size 1
	// pq_enqueue(&head, _copy_string("a"), _cmp_strings);  // size 2
    //----------------
    pq_enqueue(&head, _copy_str("potatoooo"), _cmp_string);  
	pq_enqueue(&head, _copy_str("is"),      _cmp_string);  
	pq_enqueue(&head,  _copy_str("are"), _cmp_string); 
	pq_enqueue(&head, _copy_str("a"),        _cmp_string);  
	pq_enqueue(&head, _copy_str("abcc"),   _cmp_string);  
	
	stack_push(&head,  _copy_str("potatoooo"));
	stack_push(&head,  _copy_str("is"));
	stack_push(&head,  _copy_str("are"));
	stack_push(&head,  _copy_str("a"));
	stack_push(&head,  _copy_str("abcc"));

	Node* temp_1 = stack_pop(&head);
	if(temp_1 != NULL) {
		free(temp_1->a_value);
		free(temp_1);
	}

	Node* temp_2 = pq_dequeue(&head);
	if(temp_2 != NULL) {
		free(temp_2 -> a_value);
		free(temp_2);
	}


	for(Node* curr = head; curr != NULL; curr = curr -> next) {
		printf("%s\n", (char*)(curr -> a_value));
	}

	// Deallocate all memory used by the list, including each node's payload.
	destroy_list(&head, _destroy_string);
	
	int arr[] = {12, 3, 4, 665, 4, 44, 154, 7};
	for(int i = 0; i<8; i++) {
		pq_enqueue(&head, _copy_integer(arr[i]), _cmp_int);
		printf("%d-", arr[i]);
	}
	destroy_list(&head, _destroy_string);

	return EXIT_SUCCESS;
}
*/
static int _cmp_strings_by_length(const void* a_lhs, const void* a_rhs) {
    size_t len_lhs = strlen(a_lhs); // No typecast needed!  Never use typedcast unless:
    size_t len_rhs = strlen(a_rhs); // (a) necessary, (b) safe, and (c) well-understood.
    return len_lhs - len_rhs; // shortest string comes forst
}

static void _destroy_string(void* string) {
    free(string);
}

static char* _copy_string(const char* src_string) {
    size_t num_chars = strlen(src_string);
    char* dst_string = malloc(sizeof(*dst_string) * (num_chars + 1));
    return strcpy(dst_string, src_string);
}

int main(int argc, char* argv[]) {
    // Create a priority queue of four strings, ordered by length (ascending).
    Node* head = NULL;  // size 0
    pq_enqueue(&head, _copy_string("Reginald"), _cmp_strings_by_length);  // size 1
    pq_enqueue(&head, _copy_string("was"),      _cmp_strings_by_length);  // size 2
    pq_enqueue(&head, _copy_string("a"),        _cmp_strings_by_length);  // size 3
    pq_enqueue(&head, _copy_string("hatter"),   _cmp_strings_by_length);  // size 4

    // Print contents of the list:  a was hatter Reginald
    for(Node* curr = head; curr != NULL; curr = curr -> next) {
        printf("%s\n", (char*)(curr -> a_value));
    }

    // Deallocate all memory used by the list, including each node's payload.
    destroy_list(&head, _destroy_string);

    return EXIT_SUCCESS;
}

#define DEMO_HUFFMAN_C_V1
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
