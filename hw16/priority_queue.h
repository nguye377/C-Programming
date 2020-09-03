#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__


typedef struct _Node {
   void* a_value;
   struct _Node *next;
} Node;


Node *pq_enqueue(Node** a_head, void *a_value, int (*cmp_fn)(const void*, const void*));

                       
Node *pq_dequeue(Node** a_head);


Node *stack_push(Node** a_top, void* a_value);

                       
Node *stack_pop(Node** a_top);


void destroy_list(Node** a_head, void (*destroy_value_fn)(void*));

 
#endif

#define HUFFMAN_H_V0
