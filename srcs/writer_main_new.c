/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:42:37 by limry             #+#    #+#             */
/*   Updated: 2020/02/16 04:38:40 by kona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
void				writer(t_map *map)
{
	int				i;
	int				ants;
	t_positioner	*paths;
	t_path			*tmp;

	i = 0;
	ants = 0;
	paths = (t_positioner*)malloc(map->ants * sizeof(t_positioner));
	while (ants < map->ants)
	{
		tmp = map->path;
		while (tmp && ants < map->ants)
		{
			paths[ants].path = tmp;
			paths[ants].offset = i;
			ants++;
			tmp = tmp->next;
		}
		i++;
	}
	generate_paths(map, paths);
	free(paths);
}
*/

void 			count_ants_for_paths(t_map *map)
{
	t_paths_arr	*path;
	int			to_div;
	int			spreaded;
	int			iter;
	int			i;

	spreaded = 0;
	path = map->paths;
	i = 0;
	while (i < path->current_path)
	{
		to_div = map->ants - spreaded;
		iter = i;
		while (++iter < map->paths->current_path)
		{
			to_div -= (path->path_lens[i] - path->path_lens[iter]);
		}
		path->num_ants[i] = to_div > 0 ? to_div / (iter - i) : 0;
		//path->num_ants[i] = path->num_ants[i] > (map->ants - spreaded) ?
		//		(int)map->ants - spreaded : path->num_ants[i];
		spreaded += path->num_ants[i];
		i++;
	}
}

void				log_ant_move(t_room *room, t_map *map, int path_id)
{
	int 			color;

	color = path_id % 8 + 30;
	dstr_joinstr(map->dstr, "\033[1;");
	dstr_joinstr(map->dstr, ft_itoa(color));
	dstr_joinstr(map->dstr, "m");
	dstr_joinstr(map->dstr, "L");
	dstr_joinstr(map->dstr, ft_itoa(room->ant));
	dstr_joinstr(map->dstr, "-");
	dstr_joinstr(map->dstr, room->name);
	dstr_joinstr(map->dstr, "\033[0m");
}

int				move_ant(int path_id, int cur_pos, int *ants_out, int *cur_ant, t_map *map)
{

	if (map->paths->path_starts[path_id][cur_pos]->ant ||
		(cur_pos != 0 && map->paths->path_starts[path_id][cur_pos - 1]->ant == 0))
		return (0);
	else if (cur_pos == 0 && map->paths->num_ants[path_id] > 0)
	{
		map->paths->path_starts[path_id][0]->ant = *cur_ant;
		(*cur_ant)++;
		map->paths->num_ants[path_id] -= 1;
		log_ant_move(map->paths->path_starts[path_id][cur_pos], map, path_id);
		return (1);
	}
	else if (map->paths->path_starts[path_id][cur_pos] == map->fin && map->paths->path_starts[path_id][cur_pos - 1]->ant != 0)
	{
		map->paths->path_starts[path_id][cur_pos]->ant = map->paths->path_starts[path_id][cur_pos - 1]->ant;
		log_ant_move(map->paths->path_starts[path_id][cur_pos], map, path_id);
		(*ants_out)++;
		map->paths->path_starts[path_id][cur_pos - 1]->ant = 0;
		map->paths->path_starts[path_id][cur_pos]->ant = 0;
		return (1);
	}
	else if (map->paths->path_starts[path_id][cur_pos - 1]->ant != 0)
	{
		map->paths->path_starts[path_id][cur_pos]->ant = map->paths->path_starts[path_id][cur_pos - 1]->ant;
		map->paths->path_starts[path_id][cur_pos - 1]->ant = 0;
		log_ant_move(map->paths->path_starts[path_id][cur_pos], map, path_id);
		return (1);
	}
	return (0);
}

void				push_ants(t_map *map)
{
	int				step;
	int				step_iter;
	int				ants_out;
	int				cur_ant;
	int				cur_path;

	ants_out = 0;
	step = 1;
	cur_ant = 1;
	while (ants_out < map->ants)
	{
		step_iter = step;
		while (step_iter--)
		{
			cur_path = 0;
			while (cur_path < map->paths->current_path)
			{
				if (move_ant(cur_path, step_iter % map->paths->path_lens[cur_path], &ants_out, &cur_ant, map))
					dstr_joinstr(map->dstr, " ");
				cur_path++;
			}
		}
		dstr_joinstr(map->dstr, "\n");
		step++;
	}
}

void				swap_paths(t_path *bigger, t_path *smaller)
{
	t_path			swap;

	swap.path = bigger->path;
	swap.len = bigger->len;
	bigger->path = smaller->path;
	bigger->len = smaller->len;
	smaller->path = swap.path;
	smaller->len = swap.len;
}

void 				sort_paths(t_map *map)
{
	t_path			*tmp1;
	t_path			*tmp2;
	int 			i;

	i = 1;
	tmp1 = map->path;
	tmp2 = tmp1->next;
	while (i)
	{
		i = 0;
		while (tmp1 && tmp2)
		{
			if (tmp1->len > tmp2->len)
			{
				swap_paths(tmp1, tmp2);
				i = 1;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		tmp1 = map->path;
		tmp2 = tmp1->next;
	}
}

void				print_paths(t_path *p)
{
	t_path			*tmp;
	uint64_t		i;

	tmp = p;
	while(tmp)
	{
		i = 0;
		while (i < tmp->len)
		{
			printf("[%s] ", tmp->path[i]->name);
			i++;
		}
		printf("\n");
		tmp = tmp->next;
	}
}

void				prep_paths(t_paths_arr *p)
{
	t_paths_arr			*tmp;
	int 			i;

	tmp = p;
	i = 0;
	while(i < tmp->current_path)
	{
		tmp->path_starts[i]++;
		tmp->path_lens[i]--;
		i++;
	}
}


void				writer(t_map *map)
{
	//sort_paths(map);
	//print_paths(map->path);
	count_ants_for_paths(map);
	prep_paths(map->paths);
	push_ants(map);
}