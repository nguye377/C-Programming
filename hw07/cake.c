#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "clog.h"							// optional
#include "cake.h"
#include "miniunit.h"

struct Node* create_list(const char* first_name, ...) {
	if (first_name == NULL) {
		return NULL;
	}
	struct Node* head = NULL;
	struct Node* tail = NULL;

	va_list argp;
	char *p;
	
	va_start(argp, first_name);
	head = malloc(sizeof(struct Node));
	head->name = first_name;
	tail = head;
	tail->next = NULL;

	while ((p = va_arg(argp, char*)) != NULL) {
		tail->next = malloc(sizeof(struct Node));
		tail = tail->next;
		tail->name = p;
		tail->next = NULL;
		
	}
	tail->next = head;


	assert((first_name == NULL && head == NULL) ||
		   (first_name != NULL && head -> name == first_name));
	return head;
}

//This function to print nodes
void print_list(const struct Node* start_node) {
	
	const struct Node* temp = (struct Node * ) start_node;
	if( temp == NULL)
		return;
	printf("┌");
	int total_width = 1;

	do {
		printf("[\"%s\"]", temp -> name);
		total_width += strlen(temp -> name) + 5;
		printf("─"); // Character: "box drawings light horizontal"
			temp = temp -> next;
	} while (temp != start_node);
	
	//__________________________________________________
	// LOWER LEVEL
	// Print upper left corner
	printf("┐\n");
	// Print horizontal lines
	printf("└");
	int num_horizontal_lines = total_width - 1 ;
	for(int name_idx = 0; name_idx < num_horizontal_lines; name_idx++) {
		printf("─"); // Character: "box drawings light horizontal"
	}
	// Print lower right corner
	printf("┘\n");
	
}


void destroy_list(struct Node** a_head) {
	//struct Node* current = *a_head;
	//struct Node* next_node;
	struct Node *h = *a_head;
	while(*a_head != NULL) {
		struct Node* temp = (*a_head) -> next;
		free(*a_head);
		*a_head = temp;
		if(*a_head == h) {

			*a_head = NULL;
		}
	}
	*a_head = NULL;
	

	// while(current != NULL){
	// 	next_node = current -> next;
	// 	free(current); 
	// 	current = next_node;
	// 	if(*a_head == current){
	// 		*a_head = NULL;
	// 	}
	// }
	//*a_head = NULL;

	assert(*a_head == NULL);  // List must be empty when destroy_list(…) returns
}


struct Node* get_nth_node(struct Node* start_node, int n) {
	struct Node* node = NULL;

	struct Node* current = start_node;
	int count = 1;
	if(current == NULL){
		return NULL;
	}
	
	if(n == 0){
		for(int i = 0; i < count_nodes(start_node)-1; i++){
			current = current ->next;
			//printf("%d out of %ld\n", i, count_nodes(start_node));
		}
		//printf("last one? %s\n",current->name);
		return current;

	} 
	while (count < n){
		current = current -> next;
		count++;
	}
	//printf("inside get n node. returning: %s\n", current->name);
	return current;
/*
	for (int i = 0; i < n-1; i++) {
		current = current->next;
	}
	printf("get nth: %s\n", current -> name);
	
	return current;
*/
	/*
	while (current != NULL)
	{
		if(index == n){
			return (current);
		}
		index++;
		current = current -> next;
	}
	*/
	
	assert((node == NULL) == (start_node == NULL));
	return node;
}


struct Node* detach_next_node(struct Node** a_node) {
	struct Node* loner = NULL;

	loner = *a_node;
	//printf("the node I should delete is: %s\n", loner->name);
	if(loner == NULL){
		return NULL;
	}
	else if(loner == loner -> next){
		*a_node = NULL;
		return *a_node;
	}
	else{
		loner = (*a_node) -> next;
		(*a_node) -> next = loner ->next;
		loner -> next = loner;
		// printf("the node I am deleting is: %s\n", loner->name);
		// printf("--------\n");
		return loner;
	}
	// struct Node * prev_loner;
	assert((loner != NULL && loner -> next == loner) || *a_node == NULL);
	return loner;
}


void choose_winner(struct Node** a_node, int n) {
	if (*a_node == NULL) {
		return;
	}
	
	struct Node* delete_node;
	struct Node* temp_node = *a_node;
	// int k = n-1;
	while(temp_node->next != temp_node){
		temp_node= get_nth_node(temp_node, n - 1);
		delete_node = detach_next_node(&temp_node);
		temp_node = temp_node -> next;
		if (delete_node != NULL) {
			free(delete_node);
		}
		//print_list(temp_node);
	}
	*a_node = temp_node;
	//print_list(temp_node);
}


size_t count_nodes(const struct Node* node) {
	if(node == NULL){
		return 0;
	}
	struct Node *temp = (struct Node*)  node;
	int num_node = 0;
	do {
		temp = temp -> next;
		num_node++;
	} while (temp != node);
	//printf("%d\n", num_node);
	return num_node;
}


bool has_name(const struct Node* node, const char* name) {
	if(node == NULL){
		return false;
	}
	struct Node* current = (struct Node *) node;
	do {
		if(strcmp(current -> name, name) == 0){
			return true;
		} 
		current = current->next;
	} while (current != node);
	return false;
	//return false; // stub -- TODO: delete this line
}


bool is_names(const struct Node* node, size_t num_names, const char** names) {
	if(node == NULL){
		return false;
	}
	if (num_names != count_nodes(node)){
		return false;
	}

	struct Node * current = (struct Node *) node;
	for(int i = 0; i < num_names; i++) {
		if(strcmp(current -> name, names[i]) != 0){
			return false;
		}
		current = current -> next;
	}
	return true;
	// return false; // stub -- TODO: delete this line
}


#define CAKE_C_VERSION 4
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
