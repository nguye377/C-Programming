#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

// print_array_like_circular_list.c
//
// Print an array of strings using the same formatting required for the
// print_circular_list(…) function
//
// This code is not required to do the homwork.  It is provided "as is" in hopes
// that it may reduce your time fussing with box-drawing characters and logic.
//
// To enter the box-drawing characters in Vim without copying from this file,
// press Ctrl-k d r, Ctrl-k d l, Ctrl-k u r, Ctrl-k u l, and Ctrl-k h h.
//
// Box drawing characters don't look right?
// ∙ If you are using an editor other than Vim, set it to UTF-8.
// ∙ Make sure PuTTY (or Mac/Linux terminal) are set to UTF-8.
//   (This was included in the original setup you did in week 1.)
//
// Author: Alexander J. Quinn (https://engineering.purdue.edu/~aq)
//
// You may copy/adapt any code in this file for HW07 of ECE 26400 Spring 2020.


void print_array_like_circular_list(char** names, size_t num_names) {
	//__________________________________________________
	// UPPER LEVEL

	// Print upper-left corner
	printf("┌"); // Character:  "box drawings light down and right"

	// Print each name, wrapped in ‘["▒"]’, separated by horizontal line ‘─’.
	int total_width = 1;
	for(int name_idx = 0; name_idx < num_names; name_idx++) {

		// Print the name, wrapped in ‘["▒"]’.
		printf("[\"%s\"]", names[name_idx]);
		total_width += strlen(names[name_idx]) + 5; // 5 for wrapper + separator
		// If not last element…
		if(name_idx < num_names - 1) { 
			// Print separator ‘─’ and increment counter for the lines below.
			printf("─"); // Character: "box drawings light horizontal"
		}
	}

	//__________________________________________________
	// LOWER LEVEL

	// Print upper left corner
	printf("┐\n");

	// Print horizontal lines
	printf("└");
	int num_horizontal_lines = total_width - 2;
	for(int name_idx = 0; name_idx < num_horizontal_lines; name_idx++) {
		printf("─"); // Character: "box drawings light horizontal"
	}

	// Print lower right corner
	printf("┘\n");
}


int main(int argc, char* argv[]) {
	char* names[] = {"Alice", "Bob", "Charlie"};
	printf("%lu\n" , sizeof(names[0]));
	printf("%lu\n" , sizeof(names));
	size_t num_names = sizeof(names) / sizeof(names[0]);
	
	print_array_like_circular_list(names, num_names);

	return EXIT_SUCCESS;
}

#define PRINT_ARRAY_LIKE_CIRCULAR_LIST_C_VERSION 1

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
