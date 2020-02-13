/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:38:24 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/12 16:38:29 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			enough_ways(t_map *map, t_graph_inf *inf)
{
	int		current_way_len;

	current_way_len = way_len_calc(inf->ways[inf->current_way_number]) - 1;
	if (!inf->are_enough_ways_current)
	{
		if (map->ants == 1)
			return (1);
		inf->are_enough_ways_current =
		((double)map->ants + (double)current_way_len) /
		(inf->current_way_number + 1);
		inf->total_ways_len += current_way_len;
		return (0);
	}
	else
	{
		inf->are_enough_ways_new =
		((double)map->ants + (double)(inf->total_ways_len + current_way_len)) /
		(inf->current_way_number + 1);
		if (inf->are_enough_ways_new >= inf->are_enough_ways_current)
		{
			inf->ways[inf->current_way_number][0] = NULL;
			return (1);
		}
		inf->total_ways_len += current_way_len;
		inf->are_enough_ways_current = inf->are_enough_ways_new;
		return (0);
	}
}

void		initialization_algo(t_graph_inf *inf, t_map *map)
{
	inf->two_flows = 0;
	inf->current_way_number = 0;
	inf->current_pos_in_way = 0;
	inf->position_in_way = 1;
	inf->ways[inf->current_way_number][0] = map->start;
	inf->are_enough_ways_current = 0;
	inf->total_ways_len = 0;
}

void		algo(t_map *map, t_graph_inf *inf)
{
	while (bfs(map->fin, map))
	{
		initialization_algo(inf, map);
		while ((dfs(map->start, inf, map)))
		{
			map->fin->color = WHITE;
			if (!inf->mirror_links[0] && enough_ways(map, inf))
				break ;
			inf->position_in_way = 1;
			(inf->current_way_number)++;
			inf->current_pos_in_way = 0;
			if (inf->ways[inf->current_way_number])
				inf->ways[inf->current_way_number][0] = map->start;
		}
		if (!inf->mirror_links[0])
		{
			if (inf->ways[inf->current_way_number] && inf->ways[inf->current_way_number][0] == map->start && !inf->ways[inf->current_way_number][1])
				inf->ways[inf->current_way_number][0] = NULL;
			break ;
		}
		else
			time_to_do_some_cleaning(map, inf);
	}
}
