#include "lem_in.h"

void	clean_flow_and_potential_room(t_room *room)
{
	t_link	*link;

	link = room->linked_to;
	while (link)
	{
		link->flow = 0;
		link = link->next;
	}
	room->potential = 0;
}

void	clean_potentials_and_flows_graph(t_room *start)
{
	t_room	*room;

	clean_flow_and_potential_room(start);
	room = start->next;
	while(room != start)
	{
		clean_flow_and_potential_room(room);
		room = room->next;
	}
}

void			solver_edmonds_karp(t_map *g)
{
	t_solver	slv;
	int			path_num;

	path_num = 0;
	init_solver(&slv, g);
	clean_potentials_and_flows_graph(g->start);
	while (bfs_potential(g->start, g->fin, g, slv.deq))
	{
		while (bin_dijkstra(g, slv.heap))
		{
			slv.paths_arr->path_starts[path_num + 1] =
			slv.paths_arr->path_lens[path_num] + slv.paths_arr->path;
			path_num++;
		}
		if (enough_solutions(slv, g))
			break;
	}
}
