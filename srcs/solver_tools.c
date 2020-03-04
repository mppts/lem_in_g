/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:56:05 by limry             #+#    #+#             */
/*   Updated: 2020/03/04 15:00:41 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_patha		*slv_error_cleaning(int step, t_patha *solution)
{
	if (step > 4)
		free(solution->num_ants);
	if (step > 3)
		free(solution->path_lens);
	if (step > 2)
		free(solution->path_starts);
	if (step > 1)
		free(solution->path);
	if (step > 0)
		free(solution);
	return (NULL);
}

void			slv_clean_paths(t_patha *path, t_map *g)
{
	uint64_t	max_path_num;

	max_path_num = g->start->num_linked_to > g->fin->num_linked_to ?
	g->start->num_linked_to : g->fin->num_linked_to;
	ft_bzero(path->path, (sizeof(t_room*) * g->num_nodes));
	ft_bzero(path->path_starts, sizeof(t_room**) * max_path_num);
	ft_bzero(path->path_lens, sizeof(int) * max_path_num);
	ft_bzero(path->num_ants, sizeof(int) * max_path_num);
	*path->path_starts = path->path;
	path->amt_steps_cost = 0;
	path->num_paths = 0;
	path->path_id = 0;
}

t_patha		*slv_init_solution(t_map *g)
{
	t_patha	*path;
	uint64_t	max_num_p;
	int			err;

	err = 0;
	if (!(path = malloc(sizeof(t_patha))))
		return (NULL);
	if (++err && !(path->path = malloc(sizeof(t_room*) * g->num_nodes)))
		return (slv_error_cleaning(err, path));
	max_num_p = g->start->num_linked_to > g->fin->num_linked_to ?
				g->start->num_linked_to : g->fin->num_linked_to;
	if (++err && !(path->path_starts = malloc(sizeof(t_room**) * max_num_p)))
		return (slv_error_cleaning(err, path));
	if (++err && !(path->path_lens = malloc(sizeof(int) * max_num_p)))
		return (slv_error_cleaning(err, path));
	if (++err && !(path->num_ants = malloc(sizeof(int) * max_num_p)))
		return (slv_error_cleaning(err, path));
	slv_clean_paths(path, g);
	return (path);
}

t_solver		*init_solver(t_map *g)
{
	t_solver	*slv;

	if (!(slv = (t_solver*)malloc(sizeof(t_solver))))
		return (NULL);
	slv->heap = bin_heap_init(g->num_nodes);
	slv->deq = deq_init_malloc(g->num_nodes, sizeof(t_room*));
	slv->paths_arr = slv_init_solution(g);
	slv->paths_arr_solution = slv_init_solution(g);
	return (slv);
}

void			remove_solver(t_solver *slv)
{
	if (slv)
	{
		bin_heap_free(slv->heap);
		deq_remove_unsafe(slv->deq);
		slv_error_cleaning(5, slv->paths_arr);
	}
	free(slv);
}
