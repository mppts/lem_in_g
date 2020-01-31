
#include "fibonacci_heap.h"

t_fib_node 		*fib_create_node(void *data, uint64_t key)
{
	t_fib_node	*new;

	new = (t_fib_node*)malloc(sizeof(t_fib_node));
	if(!new)
		return (NULL);
	new->child = NULL;
	new->left = new;
	new->right = new;
	new->parent = NULL;
	new->data = data;
	new->degree = 0;
	new->key = key;
	new->mark = 0;
}