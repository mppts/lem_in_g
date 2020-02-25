/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_push_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:31:36 by limry             #+#    #+#             */
/*   Updated: 2020/02/25 16:32:50 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				log_ant_move(t_room *room, t_map *map)
{
	dstr_joinstr(map->dstr, "L");
	dstr_joinstr(map->dstr, ft_itoa(room->ant));
	dstr_joinstr(map->dstr, "-");
	dstr_joinstr(map->dstr, room->name);
}

int					move_ant(int path_id, int cur_pos,
					int *ants_out, int *cur_ant, t_map *map)
{

	if (map->paths->path_starts[path_id][cur_pos]->ant ||
		(cur_pos != 0 && map->paths->path_starts[path_id][cur_pos - 1]->ant == 0))
		return (0);
	else if (cur_pos == 0 && map->paths->num_ants[path_id] > 0)
	{
		map->paths->path_starts[path_id][0]->ant = *cur_ant;
		(*cur_ant)++;
		map->paths->num_ants[path_id] -= 1;
		log_ant_move(map->paths->path_starts[path_id][cur_pos], map);
		return (1);
	}
	else if (map->paths->path_starts[path_id][cur_pos] == map->fin && map->paths->path_starts[path_id][cur_pos - 1]->ant != 0)
	{
		map->paths->path_starts[path_id][cur_pos]->ant = map->paths->path_starts[path_id][cur_pos - 1]->ant;
		log_ant_move(map->paths->path_starts[path_id][cur_pos], map);
		(*ants_out)++;
		map->paths->path_starts[path_id][cur_pos - 1]->ant = 0;
		map->paths->path_starts[path_id][cur_pos]->ant = 0;
		return (1);
	}
	else if (map->paths->path_starts[path_id][cur_pos - 1]->ant != 0)
	{
		map->paths->path_starts[path_id][cur_pos]->ant = map->paths->path_starts[path_id][cur_pos - 1]->ant;
		map->paths->path_starts[path_id][cur_pos - 1]->ant = 0;
		log_ant_move(map->paths->path_starts[path_id][cur_pos], map);
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
	step = 0;
	cur_ant = 1;
	while (ants_out < map->ants)
	{
		step_iter = ++step;
		while (step_iter--)
		{
			cur_path = -1;
			while (cur_path++ < map->paths->path_id)
				if (move_ant(cur_path, step_iter %
				map->paths->path_lens[cur_path], &ants_out, &cur_ant, map))
					dstr_joinstr(map->dstr, " ");
		}
		dstr_joinstr(map->dstr, "\n");
	}
}