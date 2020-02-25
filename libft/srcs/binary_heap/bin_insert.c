/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:29:45 by limry             #+#    #+#             */
/*   Updated: 2020/02/25 20:29:48 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_heap.h"

void			heapify_up(t_bin_heap *heap)
{
	int64_t		i;

	i = heap->num_nodes;
	while (i > 1 && heap->nodes[i].key < heap->nodes[i / 2].key)
	{
		bin_heap_swap(&(heap->nodes[i]), &(heap->nodes[i / 2]));
		i /= 2;
	}
}

int				bin_heap_insert(t_bin_heap *heap, void *data, int64_t key)
{
	if (heap->num_nodes > heap->capacity)
		return (0);
	(heap->nodes + heap->num_nodes)->data = data;
	(heap->nodes + heap->num_nodes)->key = key;
	heapify_up(heap);
	heap->num_nodes++;
	return (1);
}
