
#include "fibonacci_heap.h"

t_fib_heap 		*fib_init_heap(void)
{
	t_fib_heap	*new;

	new = (t_fib_heap*)malloc(sizeof(t_fib_heap));
	if (!new)
		return (NULL);
	new->root = NULL;
	new->size = 0;
}
