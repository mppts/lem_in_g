/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:42:37 by limry             #+#    #+#             */
/*   Updated: 2020/03/04 08:54:21 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				count_ants_for_paths(t_map *map)
{
	t_patha			*path;
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
			to_div -= (path->path_lens[i] - path->path_lens[iter]);
		if (to_div * 10 / ((iter) - i) % 10 >= 5 )
			path->num_ants[i] = to_div > 0 ? to_div / ((iter) - i) + 1 : 0;
		else
			path->num_ants[i] = to_div > 0 ? to_div / ((iter) - i) : 0;
		spreaded += path->num_ants[i];
		i++;
	}
}

void				prep_paths(t_patha *p, t_map *g)
{
	t_patha			*tmp;
	int				i;

	tmp = p;
	i = 0;
	while (i < tmp->path_id)
	{
		tmp->path_starts[i]++;
		tmp->path_lens[i]--;
		if (g->max_len < tmp->path_lens[i])
			g->max_len = tmp->path_lens[i];
		i++;
	}
}

void				print_desc(t_patha *pArr)
{
	int 			i;
	int 			j;

	i = 0;
	while (i < pArr->path_id)
	{
		j = 0;
		printf("%d %d: ",pArr->num_ants[i] , pArr->path_lens[i]);
		while (j < pArr->path_lens[i])
		{
			printf("[%s] ", pArr->path_starts[i][j]->name);
			j++;
		}
		printf("\n");
		i++;
	}
}

void				writer(t_map *map)
{
	dstr_joinstr(map->dstr, "\n");
	count_ants_for_paths(map);
	prep_paths(map->paths, map);
	//print_desc(map->paths);
	push_ants(map);
}
