#include "binary_heap.h"

t_bin_node			*bin_get_root(t_bin_heap *heap)
{
	if (heap->num_nodes == 0)
		return (NULL);
	return (&(heap->nodes[1]));
}