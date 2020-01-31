
#include "binary_heap.h"

int 				bin_inc_key(t_bin_heap *heap, uint64_t i, uint64_t key)
{
	if (heap->nodes[i].key > key)
		return (-1);
	(&heap->nodes[i])->key = key;
	while (i > 1 && heap->nodes[i].key > heap->nodes[i / 2].key)
	{
		bin_heap_swap(&heap->nodes[i], &heap->nodes[i / 2]);
		i /= 2;
	}
	return (i);
}

int 				bin_decr_key(t_bin_heap *heap, uint64_t i, uint64_t key)
{
	if (heap->nodes[i].key < key)
		return (-1);
	(&heap->nodes[i])->key = key;
	while (i > 1 && heap->nodes[i].key < heap->nodes[i / 2].key)
	{
		bin_heap_swap(&heap->nodes[i], &heap->nodes[i / 2]);
		i /= 2;
	}
	return (i);
}