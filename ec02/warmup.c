#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

/* TODO:  Create a worker function to go with zero_array(..) */

bool zero_array(int* array, int array_length, int num_threads, const char** a_error) {
	/* Given an array, set every element to 0 using multiple threads.
	 *
	 * - If successful, return true and, if a_error != NULL, set *a_error = NULL.
	 *
	 * - In case of any failure, return false and, if a_error != NULL,
	 *   set *a_error to the address of an error message on the data segment.
	 */
	return true; /* TODO: finish this function and remove this stub */
}

int main(int argc, char* argv[]) {
	int num_threads = 4;

	int array[16] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	int array_length = sizeof(array)/sizeof(*array);

	for(int i=0; i<array_length; i++) {
		assert(array[i] == 2);
	}

	const char* error = NULL;
	bool did_succeed = zero_array(array, array_length, num_threads, &error);
	if(did_succeed) {
		for(int i=0; i<array_length; i++) {
			assert(array[i] == 0);
		}
		return EXIT_SUCCESS;
	}
	else {
		fprintf(stderr, "%s\n", error);
		return EXIT_FAILURE;
	}
}

// Updated 4/17/2019 7:52 PM:  Error message should be on the DATA SEGMENT.

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
