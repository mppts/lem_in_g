/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_bellman_ford_start_end.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:47:35 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/27 17:50:51 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				has_way_to_same_way(t_room *room, t_map *map)
{
	t_link		*tmp;

	tmp = room->linked_to;
	if (room->way_number == -1 && room != map->fin)
		return (1);
	while (tmp)
	{
		if (tmp->to->way_number == room->way_number &&
			!tmp->flow && tmp->mirror->flow)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				conditions_checking(t_map *map, t_link *tmp_link, t_room *room)
{
	if (!room->room_from_we_came && room != map->start)
		return (0);
	if (room == map->start && !tmp_link->flow)
		return (1);
	if (!tmp_link->flow && tmp_link->to != room->room_from_we_came
			&& tmp_link->to != map->start &&
		(room->way_number == tmp_link->to->way_number ||
			(room->way_number != tmp_link->to->way_number &&
				room->room_from_we_came->way_number == room->way_number &&
					(tmp_link->to->way_number == -1 ||
						has_way_to_same_way(tmp_link->to, map))) ||
		(room->way_number != tmp_link->to->way_number &&
			room->room_from_we_came->way_number != room->way_number
				&& room->way_number == -1 &&
					has_way_to_same_way(tmp_link->to, map))))
		return (1);
	return (0);
}

void			change_level(t_link *tmp, t_room *room,
								int *do_we_have_a_change)
{
	if (tmp->mirror->flow)
	{
		if (!tmp->to->level || room->level - 1 < tmp->to->level)
		{
			tmp->to->level = room->level - 1;
			tmp->to->room_from_we_came = room;
			(*do_we_have_a_change)++;
		}
	}
	else
	{
		if (!tmp->to->level || room->level + 1 < tmp->to->level)
		{
			tmp->to->level = room->level + 1;
			tmp->to->room_from_we_came = room;
			(*do_we_have_a_change)++;
		}
	}
}

void			work_with_links(t_map *map, t_room *room,
									int *do_we_have_a_change)
{
	t_link		*tmp;

	tmp = room->linked_to;
	while (tmp)
	{
		if (conditions_checking(map, tmp, room))
			change_level(tmp, room, do_we_have_a_change);
		tmp = tmp->next;
	}
}

int				bellman_ford(t_map *map, t_room **line)
{
	t_room		*tmp_room;
	int			do_we_have_a_change;
	int			indicator;

	do_we_have_a_change = 1;
	map->cycle_found = 0;
	while (do_we_have_a_change)
	{
		tmp_room = map->start;
		do_we_have_a_change = 0;
		indicator = 0;
		map->cycle_found++;
		if (map->cycle_found > map->num_nodes + 2)
			break ;
		while (!indicator || tmp_room != map->start)
		{
			if (tmp_room != map->fin)
				work_with_links(map, tmp_room, &do_we_have_a_change);
			tmp_room = tmp_room->next;
			indicator++;
		}
	}
	return (find_way_bf(map, line));
}
