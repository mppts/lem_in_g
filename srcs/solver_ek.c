/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_ek.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:37:56 by limry             #+#    #+#             */
/*   Updated: 2020/02/26 18:43:11 by limry            ###   ########.fr       */
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

void			refresh_potentials(t_room *start)
{
	t_room		*tmp;

	start->potential = start->delta;
	start->level = 0;
	start->delta = 0;
	start->sign = 0;
	tmp = start->next;
	while (tmp != start)
	{
		tmp->potential = tmp->delta;
		tmp->delta = INT64_MAX;
		tmp->sign = 0;
		tmp = tmp->next;
	}
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
	}
}

void				print_ppath(t_map *g)
{
	t_room	*tmp;
	t_link	*ln;
	char	*nm;
	tmp = g->start;
	while (tmp != g->start->prev)
	{
		nm = tmp->name;
		ln = tmp->linked_to;
		while (ln)
		{
			if (ln->flow == 0)
			{
				printf("%s\t\t%s\n",nm, ln->to->name);
				nm = "\t";
			}
			ln = ln->next;
		}
		tmp = tmp->next;
	}
}

void			solver_edmonds_karp(t_map *g)
{
	t_solver	*slv;

	slv = init_solver(g);
	if (bfs_potential(g->start, g->fin, slv->deq))
	{
		g->start->potential = 0;
		g->start->delta = 0;
		while (bin_dijkstra(g, slv->heap))
		{
			fulfill_path(g);
			find_all_paths(slv->paths_arr, g);
			print_desc2(slv->paths_arr);
			//print_ppath(g);
			printf("\n");
			if (enough_solutions(slv, g))
				break ;
			bin_clean_heap_data(slv->heap);
			refresh_potentials(g->start);
			g->fin->level = 1;
		}
	}
	g->paths = slv->paths_arr_solution;
	remove_solver(slv);
}
