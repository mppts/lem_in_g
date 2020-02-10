/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:42:37 by limry             #+#    #+#             */
/*   Updated: 2020/02/10 17:42:39 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				join_ant_move(t_map *map, t_positioner paths[map->ants],
					int ants, int offset)
{
	dstr_joinstr(map->dstr, "L");
	dstr_joinstr(map->dstr, ft_itoa(ants + 1));
	dstr_joinstr(map->dstr, "-");
	dstr_joinstr(map->dstr, (paths[ants].path->path[offset])->name);
}

void				generate_paths(t_map *map, t_positioner paths[map->ants])
{
	int				offset;
	int				ants;
	int				ants_out;

	offset = 0;
	ants_out = 0;
	while (ants_out != map->ants)
	{
		ants = ants_out;
		while (paths[ants].offset == offset &&
		paths[ants].path->len > paths[ants].offset)
		{
			join_ant_move(map, paths, ants, offset);
			if (++(paths[ants].offset) > paths[ants].path->len)
				ants_out++;
			ants++;
		}
		offset++;
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
	while (map->ants - ants)
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
