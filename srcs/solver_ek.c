#include "lem_in.h"


void		slv_copy_to_solution(t_solver *slv, t_map *g)
{
	int		max_path_num;

	max_path_num = g->start->num_linked_to > g->fin->num_linked_to ?
				   g->start->num_linked_to : g->fin->num_linked_to;
	slv->paths_arr_solution->num_paths = slv->paths_arr->num_paths;
	slv->paths_arr_solution->amt_steps_cost = slv->paths_arr->amt_steps_cost;
	slv->paths_arr_solution->current_path = slv->paths_arr->current_path;
	ft_memcpy(slv->paths_arr_solution->path, slv->paths_arr->path,
			sizeof(t_room*) * g->num_nodes);
	ft_memcpy(slv->paths_arr_solution->path_starts, slv->paths_arr->path_starts,
			sizeof(t_room**) * max_path_num);
	ft_memcpy(slv->paths_arr_solution->path_lens, slv->paths_arr->path_lens,
			sizeof(int) * max_path_num);
	slv->paths_arr_solution->num_paths = slv->paths_arr->num_paths;
}

int			enough_solutions(t_solver *slv, t_map *g)
{
	int 	first;

	first = slv->paths_arr_solution->current_path;
	if (slv->paths_arr_solution->current_path == 0 ||
	(slv->paths_arr_solution->amt_steps_cost + g->ants) / (slv->paths_arr_solution->current_path)
	> (slv->paths_arr->amt_steps_cost + g->ants) / (slv->paths_arr->current_path))
	{
		slv_copy_to_solution(slv, g);
		slv_clean_paths(slv->paths_arr, g);
		return (0);
	}
	return (1);
}

void			fill_link_from_to(t_room *from, t_room *to)
{
	t_link		*ln;

	ln = from->linked_to;
	while(ln)
	{
		if (ln->to == to)
		{
			if (ln->mirror->flow == 0)
			{
				ln->mirror->flow = 1;
			}
			else
			{
				ln->flow = 0;
				ln->mirror->flow = -1;
			}
			break ;
		}
		ln = ln->next;
	}
}

void			fulfill_path(t_paths_arr *path, t_map *g)
{
	t_room		*rm;

	rm = g->fin;
	while (rm != g->start)
	{
		rm->level = 1;
		fill_link_from_to(rm->pred, rm);
		rm = rm->pred;
	}
}

void			refresh_potentials(t_room *start)
{
	t_room		*tmp;

	start->potential = 0;
	start->level = 0;
	start->sign = 0;
	tmp = start->next;
	while (tmp != start)
	{
		tmp->potential = INT64_MAX;
		tmp->sign = 0;
		tmp = tmp->next;
	}
}

void			push_path(t_paths_arr *path, t_map *g, t_deq *deq, t_link *lf)
{
	t_link		*link;

	path->path_starts[path->current_path][0] = g->start;
	path->path_starts[path->current_path][1] = lf->to;
	path->path_lens[path->current_path] = 2;
	link = lf->to->linked_to;
	while(link)
	{
		if(link->flow == 0)
		{
			path->path_starts[path->current_path][path->path_lens[path->current_path]++] = link->to;
			link = link->to->linked_to;
		}
		else
			link = link->next;
	}
	path->path_starts[path->current_path][path->path_lens[path->current_path]] = NULL;
}

void			find_all_paths(t_paths_arr *path, t_map *g, t_deq *deq)
{
	t_link		*link;

	link = g->start->linked_to;
	while (link)
	{
		if (link->flow  == 0)
		{
			push_path(path, g, deq, link);
			path->amt_steps_cost += path->path_lens[path->current_path];
			path->current_path++;
			path->path_starts[path->current_path] =
			path->path_starts[path->current_path - 1] +
			path->path_lens[path->current_path - 1];
		}
		link = link->next;
	}
}

void			print_desc(t_paths_arr *pArr)
{
	int 		i;
	int 		j;

	i = 0;
	while (i < pArr->current_path)
	{
		j = 0;
		printf("%d: ",pArr->path_lens[i]);
		while (j < pArr->path_lens[i])
		{
			printf("[%s] ", pArr->path_starts[i][j]->name);
			j++;
		}
		printf("\n");
		i++;
	}
}

void			solver_edmonds_karp(t_map *g)
{
	t_solver	*slv;

	slv = init_solver(g);
	if (bfs_potential(g->start, g->fin, g, slv->deq))
	{
		g->start->potential = 0;
		while (bin_dijkstra(g, slv->heap))
		{
			printf("\n");
			fulfill_path(slv->paths_arr, g);
			find_all_paths(slv->paths_arr, g, slv->deq);
			print_desc(slv->paths_arr);
			if (enough_solutions(slv, g))
				break;
			bin_clean_heap_data(slv->heap);
			refresh_potentials(g->start);
			g->fin->level = 1;
		}
	}
	remove_solver(slv);
}


