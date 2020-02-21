
#include <lem_in.h>
#include "binary_heap.h"

int				bin_dijkstra(t_map *g, t_bin_heap *heap)
{
	t_room		*tmp;
	t_link		*link;

	bin_heap_insert(heap, g->start, g->start->potential);
	while(heap->num_nodes > 1)
	{
		tmp = (t_room*)bin_pop_root(tmp, heap);
		tmp->sign = 1;
		link = tmp->linked_to;
		while (link)
		{
			while (link && (link->to == tmp || link->flow == 1))
				link = link->next;
			if (link && (!tmp->level &&  link->to->potential > tmp->potential + link->flow || tmp->level && link->to->potential > tmp->potential + link->flow))
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