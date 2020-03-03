/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_ek.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:37:56 by limry             #+#    #+#             */
/*   Updated: 2020/03/03 20:05:02 by limry            ###   ########.fr       */
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

void			refresh_potentials(t_room *start, t_map *g)
{
	t_room		*tmp;

	start->pot_out = start->delta_out;
	start->pot_in = start->delta_in;
	start->level = 0;
	start->delta_out = 0;
	start->delta_in = 0;
	start->sign = 0;
	start->pred_in = NULL;
	start->pred_out = NULL;
	tmp = start->next;
	while (tmp != start)
	{
		tmp->pot_out = tmp->delta_out;
		tmp->pot_in = tmp->delta_in;
		tmp->pred_in = NULL;
		tmp->pred_out = NULL;
		tmp->delta_out = INT64_MAX;
		tmp->delta_in = INT64_MAX;
		tmp->sign = 0;
		tmp = tmp->next;
	}
	g->fin->level = 1;
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
		g->start->delta_out = 0;
		g->start->delta_in = 0;
		while (bin_dijkstra(g, slv->heap))
		{

			fulfill_path(g);
			find_all_paths(slv->paths_arr, g);
			//print_desc2(slv->paths_arr);
			//printf("\n");
			if (enough_solutions(slv, g))
				break ;
			bin_clean_heap_data(slv->heap);
			refresh_potentials(g->start, g);
			g->fin->level = 0;
		}
	}
	g->paths = slv->paths_arr_solution;
	remove_solver(slv);
}
