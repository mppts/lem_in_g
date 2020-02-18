/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:38:24 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/16 04:38:41 by kona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int       enough_ways(t_map *map, t_graph_inf *inf)
{
	int       current_way_len;
	current_way_len = way_len_calc(inf->ways[inf->current_way_number]) - 1;
	if (!inf->are_enough_ways_current)
	{
		if (map->ants == 1)
			return (1);
		//if ((map->ants + current_way_len) % (inf->current_way_number + 1))
		//	inf->are_enough_ways_current = ((int)map->ants + current_way_len) / (inf->current_way_number + 1) + 1;
		//else
		inf->are_enough_ways_current = ((int)map->ants + current_way_len) / (inf->current_way_number + 1);
		inf->total_ways_len += current_way_len;
		return (0);
	}
	else
	{
		//if (((int)map->ants + (inf->total_ways_len + current_way_len)) % (inf->current_way_number + 1))
		//	inf->are_enough_ways_new = ((int)map->ants + (inf->total_ways_len + current_way_len)) / (inf->current_way_number + 1) + 1;
		//else
		inf->are_enough_ways_new = ((int)map->ants + (inf->total_ways_len + current_way_len)) / (inf->current_way_number + 1);
		if (inf->are_enough_ways_new < inf->are_enough_ways_current)
		{
			inf->total_ways_len += current_way_len;
			inf->are_enough_ways_current = inf->are_enough_ways_new;
			return (0);
		}
		inf->ways[inf->current_way_number][0] = NULL;
		return (1);
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
	map->start->level = 0;
	map->fin->level = 0;
	map->start->color = WHITE;
	//restore_meta_graph_info(map->room_start);
	//put_zero_to_flows(map->room_start);
	if (inf_min->are_enough_ways_current > inf->are_enough_ways_current && inf->are_enough_ways_current != 0)
	{
		inf_min->are_enough_ways_current = inf->are_enough_ways_current;
		if (inf_min->ways)
			free(inf_min->ways);
		inf_min->ways = inf->ways;
		inf->ways = memory_for_ways(map, inf->ways);
		inf_min->current_way_number = inf->current_way_number;
	}
}

int		save_prev_result(t_graph_inf *inf, t_map *map, t_graph_inf *inf_min)
{
	t_room	***tmp;

	if (inf_min->are_enough_ways_current > inf->are_enough_ways_current && inf->are_enough_ways_current != 0)
	{
		inf_min->are_enough_ways_current = inf->are_enough_ways_current;
		tmp = inf_min->ways;
		inf_min->ways = inf->ways;
		inf->ways = tmp;
		//inf_min->ways[inf->current_way_number + 1] = NULL;
		inf_min->current_way_number = inf->current_way_number;
	}
	return (0);
}


void		algo2(t_map *map, t_graph_inf *inf, t_graph_inf *inf_min)
{
	while (bfs_level(map->fin, map))
	{
		initialization_algo(inf, map, inf_min);
		while (dfs(map->start, inf, map))
		{
			map->start->color = WHITE;
			if (enough_ways(map, inf) || inf->two_flows)
				break ;
			(inf->current_way_number)++;
		}
		if (inf->two_flows == 0)
		{
			save_prev_result(inf, map, inf_min);
			break ;
		}
		else
		{
			save_prev_result(inf, map, inf_min);
			time_to_do_some_cleaning(map, inf);
		}
	}
}

void		algo3(t_map *map, t_graph_inf *inf, t_graph_inf *inf_min)
{
	while (bfs_level(map->fin, map) && bfs_potential(map->start, map))
	{
		initialization_algo(inf, map, inf_min);
		while (dfs_pl(map->start, inf, map))
		{
			map->start->color = WHITE;
			//if (inf->two_flows || enough_ways(map, inf))
			//	break ;
			(inf->current_way_number)++;
		}
		if (inf->two_flows == 0)
		{
			save_prev_result(inf, map, inf_min);
			break ;
		}
		else
		{
			save_prev_result(inf, map, inf_min);
			time_to_do_some_cleaning(map, inf);
		}
	}
}

