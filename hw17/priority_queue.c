#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "priority_queue.h"


Node* pq_enqueue(Node** a_head, void* a_value, int (*cmp_fn)(const void*, const void*)) {

	// if(a_value == NULL) {
	// 	return NULL;
	// }
	Node* current_node = malloc(sizeof(Node)); // Luon dùng pointer cho Struct
	if(current_node == NULL) {
		return NULL;
	}
	current_node -> a_value = (void*) a_value;
	current_node -> next = NULL;

	// Initial Steps
	if((*a_head) == NULL) {
		current_node ->next = NULL;
		(*a_head) = current_node;
		//current_node = (*a_head)->a_value;
		return *a_head; 
	}
	
	//current_node -> a_value = (void*) a_value; //different a_value
	// Swap *a_head bằng node nhỏ hơn 
	// Nếu *a_head có next

	//*a_head lớn hơn thì swap
	if(cmp_fn((*a_head)->a_value, current_node->a_value) >= 0){
		current_node -> next = (*a_head); // head>=current, change
		(*a_head) = current_node; //a_head has frequency smaller
		return current_node;
	}
	//Current lớn 1: lớn hơn *a_head, nhỏ hơn next
	//Current lớn 2: lớn hơn *a_head, lớn hơn next

	Node* head = *a_head;
	Node* curr = (*a_head)->next;
	
	// Giữ nguyên *a_head
	// compare (*a_head)->next->a_value->frequency;
	// and current_node->a_value->frequency
	// 
	while(((head->next)!= NULL)&& (cmp_fn(current_node->a_value, curr->a_value)>=0)) {
		// curr>=current_node->a_value thì dừng lại
		if(head->next!= NULL) // cuối chuỗi thì dùng lại
		{
			head = head -> next;
			curr = curr -> next;
		}
		else 
		{
			break;
		}
		
	}
	//if (curr->next != NULL)
	//{
		//swap 2 cái khi a_head có đuôi
		// f of *a_head< current_node < f of *a_head->next
		head->next = current_node;
		current_node->next = curr;
		return current_node;
	//}
	return current_node;
}


Node* pq_dequeue(Node** a_head) {
	// if((*a_head) == NULL){
	// 	return NULL;
	// }
	Node* current = *a_head;
	*a_head = (*a_head) -> next;
	current -> next = NULL;
	return current;
	// if((*a_head) == NULL){
	// 	return NULL;
	// }
	// else if((*a_head)->next ==NULL) {
	// 	//Node* current = *a_head;
	// 	*a_head = NULL;
	// 	return current;
	// }
	// else
	// {
	// 	(*a_head) = (*a_head) -> next;
	// 	current -> next = NULL;
	// 	return current;
	// }
	
}


Node* stack_push(Node** a_top, void* a_value) {
	// if(a_value == NULL) {
	// 	return NULL;
	// }
	Node* temp = malloc(sizeof(Node));
	if (temp == NULL){
		return NULL;
	}
	temp -> a_value = (void*) a_value; //"(void*) a_value" is a new on stack
	temp -> next = *a_top;
	*a_top = temp;
	return *a_top;
}


Node* stack_pop(Node** a_top) {
	// Node* temp = *a_top;
	// (*a_top) = (*a_top) -> next;
	// temp -> next = NULL;
	// return temp;
	Node* head  = pq_dequeue(a_top);
	return head;
}

void destroy_list(Node** a_head, void (*destroy_value_fn)(void*)) {
	if(*a_head ==NULL){
		return;
	}
	while (*a_head != NULL)
	{
		Node* curren_node = (*a_head)->next;
		destroy_value_fn((*a_head)->a_value);
		free(*a_head);
		(*a_head) = curren_node;
	}
	return;
}

#define HUFFMAN_C_V0
