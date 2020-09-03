// © 2020  Alexander J Quinn 2020.  All Rights Reserved.
//         This content is protected and may not be shared, uploaded, or distributed.

#ifndef __HUFFMAN_COMPRESS_H__
#define __HUFFMAN_COMPRESS_H__

#include <stdint.h>

typedef struct {
	uint32_t compressed_file_size_bytes;
	uint32_t coding_table_size_bytes;
	uint32_t uncompressed_file_size_bytes;
} Metadata;

extern const char* ERROR_MSG_USAGE;
extern const char* ERROR_MSG_INPUT_PATH_BLANK;
extern const char* ERROR_MSG_INPUT_PATH_DOES_NOT_EXIST;
extern const char* ERROR_MSG_INPUT_PATH_NOT_A_FILE;
extern const char* ERROR_MSG_INPUT_PATH_NOT_READABLE;
extern const char* ERROR_MSG_OUTPUT_PATH_BLANK;
extern const char* ERROR_MSG_OUTPUT_DIR_NOT_WRITABLE;
extern const char* ERROR_MSG_OUTPUT_PATH_EXISTS;

const char* check_command_line_arguments(int argc, const char* argv[]);
Metadata compress_file(const char* in_path, const char* out_path);

#endif /* end of include guard: __HUFFMAN_COMPRESS_H__ */
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
