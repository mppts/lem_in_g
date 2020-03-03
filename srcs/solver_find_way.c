/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_find_way.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:13:18 by dorphan           #+#    #+#             */
/*   Updated: 2020/03/02 22:39:57 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way		*add_new_way_pos(t_room *room, t_graph_inf *inf, t_map *map)
{
	t_way	*tmp;

	tmp = (t_way *)malloc(sizeof(t_way));
	tmp->room = room;
	if (room->way_number == -1)
		tmp->room->way_number = inf->current_way_number;
	tmp->way_number = inf->current_way_number;
	tmp->next = NULL;
	tmp->prev_way = NULL;
	tmp->way_len = map->start->level;
	return (tmp);
}

void		add_flow(t_room *room, t_room *next_room)
{
	t_link	*link;

	if (next_room)
	{
		link = room->linked_to;
		while (link->to != next_room)
			link = link->next;
		link->flow = 1;
	}
}

void		add_to_common_rooms(t_graph_inf *inf, t_room *room)
{
	int		i;

	i = 0;
	while (inf->common_rooms[i])
		i++;
	inf->common_rooms[i] = room;
}

void		find_way_1(t_map *map, t_room **line, t_graph_inf *inf)
{
	int		i;
	t_way	*current_vertex;

	i = 0;
	inf->ways[inf->current_way_number] = add_new_way_pos(line[i], inf, map);
	map->start->way_number = -1;
	current_vertex = inf->ways[inf->current_way_number];
	add_flow(line[i], line[i + 1]);
	i++;
	while (line[i])
	{
		if (line[i]->way_number == -1)
			line[i]->way_number = inf->current_way_number;
		else
			add_to_common_rooms(inf, line[i]);
		current_vertex->next = add_new_way_pos(line[i], inf, map);
		current_vertex = current_vertex->next;
		add_flow(line[i], line[i + 1]);
		i++;
	}
}
