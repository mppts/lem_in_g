#include "binary_heap.h"
#include "libft.h"

void			bin_clean_heap_data(t_bin_heap* heap)
{
	ft_bzero(heap->nodes, sizeof(t_bin_node) * (heap->capacity + 1));
	heap->num_nodes = 1;
}

t_bin_heap		*bin_heap_init(uint64_t size)
{
	t_bin_heap	*heap;

	heap = (t_bin_heap*)malloc(sizeof(t_bin_heap));
	if (!heap)
		return (NULL);
	heap->capacity = size;
	heap->num_nodes = 1;
	heap->nodes = (t_bin_node*)malloc(sizeof(t_bin_node) * (size + 1));
	if (!heap->nodes)
	{
		free(heap);
		return (NULL);
	}
	ft_bzero(heap->nodes, sizeof(t_bin_node) * (size + 1));
	return (heap);
}

t_bin_heap		*bin_heap_init_stack(t_bin_heap	*heap, t_bin_node *nodes)
{
	if (!heap)
		return (NULL);
	heap->capacity = sizeof(nodes) / sizeof(t_bin_node*);
	heap->num_nodes = 0;
	heap->nodes = nodes;
	return (heap);
}