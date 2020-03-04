/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_find_best_current_way.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:52:32 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/27 17:52:35 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		copy_2_to_1(t_room **way_1, t_room **way_2)
{
	int	one;
	int	two;

	one = 0;
	two = 0;
	while (way_1[one])
		way_1[one++] = NULL;
	one = 0;
	while (way_2[two])
		way_1[one++] = way_2[two++];
	two = 0;
	while (way_2[two])
		way_2[two++] = NULL;
}

int			compare_ways(t_room **way_1, t_room **way_2)
{
	int		one;
	int		two;

	if (!way_1[1] && !way_2[1])
		return (0);
	else if (!way_2[1])
		return (1);
	else if (!way_1[1])
	{
		copy_2_to_1(way_1, way_2);
		return (1);
	}
	one = 0;
	two = 0;
	while (way_1[one])
		one++;
	while (way_2[two])
		two++;
	if (two < one)
		copy_2_to_1(way_1, way_2);
	else
		while (two >= 0)
			way_2[two--] = NULL;
	return (1);
}

void		clear_precessors(t_map *map)
{
	t_room	*tmp;
	int		indicator;

	tmp = map->start;
	indicator = 0;
	while (!indicator || tmp != map->start)
	{
		tmp->c_in_way = 0;
		tmp->room_from_we_came = NULL;
		tmp = tmp->next;
		indicator++;
	}
}

int			find_best_current_way(t_map *map, t_room **way_1,
								t_room **way_2)
{
	bellman_ford(map, way_1);
	clear_precessors(map);
	bellman_ford_rev(map, way_2);
	if (!compare_ways(way_1, way_2))
		return (0);
	return (1);
}
