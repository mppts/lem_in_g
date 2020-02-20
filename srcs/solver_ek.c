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

void		slv_copy_to_solution(t_solver *slv, t_map *g)
{
	int		max_path_num;

	max_path_num = g->start->num_linked_to > g->fin->num_linked_to ?
				   g->start->num_linked_to : g->fin->num_linked_to;
	slv->paths_arr_solution->num_paths = slv->paths_arr->num_paths;
	slv->paths_arr_solution->amt_steps_cost = slv->paths_arr->amt_steps_cost;
	slv->paths_arr_solution->current_path = slv->paths_arr->current_path;
	ft_memcpy(&(slv->paths_arr_solution->path), &(slv->paths_arr->path),
			sizeof(t_room*) * g->num_nodes);
	ft_memcpy(&(slv->paths_arr_solution->path_starts), &(slv->paths_arr->path_starts),
			sizeof(t_room**) * max_path_num);
	ft_memcpy(&(slv->paths_arr_solution->path_lens), &(slv->paths_arr->path_lens),
			sizeof(int) * max_path_num);
	slv->paths_arr_solution->num_paths = slv->paths_arr->num_paths;
}

int			enough_solutions(t_solver *slv, t_map *g)
{
	if (slv->paths_arr_solution->current_path == 0 ||
	(slv->paths_arr_solution->amt_steps_cost + g->ants) / (slv->paths_arr_solution->current_path)
	> (slv->paths_arr->amt_steps_cost + g->ants) / (slv->paths_arr->current_path))
	{
		slv_copy_to_solution(slv, g);
		slv_clean_paths(slv->paths_arr, g);
		return (1);
	}
	return (0);
}


t_room			*find_path_back(t_link *ln)
{
	while (ln)
	{
		if (ln->mirror->flow)
			return (ln->to);
		ln = ln->next;
	}
	return (NULL);
}


void			save_path(t_paths_arr *path, t_map *g, t_link *link)
{
	uint64_t	i;
	t_room		*rm;
	t_link		*ln;

	rm = link->to;
	while(rm != g->start)
	{
		path->path_lens[path->current_path] += 1;
		ln = rm->linked_to;
		rm = find_path_back(ln);
	}
	rm = link->to;
	i = 1;
	while (i <= path->path_lens[path->current_path])
	{
		path->path_starts[path->current_path][path->path_lens[path->current_path] - i] = rm;
		ln = rm->linked_to;
		rm = find_path_back(ln);
		i++;
	}
	path->path_starts[path->current_path][path->path_lens[path->current_path]] = g->fin;
	path->path_lens[path->current_path] += 1;
	path->amt_steps_cost += path->path_lens[path->current_path];
}

void			save_paths(t_paths_arr *path, t_map *g)
{
	t_link		*tmp;

	tmp = g->fin->linked_to;
	while (tmp)
	{
		if (tmp->mirror->flow)
		{
			path->path_lens[path->current_path] += 1;
			save_path(path, g, tmp);
			path->current_path++;
			*(path->path_starts[path->current_path]) =
			(*(path->path_starts[path->current_path - 1]) +
			path->path_lens[path->current_path - 1]);
		}
		tmp = tmp->next;
	}
}

void			solver_edmonds_karp(t_map *g)
{
	t_solver	*slv;

	slv = init_solver(g);
	clean_potentials_and_flows_graph(g->start);
	if (bfs_potential(g->start, g->fin, g, slv->deq))
	{
		g->start->potential = 0;
		while (bin_dijkstra(g, slv->heap, slv->paths_arr))
		{
			save_paths(slv->paths_arr, g);
			if (enough_solutions(slv, g))
				break;
			bin_clean_heap_data(slv->heap);
		}
	}
	remove_solver(slv);
}
