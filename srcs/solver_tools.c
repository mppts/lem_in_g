# include <lem_in.h>

t_paths_arr		*slv_error_cleaning(int step, t_paths_arr *solution)
{
	if (step  == 1)
		free(solution);
	else if (step  == 2)
	{
		free(solution->path);
		free(solution);
	}
	else if (step  == 3)
	{
		free(solution->path_starts);
		free(solution->path);
		free(solution);
	}
	else if (step  == -1)
	{
		free(solution->path_lens);
		free(solution->path_starts);
		free(solution->path);
		free(solution);
	}
	return (NULL);
}

void			slv_clean_paths(t_paths_arr *solution, t_map *g)
{
	int			max_path_num;

	max_path_num = g->start->num_linked_to > g->fin->num_linked_to ?
				   g->start->num_linked_to : g->fin->num_linked_to;
	ft_bzero(solution->path, sizeof(t_room*) * g->num_nodes);
	ft_bzero(solution->path_starts, sizeof(t_room**) * max_path_num);
	ft_bzero(solution->path_lens, sizeof(int) * max_path_num);
	solution->path_starts = &solution->path;
	solution->amt_steps_cost = 0;
	solution->num_paths = 0;
}

t_paths_arr		*slv_init_solution(t_map *g)
{
	t_paths_arr	*path;
	int			max_path_num;
	int			err;

	err = 0;
	if (!(path = malloc(sizeof(t_paths_arr))))
		return (NULL);
	if (++err && !(path->path = malloc(sizeof(t_room*) * g->num_nodes)))
		return (slv_error_cleaning(err, path));
	max_path_num = g->start->num_linked_to > g->fin->num_linked_to ?
				   g->start->num_linked_to : g->fin->num_linked_to;
	if (++err && !(path->path_starts = malloc(sizeof(t_room**) * max_path_num)))
		return (slv_error_cleaning(err, path));
	if (++err && !(path->path_lens = malloc(sizeof(int) * max_path_num)))
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

void	remove_solver(t_solver *slv)
{
	if (slv)
	{
		bin_heap_free(slv->heap);
		deq_remove_unsafe(slv->deq);
		slv_error_cleaning(-1, slv->paths_arr);
		slv_error_cleaning(-1, slv->paths_arr_solution);
	}
	free(slv);
}