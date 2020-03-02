/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:32:09 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/27 19:32:12 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			nulls_to_ways(t_room **way_1, t_room **way_2, int len)
{
	int			i;

	i = 0;
	while (i <= len)
	{
		way_1[i] = NULL;
		way_2[i++] = NULL;
	}
}

void			algo(t_map *map, t_graph_inf *inf)
{
	t_room		**way_1;
	t_room		**way_2;
	int			indicator;

	way_1 = (t_room **)malloc(sizeof(t_room *) * (map->num_nodes + 1));
	way_2 = (t_room **)malloc(sizeof(t_room *) * (map->num_nodes + 1));
	nulls_to_ways(way_1, way_2, map->num_nodes);
	indicator = 0;
	while (!indicator && (find_best_current_way(map, way_1, way_2)))
	{
		find_way_1(map, way_1, inf);
		if (sufficienty_c(inf, map))
			indicator = 1;
		if (!indicator && inf->common_rooms[0])
			separate_cross_ways(inf, map);
		auxiliary_works(map, inf, way_1);
		if (!indicator)
			inf->current_way_number++;
	}
	free(way_1);
	free(way_2);
}
