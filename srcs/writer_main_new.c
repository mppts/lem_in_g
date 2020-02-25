/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:42:37 by limry             #+#    #+#             */
/*   Updated: 2020/02/25 16:29:25 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 				count_ants_for_paths(t_map *map)
{
	t_paths_arr		*path;
	int				to_div;
	int				spreaded;
	int				iter;
	int				i;

	spreaded = 0;
	path = map->paths;
	i = 0;
	while (i < path->path_id)
	{
		to_div = map->ants - spreaded;
		iter = i;
		while (++iter < map->paths->path_id)
		{
			to_div -= (path->path_lens[i] - path->path_lens[iter]);
		}
		path->num_ants[i] = to_div > 0 ? to_div / (iter - i) : 0;
		spreaded += path->num_ants[i];
		i++;
	}
}


void				prep_paths(t_paths_arr *p)
{
	t_paths_arr		*tmp;
	int 			i;

	tmp = p;
	i = 0;
	while(i < tmp->path_id)
	{
		tmp->path_starts[i]++;
		tmp->path_lens[i]--;
		i++;
	}
}

void				writer(t_map *map)
{
	count_ants_for_paths(map);
	prep_paths(map->paths);
	push_ants(map);
}