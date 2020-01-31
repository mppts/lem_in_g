#include "binary_heap.h"

void				bin_heap_swap(t_bin_node *a, t_bin_node *b)
{
	t_bin_node		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}