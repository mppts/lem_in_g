#ifndef LEM_IN_FIBONACCI_HEAP_H
#define LEM_IN_FIBONACCI_HEAP_H

#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct				s_fib_node
{
	uint64_t 				key;
	void					*data;
	struct s_fib_node		*parent;
	struct s_fib_node		*child;
	struct s_fib_node		*left;
	struct s_fib_node		*right;
	uint64_t 				degree;
	uint8_t 				mark;
}							t_fib_node;

typedef struct				s_fib_heap
{
	uint64_t 				size;
	t_fib_node				*root;
}							t_fib_heap;
/*
** init heap and get min functions
*/
t_fib_heap 					*fib_init_heap(void);
t_fib_node 					*fib_create_node();
void						fib_insert(t_fib_heap *heap, t_fib_node *node);
t_fib_node 					*fib_get_min(t_fib_heap *heap);
/*
** merge - main function for union, unionLists - additional function
*/
t_fib_heap 					*fib_merge_heaps(t_fib_heap *a,t_fib_heap *b);
void						fib_unionList(t_fib_node *a, t_fib_node *b);
/*
** Remove min element
*/
void						fib_remove_min(t_fib_heap *heap);
/*
** tree thinning
*/
void						fib_thinning(t_fib_heap *heap);
#endif
