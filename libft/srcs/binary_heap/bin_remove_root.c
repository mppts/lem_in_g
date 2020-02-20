
#include "binary_heap.h"

void			heap_heapify(t_bin_heap *heap, uint64_t i)
{
	uint64_t 	l;
	uint64_t 	r;
	uint64_t 	min;

	while (1)
	{
		l = 2 * i;
		r = 2 * i + 1;
		min = i;
		if (l <= heap->num_nodes && heap->nodes[l].key < heap->nodes[i].key)
			min = l;
		if (r <= heap->num_nodes && heap->nodes[r].key < heap->nodes[min].key)
			min = r;
		if (min == i)
			break;
		bin_heap_swap(&heap->nodes[i], &heap->nodes[min]);
		i = min;
	}
}

void			bin_remove_root(t_bin_heap *heap)
{
	if (heap->num_nodes == 1)
		return ;
	heap->num_nodes--;
	heap->nodes[1] = heap->nodes[heap->num_nodes];
	heap_heapify(heap, 1);
}

void		*bin_pop_root(void *data_new_min, t_bin_heap *heap)
{
	data_new_min = bin_get_root(heap)->data;
	bin_remove_root(heap);
	return (data_new_min);
}