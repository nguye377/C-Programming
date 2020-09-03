#ifndef __CAKE_H__
#define __CAKE_H__

#define CORNER_NW "┌"
#define CORNER_SW "└"
#define CORNER_NE "┐"
#define CORNER_SE "┘"
#define BOX_HORIZONTAL_LINE "─"

#include <stdlib.h>
#include <stdbool.h>

struct Node {
	const char* name;
	struct Node* next;
};

struct Node* create_list(const char* first_name, ...);
void choose_winner(struct Node** a_node, int n);
struct Node* detach_next_node(struct Node** a_node);
struct Node* get_nth_node(struct Node* start_node, int n);
void destroy_list(struct Node** a_head);
void print_list(const struct Node* start_node);

size_t count_nodes(const struct Node* node);
bool has_name(const struct Node* node, const char* name);
bool is_names(const struct Node* node, size_t num_names, const char** names);

#define CAKE_H_VERSION 3

#endif
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
