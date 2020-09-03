#ifndef __JSON_H__
#define __JSON_H__
#include <stdbool.h>
#define BONUS_JSON_CONSTANTS

typedef struct {
	enum  { ELEMENT_INT, ELEMENT_STRING, ELEMENT_LIST,ELEMENT_NULL, ELEMENT_BOOL } type;
	union {
		int    as_int;
		char*  as_string;
		struct _Node* as_list;
		bool as_bool;
		void* as_null;
	} value; // ANONYMOUS union (C11).
} Element;


typedef struct _Node {
	struct _Node* next;
	Element element;
} Node;


bool parse_int(int* a_value, char** a_pos);
bool parse_string(char** a_s, char** a_pos);
bool parse_element(Element* a_element, char** a_pos);
bool parse_list(Node** a_head, char** a_pos);
void print_element(Element element);
void free_element(Element element);

#endif

#define JSON_H_VERSION_1
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
