#include "binary_heap.h"

void				bin_heap_free(t_bin_heap *heap)
{
	if (!heap)
		return ;
	if (heap->nodes)
		free(heap->nodes);
	free(heap);
}