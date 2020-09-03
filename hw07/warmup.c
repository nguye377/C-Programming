#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//#include "clog.h"     // optional


// TODO:  Create definition of «struct Rectangle»
struct Rectangle {
	int height;
	int width;
};

struct Rectangle create_rectangle_stack(int height, int width) {
	// TODO
	struct Rectangle Rec = {.height=height, .width=width};
	return Rec;
}

struct Rectangle* create_rectangle_heap(int height, int width) {
	// TODO
	struct Rectangle*  node = malloc(sizeof(*node));
	*node = (struct Rectangle)  {.height=height, .width=width};
	return node;
}

void print_rectangle(struct Rectangle rect) {
	// TODO
	for(int i = 0; i < rect.height; i++){
		for (int j = 0; j < rect.width; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//print_rectangle(create_rectangle_stack(2, 6));
}

void destroy_rectangle(struct Rectangle* a_rect) {
	// TODO
	free(a_rect);
}

// TODO:  Create definition of «struct LimerickNode»
struct LimerickNode
{
	const char* str;
	struct LimerickNode* next;
};

struct LimerickNode* create_limerick(const char* lines[5]) {
	// TODO
	struct LimerickNode* head = malloc(sizeof(*head));
	struct LimerickNode* iterator = head;
	*head = (struct LimerickNode) {.str = lines[0], .next = NULL};
	//put string inside the linked list
	for(int i = 1; i < 5; i++){
		(iterator->next) = malloc(sizeof(*(iterator->next)));
		iterator = iterator -> next;
		*iterator = (struct LimerickNode) {.str = lines[i], .next=NULL};
		iterator->next = NULL;
	}
	return head;
}

void destroy_limerick(struct LimerickNode* head) {
	// TODO
	while(head != NULL)
	{
		struct LimerickNode* new_head = head -> next;
		free(head);
		head = new_head;
	}

}

void print_limerick(const struct LimerickNode* head) {
	// TODO
	for(const struct LimerickNode* temp = head; temp != NULL; temp = temp ->next){
		printf("%s\n", temp -> str);
	}
}


int main(int argc, char* argv[]) {
	
	struct Rectangle   rect_1 = create_rectangle_stack(3, 5);
	print_rectangle(rect_1);
	printf("\n");

	struct Rectangle* a_rect_2 = create_rectangle_heap(5, 7);
	print_rectangle(*a_rect_2);
	destroy_rectangle(a_rect_2);
	printf("\n");

	struct LimerickNode* head = create_limerick((const char*[5]) {
		"There was an Old Man of the Coast,",
		"Who placidly sat on a post;",
		"But when it was cold,",
		"He relinquished his hold,",
		"And called for some hot buttered toast."});
	print_limerick(head);
	destroy_limerick(head);
	printf("--\nAuthor: Edward Lear\n");
	
	return EXIT_SUCCESS;
}

#define WARMUP_C_VERSION 1
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
