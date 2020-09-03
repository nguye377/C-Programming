// © 2020  Alexander J Quinn 2020.  All Rights Reserved.
//         This content is protected and may not be shared, uploaded, or distributed.

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "simple_file_utilities.h"

bool does_path_exist(const char* path) {
	return access(path, F_OK) == 0;
}

bool is_path_a_regular_file(const char* path) {
	struct stat stat_info;
	return stat(path, &stat_info) == 0 && S_ISREG(stat_info.st_mode);
}

bool is_path_a_directory(const char* path) {
	struct stat stat_info;
	return stat(path, &stat_info) == 0 && S_ISDIR(stat_info.st_mode);
}

bool is_containing_directory_writable(const char* path) {
	char* path_copy = strdup(path);
	char* dir_path = dirname(path_copy); 
	bool is_dir = is_path_a_directory(dir_path);
	bool is_path_a_writable_dir = is_dir && access(path, W_OK) == 0;
	free(path_copy);
	return is_path_a_writable_dir;
}

void remove_file_if_exists(const char* path) {
	if(is_path_a_regular_file(path)) {
		unlink(path);
	}
}

long get_file_size_bytes(const char* path) {
	struct stat stat_info;
	bool did_stat_succeed = stat(path, &stat_info) == 0;
	if(did_stat_succeed) {
		return stat_info.st_size;
	}
	else {
		return ERROR_CODE_STAT_FAILED;
	}
}


////////////////////////////////////////////////////////////////////////////////
// ABOUT THE LIBRARY FUNCTIONS USED IN THIS FILE
//
// ∙ dirname(…) returns the containing directory path.  The argument (path) must
//   be writable, so we must make a copy of the path on the heap.
//
// ∙ strdup(…) makes a copy of any string on the heap.  (You implemented something
//   equivalent in a warmup earlier in the semester.)
//
// ∙ stat(…) provides a struct object with basic information about a path, such as
//   whether it refers to a regular file, a directory, or something special.  The
//   struct object is passed back by address.  The direct value returned by stat(…)
//   is false (0) if the file exists, and true (1) if it does not exist (or if
//   some other problem occurred).
//
// ∙ S_ISREG(…) takes the .st_mode field of the struct object returned by stat(…), and
//   returns true (or ≥1) if and only if the path refers to a regular FILE.  This is
//   a macro.
//
// ∙ S_ISDIR(…) takes the .st_mode field of the struct object returned by stat(…), and
//   returns true (or ≥1) if and only if the path refers to a DIRECTORY.  This is a
//   macro.
//
// ∙ access(…) checks whether a certain operation may be performed on a given path.
//   In this case, access(path, W_OK) checks if the path is writable, and hence,
//   whether you are allowed to create a few file in this directory.  It returns 0 if
//   the operation is allowed, and 1 if it is not allowed or if there was some other
//   error.
//
// ∙ #define _POSIX_C_SOURCE 200809L tells GCC to include some POSIX (operating
//   system standard) headers/libraries.  This allows us to use to strdup(…).
////////////////////////////////////////////////////////////////////////////////

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
