#include <stdio.h>
#include <stdlib.h>

// This is an example of how to call a function with an array of constant strings, using
// a compound literal.
//
// You do not need to use this in any way to do the homework.  This is simply an example
// in a form that you can try directly.
//
// Author: Alexander J. Quinn (https://engineering.purdue.edu/~aq)

void print_limerick_array(const char* lines[5]) {
	for(int i = 0; i < 5; i++) {
		printf("%s\n", lines[i]);
	}
	printf("\n");
}

int main(int argc, char* argv[]) {
	print_limerick_array((const char*[5]) { "There was an Old Man with a beard,",
                                            "Who said, 'It is just as I feared!'",
                                            "Two Owls and a Hen,",
                                            "Four Larks and a Wren,",
                                            "Have all built their nests in my beard!'" } );
	
	// Equivalent to this:
	const char* limerick_as_array[5] = {
		"There was an Old Man with a beard,",
		"Who sat on a horse when he reared;",
		"But they said, 'Never mind!",
		"You will fall off behind,",
		"You propitious Old Man with a beard!"
	};
	print_limerick_array(limerick_as_array);

	return EXIT_SUCCESS;
}

#define CALL_FUNCTION_WITH_COMPOUND_LITERAL_C_VERSION 1
