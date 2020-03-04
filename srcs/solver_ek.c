/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_ek.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:37:56 by limry             #+#    #+#             */
/*   Updated: 2020/03/04 18:28:27 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			slv_copy_to_solution(t_solver *slv, t_map *g)
{
	t_room		**tmp_path;
	t_room		***tmp_starts;
	int			*tmp_lens;

	slv->paths_arr_solution->num_paths = slv->paths_arr->num_paths;
	slv->paths_arr_solution->amt_steps_cost = slv->paths_arr->amt_steps_cost;
	slv->paths_arr_solution->path_id = slv->paths_arr->path_id;
	slv->paths_arr_solution->num_paths = slv->paths_arr->num_paths;
	tmp_path = slv->paths_arr->path;
	tmp_starts = slv->paths_arr->path_starts;
	tmp_lens = slv->paths_arr->path_lens;
	slv->paths_arr->path = slv->paths_arr_solution->path;
	slv->paths_arr->path_starts = slv->paths_arr_solution->path_starts;
	slv->paths_arr->path_lens = slv->paths_arr_solution->path_lens;
	slv->paths_arr_solution->path = tmp_path;
	slv->paths_arr_solution->path_starts = tmp_starts;
	slv->paths_arr_solution->path_lens = tmp_lens;
}

int				enough_solutions(t_solver *slv, t_map *g)
{
	if (slv->paths_arr_solution->path_id == 0 ||
		(slv->paths_arr_solution->amt_steps_cost + g->ants) /
		(slv->paths_arr_solution->path_id)
		> (slv->paths_arr->amt_steps_cost + g->ants) /
		  (slv->paths_arr->path_id))
	{
		slv_copy_to_solution(slv, g);
		slv_clean_paths(slv->paths_arr, g);
		return (0);
	}
	return (1);
}

void			refresh_potentials(t_room *start, t_map *g, int f)
{
	t_room		*tmp;

	start->pot_out += f  ? start->delta_out : 0;
	start->pot_in += f  ? start->delta_in : 0;
	start->level = 0;
	start->delta_out = 0;
	start->delta_in = 0;
	start->sign = 1;
	tmp = start->next;
	while (tmp != start)
	{
		tmp->pot_out += f ? tmp->delta_out : 0;
		tmp->pot_in += f  ? tmp->delta_in : 0;
		tmp->delta_out = INT64_MAX;
		tmp->delta_in = INT64_MAX;
		tmp->sign = 0;
		tmp->sim = 0;
		tmp = tmp->next;
	}
	g->fin->level = f ? 1 : 0;
}


void				print_desc2(t_patha *pArr)
{
	int 			i;
	int 			j;

	i = 0;
	while (i < pArr->path_id)
	{
		j = 0;
		printf("%d: ", pArr->path_lens[i]);
		while (j < pArr->path_lens[i])
		{
			printf("[%s] ", pArr->path_starts[i][j]->name);
			j++;
		}
		printf("\n");
		i++;
	}/*
	while(i < pArr->amt_steps_cost)
	{
		printf("[%s] ", pArr->path[i]->name);
		i++;
	}*/
}

void			solver_edmonds_karp(t_map *g)
{
	t_solver	*slv;

	slv = init_solver(g);
	if (bfs_potential(g->start, g->fin, slv->deq))
	{
		refresh_potentials(g->start, g, 0);
		while (bin_dijkstra(g, slv->heap))
		{
			fulfill_path(g);
			find_all_paths(slv->paths_arr, g);
			print_desc2(slv->paths_arr);
			printf("\n");
			if (enough_solutions(slv, g))
				break ;
			refresh_potentials(g->start, g, 1);
			bin_clean_heap_data(slv->heap);
		}
	}
	g->paths = slv->paths_arr_solution;
	remove_solver(slv);
}
