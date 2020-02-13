/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:38:24 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/13 22:00:44 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			enough_ways(t_map *map, t_graph_inf *inf)
{
	int		current_way_len;

	current_way_len = inf->current_pos_in_way;
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
		if (inf->are_enough_ways_new > inf->are_enough_ways_current)
		{
			inf->ways[inf->current_way_number][0] = NULL;
			return (1);
		}
		inf->total_ways_len += current_way_len;
		inf->are_enough_ways_current = inf->are_enough_ways_new;
		return (0);
	}
}

void		initialization_algo(t_graph_inf *inf, t_map *map, t_graph_inf *inf_min)
{
	inf->two_flows = 0;
	inf->current_way_number = 0;
	inf->current_pos_in_way = 1;
	inf->ways[inf->current_way_number][0] = map->start;
	inf->are_enough_ways_current = 0;
	inf->total_ways_len = 0;
	map->start->level = INT64_MAX - 1;
	if (inf_min->are_enough_ways_current > inf->are_enough_ways_current)
	{
		inf_min->are_enough_ways_current = inf->are_enough_ways_current;
		if (inf_min->ways)
			free(inf_min->ways);
		inf_min->ways = inf->ways;
		inf->ways = memory_for_ways(map, inf->ways);
		inf_min->current_way_number = inf->current_way_number;
	}
}

void		algo2(t_map *map, t_graph_inf *inf, t_graph_inf *inf_min)
{
	while (bfs(map->fin, map))
	{
		initialization_algo(inf, map, inf_min);
		while ((dfs(map->start, inf, map)))
		{
			map->start->color = WHITE;
			if (enough_ways(map, inf))
				break ;
			(inf->current_way_number)++;
			inf->current_pos_in_way = 1;
			if (inf->ways[inf->current_way_number])
				inf->ways[inf->current_way_number][0] = map->start;
		}
		if (inf->two_flows == 0)
		{
			inf->ways[inf->current_way_number + 1] = NULL;
			break ;
		}
		else
			time_to_do_some_cleaning(map, inf);
	}
}
