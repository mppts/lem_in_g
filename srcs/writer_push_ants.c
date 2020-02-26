/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_push_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:31:36 by limry             #+#    #+#             */
/*   Updated: 2020/02/26 16:28:15 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				log_ant_move(t_room *room, t_map *map)
{
	char			*num;

	dstr_joinstr(map->dstr, "L");
	dstr_joinstr(map->dstr, num = ft_itoa(room->ant));
	dstr_joinstr(map->dstr, "-");
	dstr_joinstr(map->dstr, room->name);
	free(num);
}

int					move_ant2(int slv[5], int cur_pos, t_map *map)
{
	if (map->paths->path_starts[slv[4]][cur_pos] == map->fin &&
	map->paths->path_starts[slv[4]][cur_pos - 1]->ant != 0)
	{
		map->paths->path_starts[slv[4]][cur_pos]->ant =
				map->paths->path_starts[slv[4]][cur_pos - 1]->ant;
		log_ant_move(map->paths->path_starts[slv[4]][cur_pos], map);
		(slv[2])++;
		map->paths->path_starts[slv[4]][cur_pos - 1]->ant = 0;
		map->paths->path_starts[slv[4]][cur_pos]->ant = 0;
		return (1);
	}
	else if (map->paths->path_starts[slv[4]][cur_pos - 1]->ant != 0
	&& map->paths->path_starts[slv[4]][cur_pos]->ant == 0)
	{
		map->paths->path_starts[slv[4]][cur_pos]->ant =
				map->paths->path_starts[slv[4]][cur_pos - 1]->ant;
		map->paths->path_starts[slv[4]][cur_pos - 1]->ant = 0;
		log_ant_move(map->paths->path_starts[slv[4]][cur_pos], map);
		return (1);
	}
	return (0);
}

int					move_ant(int slv[5], int cur_pos, t_map *map)
{
	if (map->paths->path_starts[slv[4]][cur_pos]->ant ||
		(cur_pos != 0 &&
		map->paths->path_starts[slv[4]][cur_pos - 1]->ant == 0))
		return (0);
	else if (cur_pos == 0 && map->paths->num_ants[slv[4]] > 0)
	{
		map->paths->path_starts[slv[4]][0]->ant = slv[3];
		slv[3] += 1;
		map->paths->num_ants[slv[4]] -= 1;
		log_ant_move(map->paths->path_starts[slv[4]][cur_pos], map);
		return (1);
	}
	else
		return (move_ant2(slv, cur_pos, map));
}

/*
**	0 - step;
**	1 - step_iter;
**	2 - ants_out;
**	3 - cur_ant;
**	4 - cur_path;
*/

void				push_ants(t_map *map)
{
	int				slv[5];

	slv[2] = 0;
	slv[0] = 0;
	slv[3] = 1;
	while (slv[2] < map->ants)
	{
		dstr_joinstr(map->dstr, ft_itoa(slv[0]++));
		dstr_joinstr(map->dstr, ": ");
		slv[4] = -1;
		while (++slv[4] < map->paths->path_id)
		{
			slv[1] = map->paths->path_lens[slv[4]] - 1;
			while (slv[1] >= 0)
			{
				if (move_ant(slv, slv[1] % map->paths->path_lens[slv[4]], map))
					dstr_joinstr(map->dstr, " ");
				slv[1]--;
			}
		}
		dstr_remove_back(map->dstr, 1);
		dstr_joinstr(map->dstr, "\n");
	}
}
