
#include "fibonacci_heap.h"

void			fib_heap_link_lists(t_fib_node *a_head, t_fib_node *b_head)
{
	if (!a_head || !b_head)
		return ;
	a_head->left->right = b_head;
	a_head->right = b_head->left;
	b_head->left->right = a_head;
	b_head->left = a_head->left;
}

t_fib_heap 		*fib_heap_union(t_fib_heap *a, t_fib_heap *b)
{
	t_fib_heap *new;

	new = fib_init_heap();
	new->root = a->root;
	fib_heap_link_lists(a->root, b->root);
	if (!a->root|| (!b->root && b->root->key < a->root->key))
		new->root = b->root;
	new->size = a->size + b->size;
	fib_free_heap(a);
	fib_free_heap(b);
	return (new);
}