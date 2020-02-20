
#include <lem_in.h>
#include "binary_heap.h"
/*
** g - map
** nexts_v - current shortest path. On input is : [start, NULL, NULL, ...]
** dists - array of distances from sink to current vertex. On input is [0, UINT64_MAX - UINT8_MAX]
*/

int				bin_dijkstra(t_map *g, t_bin_heap *heap)
{
	t_room		*tmp;
	t_link		*link;

	bin_heap_insert(heap, g->start, g->start->potential);
	while(heap->num_nodes > 1)
	{
		tmp = (t_room*)bin_pop_root(tmp, heap);
		link = tmp->linked_to;
		while (link)
		{
			while (link && (link->to == tmp || link->flow))
				link = link->next;
			if (link && (link->to->potential >= tmp->potential + 1 || link->mirror->flow))
			{
				link->to->pred = tmp;
				link->to->potential = tmp->potential + 1;
				bin_heap_insert(heap, link->to, link->to->potential);
			}
			if (link && link->to == g->fin)
				return (1);
			if (link)
				link = link->next;
		}
	}
	return (0);
}