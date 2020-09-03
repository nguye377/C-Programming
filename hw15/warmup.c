#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "print_bits.h"

/******************************************************************************************\
 * Instructions:
 *
 * Fill in each function, according to the description following the restrictions below.
 *
 * To compile this file use this command:
 * gcc -o warmup warmup.c print_bits.o
 *
 * RESTRICTIONS:
 * ∙ The body of every function must be exactly one statement, except for print_bits(…)
 *   which must be exactly 3 statements.
 * ∙ Do not use the constant 0xff in create_string_of_eight_1s().  Other functions are fine.
 *   In fact, you *should* use it in other functions.
 *
 * The comments in this file write numbers in bits like this:  11111111₂ or 10111010₂.
 *
 * C11 does not actually accept constants like that. When writing code that uses bit
 * manipulations, always write constants in hexadecimal notation (e.g., 0xff for 11111111₂,
 * 0xBA for 10111010₂), except zero, which you can write as either 0 or 0x00 (your choice).
 *
 * Note:  The last file ends with ".o" not ".c".  It is a compiled "object file".  We are
 * giving you code you can use to diagnose the correctness of your other code, while also
 * asking you to implement the print_bits(…)  function.
 * 
 * The two functions provided by print_bits.o are described in print_bits.h.
 *
 * You may add anything you like to the main(…) function.  If you do not want to use
 * the functions in print_bits.o, you may remove the #include "print_bits.h".
\******************************************************************************************/

uint8_t create_string_of_eight_1s() {
	// This function always returns 11111111₂.

	return 0xff;  // TODO:  Rewrite this to use 0x00 and a bitwise operator.
}

uint8_t create_string_of_0s_at_left(uint8_t num_0s) {
	// Examples:
	// ∙ create_string_of_0s_at_left(1) would return 01111111₂.
	// ∙ create_string_of_0s_at_left(2) would return 00111111₂.
	// ∙ create_string_of_0s_at_left(3) would return 00011111₂.
	// ∙ create_string_of_0s_at_left(0) would return 11111111₂.
	// ∙ create_string_of_0s_at_left(8) would return 00000000₂.

	return 0;  // TODO: replace this with a one-line implementation of this function.
}

uint8_t create_string_of_0s_at_right(uint8_t num_0s) {
	// Examples:
	// ∙ create_string_of_0s_at_right(1) would return 11111110₂.
	// ∙ create_string_of_0s_at_right(2) would return 11111100₂.
	// ∙ create_string_of_0s_at_right(3) would return 11111000₂.
	// ∙ create_string_of_0s_at_right(0) would return 11111111₂.
	// ∙ create_string_of_0s_at_right(8) would return 00000000₂.

	return 0;  // TODO: replace this with a one-line implementation of this function.
}


uint8_t create_string_of_1s_at_left(uint8_t num_1s) {
	// Examples:
	// ∙ create_string_of_1s_at_left(2) would return 11000000₂.
	// ∙ create_string_of_1s_at_left(0) would return 00000000₂.
	// ∙ create_string_of_1s_at_left(8) would return 11111111₂.

	return 0;  // TODO: replace this with a one-line implementation of this function.
}

uint8_t create_string_of_1s_at_right(uint8_t num_1s) {
	// Examples:
	// ∙ create_string_of_1s_at_right(2) would return 00000011₂.
	// ∙ create_string_of_1s_at_right(0) would return 00000000₂.
	// ∙ create_string_of_1s_at_right(8) would return 11111111₂.

	return 0;  // TODO: replace this with a one-line implementation of this function.
}

uint8_t set_left_bits(uint8_t byte, uint8_t num_bits_to_set) {
	// Examples:
	// ∙ set_left_bits(00000000₂, 2) would return 11000000₂.
	// ∙ set_left_bits(00001010₂, 2) would return 11001010₂.
	// ∙ set_left_bits(10101010₂, 2) would return 11101010₂.
	// ∙ set_left_bits(10101010₂, 0) would return 10101010₂.
	// ∙ set_left_bits(11111111₂, 0) would return 11111111₂.
	// ∙ set_left_bits(10101010₂, 8) would return 11111111₂.

	return 0;  // TODO: replace this with a one-line implementation of this function.
}

uint8_t set_right_bits(uint8_t byte, uint8_t num_bits_to_set) {
	// Examples:
	// ∙ set_right_bits(00000000₂, 2) would return 00000011₂.
	// ∙ set_right_bits(00001010₂, 2) would return 00001011₂.
	// ∙ set_right_bits(10101010₂, 2) would return 10101011₂.
	// ∙ set_right_bits(10101010₂, 0) would return 10101010₂.
	// ∙ set_right_bits(11111111₂, 0) would return 11111111₂.
	// ∙ set_right_bits(10101010₂, 8) would return 11111111₂.

	return 0;  // TODO: replace this with a one-line implementation of this function.
}

uint8_t unset_left_bits(uint8_t byte, uint8_t num_bits_to_unset) {
	// Examples:
	// ∙ unset_left_bits(00111111₂, 2) would return 00111111₂.
	// ∙ unset_left_bits(11110101₂, 2) would return 00110101₂.
	// ∙ unset_left_bits(01010101₂, 2) would return 00010101₂.
	// ∙ unset_left_bits(01010101₂, 1) would return 01010101₂.
	// ∙ unset_left_bits(00000000₂, 1) would return 00000000₂.
	// ∙ unset_left_bits(01010101₂, 8) would return 00000000₂.

	return 0;  // TODO: replace this with a one-line implementation of this function.

}

uint8_t unset_right_bits(uint8_t byte, uint8_t num_bits_to_unset) {
	// Examples:
	// ∙ unset_right_bits(11111111₂, 2) would return 11111100₂.
	// ∙ unset_right_bits(11110101₂, 2) would return 11110100₂.
	// ∙ unset_right_bits(01010101₂, 2) would return 01010100₂.
	// ∙ unset_right_bits(01010101₂, 1) would return 01010100₂.
	// ∙ unset_right_bits(00000000₂, 1) would return 00000000₂.
	// ∙ unset_right_bits(01010101₂, 8) would return 00000000₂.

	return 0;  // TODO: replace this with a one-line implementation of this function.
}

uint8_t toggle_left_bits(uint8_t byte, uint8_t num_bits_to_toggle) {
	// Examples:
	// ∙ toggle_left_bits(11111111₂, 2) would return 00111111₂.
	// ∙ toggle_left_bits(01011111₂, 4) would return 10101111₂.

	return 0;  // TODO: replace this with a one-line implementation of this function.
}

uint8_t toggle_right_bits(uint8_t byte, uint8_t num_bits_to_toggle) {
	// Examples:
	// ∙ toggle_right_bits(11111111₂, 2) would return 00111100₂.
	// ∙ toggle_right_bits(11110101₂, 4) would return 11111010₂.

	return 0;  // TODO: replace this with a one-line implementation of this function.
}


void print_bits(uint8_t bits) {
	// Print the bits in 'bits' as '0' and '1' characters.  Do not print a newline at the end.
	//
	// Example:
	// ∙ print_bits_plain(0xff) should output the same as
	//   → printf("11111111").
}

int main(int argc, char* argv[]) {
	printf("Print 10111010 to demonstrate color (m=magenta, y=yellow)\n");
	printf("expected: mmmyyyyy\nactual:   ");
	print_bits_color(0xba, 3, "magenta", "yellow");
	printf("\n");

	printf("create_string_of_eight_1s()\n");
	printf("expected: 11111111\nactual:   ");
	print_bits_plain(create_string_of_eight_1s());
	printf("\n");

	printf("create_string_of_1s_at_left(3)\n");
	printf("expected: 11100000\nactual:   ");
	print_bits_color(create_string_of_1s_at_left(3), 3, NULL, "green");
	printf("\n");

	printf("create_string_of_1s_at_right(3)\n");
	printf("expected: 00000111\nactual:   ");
	print_bits_color(create_string_of_1s_at_right(3), 5, NULL, "green");
	printf("\n");

	printf("set_left_bits(00000000₂, 2)\n");
	printf("expected: 11000000\nactual:   ");
	print_bits_color(set_left_bits(0x00, 2), 2, "green", NULL);
	printf("\n");

	printf("set_right_bits(00000000₂, 2)\n");
	printf("expected: 00000011\nactual:   ");
	print_bits_color(set_right_bits(0x00, 2), 6, NULL, "green");
	printf("\n");

	printf("unset_left_bits(11111111₂, 2)\n");
	printf("expected: 00111111\nactual:   ");
	print_bits_color(unset_left_bits(0xff, 2), 2, "green", NULL);
	printf("\n");

	printf("unset_right_bits(11111111₂, 2)\n");
	printf("expected: 11111100\nactual:   ");
	print_bits_color(unset_right_bits(0xff, 2), 6, NULL, "green");
	printf("\n");

	printf("toggle_left_bits(10101010₂, 4)\n");
	printf("expected: 01011010\nactual:   ");
	print_bits_color(toggle_left_bits(0xaa, 4), 4, "green", NULL); // 0xaa is 10101010₂
	printf("\n");

	printf("toggle_right_bits(10101010₂, 4)\n");
	printf("expected: 10100101\nactual:   ");
	print_bits_color(toggle_right_bits(0xaa, 4), 4, NULL, "green"); // 0xaa is 10101010₂
	printf("\n");

	return EXIT_SUCCESS;
}
#define __WARMUP_C_V2__
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
