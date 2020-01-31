
#include "fibonacci_heap.h"

void	fib_add_node_to_roots(t_fib_node *root, t_fib_node *node)
{
	if (!root)
		return ;
	node->left = root->left;
	node->right = root;
	root->left->right = node;
	root->left = node;
}

void	fib_insert_node(t_fib_heap *heap, t_fib_node *node)
{
	fib_add_node_to_roots(heap->root, node);
	if (heap->size == 0 || node->key < heap->root->key)
		heap->root = node;
	heap->size++;
}
