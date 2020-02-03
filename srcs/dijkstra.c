
#include <lem_in.h>
#include "binary_heap.h"
/*
** g - map
** nexts_v - current shortest path. On input is : [start, NULL, NULL, ...]
** dists - array of distances from sink to current vertex. On input is [0, UINT64_MAX - UINT8_MAX]
*/

void			bin_dijkstra(t_map *g, t_room *nexts_v[g->num_nodes], int64_t dists[g->num_nodes])
{
	int64_t 	dist;
	t_room		*tmp;
	t_link		*link;
	t_bin_heap	*heap;

	dist = 0;
	tmp = NULL;
	heap = bin_heap_init(g->num_nodes);
	bin_heap_insert(heap, g->start, dist);
	dists[g->start->hash_id] = dist;
	while(heap->num_nodes)
	{
		bin_pop_root(tmp, heap);
		link = tmp->linked_to;
		dist = dists[tmp->hash_id] + 1;
		while (link)
		{
			while (link && link->to->path_id)
				link = link->next;
			if (link && link->to == g->fin)
				return ; //or add path
			if (link && dists[tmp->hash_id] > dist)
			{
				dists[link->to->hash_id] = dist;
				nexts_v[dist] = link->to;
				bin_heap_insert(heap, link->to, dist);
			}
		}
	}
}