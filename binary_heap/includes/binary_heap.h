#ifndef LEM_IN_BINARY_HEAP_H
#define LEM_IN_BINARY_HEAP_H

#include <stdlib.h>
#include <inttypes.h>

typedef struct		s_bin_node
{
	uint64_t 		key;
	void			*data;
}					t_bin_node;

typedef struct		s_bin_heap
{
	uint64_t 		capacity;
	uint64_t 		num_nodes;
	t_bin_node 		*nodes;
}					t_bin_heap;

t_bin_heap			*bin_heap_init(uint64_t size);
void				bin_heap_free(t_bin_heap *heap);
void				bin_heap_swap(t_bin_node *a, t_bin_node *b);
t_bin_node			*bin_get_root(t_bin_heap *heap);
int					bin_heap_insert(t_bin_heap *heap, void *data, uint64_t key);
void				bin_remove_root(t_bin_heap *heap);
int 				bin_inc_key(t_bin_heap *heap, uint64_t i, uint64_t key);
int 				bin_decr_key(t_bin_heap *heap, uint64_t i, uint64_t key);
void				*bin_pop_root(void *new_min, t_bin_heap *heap);

#endif