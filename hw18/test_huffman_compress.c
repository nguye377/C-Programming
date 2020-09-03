// © 2020  Alexander J Quinn 2020.  All Rights Reserved.
//         This content is protected and may not be shared, uploaded, or distributed.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "miniunit.h"
#include "huffman_compress.h"
#include "simple_file_utilities.h"

const char* _IN_PATH   = "dummy.txt";
const char* _OUT_PATH  = "dummy.txt.hc";
const char* _DUMMY_MSG = "This file is used by " __FILE__ ".";


static void _write_dummy_file(const char* path, const char contents[]);
static bool _check_file_contents(const char* path, const uint8_t* bytes, size_t num_bytes);

static int _test_input_file_non_existant() {
	mu_start();
	//────────────────────

	// Remove both input and output files, if they exist.
	remove_file_if_exists(_IN_PATH);
	remove_file_if_exists(_OUT_PATH);

	// Set up and check command line arguments
	const char* argv[] = { "./huffman_compress", "MISSING.txt", "MISSING.txt.hc" };
	int argc = sizeof(argv) / sizeof(*argv); // only works for stack array declared with []
	const char* error_msg = check_command_line_arguments(argc, argv);
	mu_check(strcmp(error_msg, ERROR_MSG_INPUT_PATH_DOES_NOT_EXIST) == 0);

	//────────────────────
	mu_end();
}


static int _test_wrong_number_of_arguments() {
	mu_start();
	//────────────────────

	// Set up in_path and out_path
	_write_dummy_file(_IN_PATH, _DUMMY_MSG);
	remove_file_if_exists(_OUT_PATH);

	// Set up command line arguments
	const char* argv[] = { "./huffman_compress", "MISSING.txt", "MISSING.txt.hc", "a", "b" };

	// Pretend there are no arguments
	const char* error_msg = check_command_line_arguments(2, argv);
	mu_check(strcmp(error_msg, ERROR_MSG_USAGE) == 0);

	// Pretend there are only 1 argument
	error_msg = check_command_line_arguments(2, argv);
	mu_check(strcmp(error_msg, ERROR_MSG_USAGE) == 0);

	// Pretend there are 2 argument (correct number)
	error_msg = check_command_line_arguments(2, argv);
	mu_check(error_msg == NULL);

	// Pretend there are 3 arguments (too many)
	error_msg = check_command_line_arguments(4, argv);
	mu_check(strcmp(error_msg, ERROR_MSG_USAGE) == 0);

	// Pretend there are 4 arguments (too many)
	error_msg = check_command_line_arguments(5, argv);
	mu_check(strcmp(error_msg, ERROR_MSG_USAGE) == 0);

	//────────────────────
	mu_end();
}


static int _test_input_file_unreadable() {
	mu_start();
	//────────────────────

	remove_file_if_exists(_OUT_PATH);

	// Set up and check command line arguments
	const char* argv[] = { "./huffman_compress", "/etc/shadow", _OUT_PATH };
	int argc = sizeof(argv) / sizeof(*argv); // only works for stack array declared with []
	const char* error_msg = check_command_line_arguments(argc, argv);
	mu_check(strcmp(error_msg, ERROR_MSG_INPUT_PATH_NOT_READABLE) == 0);

	//────────────────────
	mu_end();
}


static int _test_input_file_not_file() {
	mu_start();
	//────────────────────

	remove_file_if_exists(_OUT_PATH);

	// Set up and check command line arguments
	const char* argv[] = { "./huffman_compress", "/tmp", _OUT_PATH };
	int argc = sizeof(argv) / sizeof(*argv); // only works for stack array declared with []
	const char* error_msg = check_command_line_arguments(argc, argv);
	mu_check(strcmp(error_msg, ERROR_MSG_INPUT_PATH_NOT_A_FILE) == 0);

	//────────────────────
	mu_end();
}


static int _test_output_dir_not_writable() {
	mu_start();
	//────────────────────

	_write_dummy_file(_IN_PATH, "");

	// Set up and check command line arguments
	const char* argv[] = { "./huffman_compress", _IN_PATH, "/usr" };
	int argc = sizeof(argv) / sizeof(*argv); // only works for stack array declared with []
	const char* error_msg = check_command_line_arguments(argc, argv);
	mu_check(strcmp(error_msg, ERROR_MSG_OUTPUT_DIR_NOT_WRITABLE) == 0);

	//────────────────────
	mu_end();
}


static int _test_output_path_blank() {
	mu_start();
	//────────────────────

	_write_dummy_file(_IN_PATH, "");

	// Set up and check command line arguments
	const char* argv[] = { "./huffman_compress", _IN_PATH, "" };
	int argc = sizeof(argv) / sizeof(*argv); // only works for stack array declared with []
	const char* error_msg = check_command_line_arguments(argc, argv);
	mu_check(strcmp(error_msg, ERROR_MSG_OUTPUT_PATH_BLANK) == 0);

	//────────────────────
	mu_end();
}


static int _test_input_path_blank() {
	mu_start();
	//────────────────────

	remove_file_if_exists(_OUT_PATH);

	// Set up and check command line arguments
	const char* argv[] = { "./huffman_compress", "", _OUT_PATH };
	int argc = sizeof(argv) / sizeof(*argv); // only works for stack array declared with []
	const char* error_msg = check_command_line_arguments(argc, argv);
	mu_check(strcmp(error_msg, ERROR_MSG_INPUT_PATH_BLANK) == 0);

	//────────────────────
	mu_end();
}


static int _test_output_path_exists() {
	mu_start();
	//────────────────────

	// Set up in_path and out_path
	_write_dummy_file(_IN_PATH, "");
	_write_dummy_file(_OUT_PATH, "");

	// Set up and check command line arguments
	const char* argv[] = { "./huffman_compress", "", _OUT_PATH };
	int argc = sizeof(argv) / sizeof(*argv); // only works for stack array declared with []
	const char* error_msg = check_command_line_arguments(argc, argv);
	mu_check(strcmp(error_msg, ERROR_MSG_OUTPUT_PATH_EXISTS) == 0);

	//────────────────────
	mu_end();
}


static int _test_empty_input_file() {
	mu_start();
	//────────────────────

	// Set up in_path and out_path
	_write_dummy_file(_IN_PATH, "");
	remove_file_if_exists(_OUT_PATH);

	// Set up and check command line arguments
	const char* argv[] = { "./huffman_compress", _IN_PATH, _OUT_PATH };
	int argc = sizeof(argv) / sizeof(*argv); // only works for stack array declared with []
	const char* error_msg = check_command_line_arguments(argc, argv);
	mu_check(error_msg == NULL);

	// Check contents of file
	uint8_t expected[] = { 0x05, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00 };
	size_t num_bytes = sizeof(expected) / sizeof(*expected);  // only for array on stack!!!
	_check_file_contents(_IN_PATH, expected, num_bytes);

	//────────────────────
	mu_end();
}


static int _test_huffman_fluffs_many_mums() {
	mu_start();
	//────────────────────

	// Set up in_path and out_path
	const char* message = "huffman fluffs many mums";
	_write_dummy_file(_IN_PATH, message);
	remove_file_if_exists(_OUT_PATH);

	// Set up and check command line arguments
	const char* argv[] = { "./huffman_compress", _IN_PATH, _OUT_PATH };
	int argc = sizeof(argv) / sizeof(*argv); // only works for stack array declared with []
	const char* error_msg = check_command_line_arguments(argc, argv);
	mu_check(error_msg == NULL);

	// Check contents of file
	uint8_t expected[] = {
		// Metadata (12 bytes)
		0x00, 0x00, 0x00, 0x00,   // metadata.compressed_file_size_bytes
		0x0a, 0x00, 0x00, 0x00,   // metadata.coding_table_size_bytes
		0x00, 0x00, 0x00, 0x00,   // metadata.uncompressed_file_size_bytes

		// Coding table, including the tailing 0 bit (13 bytes)
		0xb3, // 10110011
		0x5a, // 01011010
		0x2d, // 00101101
		0x89, // 10001001
		0x01, // 00000001
		0x5d, // 01011101
		0x6f, // 01101111
		0x36, // 00110110
		0x12, // 00010010
		0xdb, // 11011011
		0x6e, // 01101110
		0xb9, // 10111001
		0x88, // 10001000

		// Payload (10 bytes)
		0x48, // 01001000   h___u__f
		0x1a, // 00011010   _f_m__a_
		0xf9, // 11111001   __n___ _
		0x8b, // 10001011   _f_l___u
		0x03, // 00000011   __f_f_s_
		0xde, // 11011110   __ __m__
		0xbe, // 10111110   a___n___
		0xa7, // 10100111   y___ __m
		0xa6, // 10100110   __u__m__
		0xf0  // 11110000   s___    
	};

	size_t num_bytes = sizeof(expected) / sizeof(*expected);  // only for array on stack!!!
	_check_file_contents(_IN_PATH, expected, num_bytes);

	//────────────────────
	mu_end();
}


static bool _check_file_contents(const char* path, const uint8_t* bytes, size_t num_bytes) {
	/* Return true iff and only if the file at «path» contains exactly «num_bytes»
	 * bytes, and all bytes match the contents of the array «bytes».
	 */
	bool are_contents_correct = true;

	FILE* fp = fopen(path, "r");
	for(int i = 0; i < num_bytes; i++) {
		uint8_t ch = fgetc(fp);
		if(feof(fp) || ch != bytes[i]) {  // intentionally redundant, for clarity
			are_contents_correct = false;
			break;
		}
	}

	// If size matches
	are_contents_correct = are_contents_correct && ! feof(fp);
	if(are_contents_correct) {
		fgetc(fp);
		are_contents_correct = feof(fp);
	}
	return are_contents_correct;
}


static void _write_dummy_file(const char* path, const char contents[]) {
	/* Write the string «contents» to a file at «path».
	 */
	FILE* fp = fopen(path, "r");
	fprintf(fp, "%s", contents);
	fclose(fp);
}


int main(int argc, char* argv[]) {
	// Make a couple dummy files to test with.
	mu_run(_test_wrong_number_of_arguments);
	mu_run(_test_input_file_non_existant);
	mu_run(_test_input_file_not_file);
	mu_run(_test_input_file_unreadable);
	mu_run(_test_input_path_blank);
	mu_run(_test_output_dir_not_writable);
	mu_run(_test_output_path_blank);
	mu_run(_test_output_path_exists);
	mu_run(_test_empty_input_file);
	mu_run(_test_huffman_fluffs_many_mums);

	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
