#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"

// DO NOT COPY CODE FROM THIS FILE INTO YOUR OWN CODE.  We are providing this
// only to clarify how the pieces are supposed to fit together.  It would not
// be a good basis for your test_huffman.c.

static int _cmp_strings_by_length(const void* a_lhs, const void* a_rhs) {
	size_t len_lhs = strlen(a_lhs); // No typecast needed!  Never use typedcast unless:
	size_t len_rhs = strlen(a_rhs); // (a) necessary, (b) safe, and (c) well-understood.
	return len_lhs - len_rhs; // shortest string comes forst
}

static char* _copy_string(const char* src_string) {
	size_t num_chars = strlen(src_string);
	char* dst_string = malloc(sizeof(*dst_string) * (num_chars + 1));
	return strcpy(dst_string, src_string);
}

static void _destroy_string(void* string) {
	free(string);
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

/* ______
 * Output
 * ‾‾‾‾‾‾
 * a
 * was
 * hatter
 * Reginald
 */

#define DEMO_HUFFMAN_C_V1
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
