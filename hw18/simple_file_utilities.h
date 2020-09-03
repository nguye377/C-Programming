// © 2020  Alexander J Quinn 2020.  All Rights Reserved.
//         This content is protected and may not be shared, uploaded, or distributed.

#include <stdbool.h>

enum { ERROR_CODE_STAT_FAILED = -1 };

/*────────────────────────────────────────────────────────────────────────────────
 * get_file_size_bytes(«path») returns the size of the file at «path», in bytes.
 */
long get_file_size_bytes(const char* path);

/*────────────────────────────────────────────────────────────────────────────────
 * does_path_exist(«path») returns true if and only if «path» exists.
 */
bool does_path_exist(const char* path);

/*────────────────────────────────────────────────────────────────────────────────
 * is_path_a_regular_file(«path») returns true if and only if «path» (1) exists
 * and (2) is a regular file
 */
bool is_path_a_regular_file(const char* path);

/*────────────────────────────────────────────────────────────────────────────────
 * is_path_a_directory(«path») returns true if and only if «path» (1) exists and
 * (2) is a directory.
 */
bool is_path_a_directory(const char* path);

/*────────────────────────────────────────────────────────────────────────────────
 * is_containing_directory_writable(«path») returns true if and only if the
 * directory containing «path» (1) exists, (2) is a directory, and (3) is writable.
 */
bool is_containing_directory_writable(const char* path);

/*────────────────────────────────────────────────────────────────────────────────
 * remove_file_if_exists(«path») deletes the file «path» if it (1) exists and
 * (2) is a regular file.
 */
void remove_file_if_exists(const char* path);
