/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:42:37 by limry             #+#    #+#             */
/*   Updated: 2020/02/10 17:45:14 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				join_ant_move(t_map *map, t_positioner paths[map->ants],
					int ants, int step)
{
	dstr_joinstr(map->dstr, "L");
	dstr_joinstr(map->dstr, ft_itoa(ants + 1));
	dstr_joinstr(map->dstr, "-");
	dstr_joinstr(map->dstr, (paths[ants].path->path[step])->name);
}

void				generate_paths(t_map *map, t_positioner paths[map->ants])
{
	int				step;
	int				ants;
	int				ants_out;

	step = 0;
	ants_out = 0;
	while (ants_out != map->ants)
	{
		ants = ants_out;
		while (paths[ants].offset == step &&
		paths[ants].path->len > paths[ants].offset)
		{
			join_ant_move(map, paths, ants, step);
			if (++(paths[ants].offset) > paths[ants].path->len)
				ants_out++;
			ants++;
		}
		step++;
		dstr_joinstr(map->dstr, "\n");
	}
}

void				writer(t_map *map)
{
	int				i;
	int				ants;
	t_positioner	paths[map->ants];
	t_path			*tmp;

	i = 0;
	ants = 0;
	while (ants < map->ants)
	{
		tmp = map->paths;
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
}
