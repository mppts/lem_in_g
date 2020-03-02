/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:42:37 by limry             #+#    #+#             */
/*   Updated: 2020/03/02 12:38:16 by limry            ###   ########.fr       */
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

int					move_ant2(int slv[4], int cur_pos,
					t_map *map, t_path *cpath)
{
	if (cpath->path[cur_pos] == map->fin &&
			cpath->path[cur_pos - 1]->ant != 0)
	{
		cpath->path[cur_pos]->ant =
				cpath->path[cur_pos - 1]->ant;
		log_ant_move(cpath->path[cur_pos], map);
		(slv[2])++;
		cpath->path[cur_pos - 1]->ant = 0;
		cpath->path[cur_pos]->ant = 0;
		return (1);
	}
	else if (cpath->path[cur_pos - 1]->ant != 0
	&& cpath->path[cur_pos]->ant == 0)
	{
		cpath->path[cur_pos]->ant =
				cpath->path[cur_pos - 1]->ant;
		cpath->path[cur_pos - 1]->ant = 0;
		log_ant_move(cpath->path[cur_pos], map);
		return (1);
	}
	return (0);
}

int					move_ant(int slv[4], int cur_pos,
					t_map *map, t_path *cpath)
{
	if (cpath->path[cur_pos]->ant ||
		(cur_pos != 0 &&
				cpath->path[cur_pos - 1]->ant == 0))
		return (0);
	else if (cur_pos == 0 && cpath->ants > 0)
	{
		cpath->path[cur_pos]->ant = slv[3];
		slv[3] += 1;
		cpath->ants--;
		log_ant_move(cpath->path[cur_pos], map);
		return (1);
	}
	else
		return (move_ant2(slv, cur_pos, map, cpath));
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
	int				slv[4];
	t_path			*cpath;

	slv[2] = 0;
	slv[0] = 0;
	slv[3] = 1;
	while (slv[2] < map->ants)
	{
		cpath = map->path;
		while (cpath)
		{
			slv[1] = cpath->len;
			while (slv[1]-- > 0 && slv[2] < map->ants)
			{
				if (move_ant(slv, slv[1], map, cpath))
					dstr_joinstr(map->dstr, " ");
			}
			cpath = cpath->next;
		}
		dstr_remove_back(map->dstr, 1);
		dstr_joinstr(map->dstr, "\n");
	}
}

void				writer(t_map *map)
{
	dstr_joinstr(map->dstr, "\n");
	prep_paths(map->path, 1);
	if (map->path->len == 1)
		simple_writer(map);
	else
	{
		count_ants_for_paths(map);
		push_ants(map);
	}
	prep_paths(map->path, 0);
}
