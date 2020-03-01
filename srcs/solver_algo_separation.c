/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_algo_separation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:05:50 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/27 19:05:51 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clear_flow(t_room *room_1, t_room *room_2)
{
	t_link	*tmp;

	tmp = room_1->linked_to;
	while (tmp->to != room_2)
		tmp = tmp->next;
	tmp->flow = 0;
	tmp->mirror->flow = 0;
}

void		separation_cycle_addition(t_way *tmp, t_way **tmp_sep,
										t_graph_inf *inf)
{
	t_way	*way_2;

	clear_flow((*tmp_sep)->room, (*tmp_sep)->next->room);
	tmp = *tmp_sep;
	(*tmp_sep)->room->way_number = -1;
	*tmp_sep = (*tmp_sep)->next;
	way_2 = inf->ways[inf->helper];
	while (way_2->room != tmp->room)
		way_2 = way_2->next;
	free(way_2);
	free(tmp);
}

t_way		*separation(t_way *tmp, t_graph_inf *inf)
{
	t_way	*tmp_sep;
	t_way	*way_2;

	inf->helper = tmp->room->way_number;
	way_2 = inf->ways[inf->helper];
	while (way_2 && way_2->room != tmp->room)
		way_2 = way_2->next;
	tmp->prev_way = tmp->next;
	tmp->next = way_2->next;
	tmp_sep = tmp->prev_way;
	clear_flow(tmp->room, tmp_sep->room);
	free(way_2);
	while (tmp_sep->room->way_number == tmp_sep->next->room->way_number)
		separation_cycle_addition(tmp, &tmp_sep, inf);
	way_2 = inf->ways[tmp_sep->room->way_number];
	while (way_2 && way_2->room != tmp_sep->room)
		way_2 = way_2->next;
	if (way_2 && way_2->next)
		way_2->next = tmp_sep->next;
	way_2 = tmp_sep->next;
	free(tmp_sep);
	return (way_2);
}

void		separate_cross_ways(t_graph_inf *inf, t_map *map)
{
	t_way	*tmp;
	int		common_room;

	common_room = 0;
	tmp = inf->ways[inf->current_way_number];
	while (tmp->room != map->fin)
	{
		if (tmp->room != map->start && tmp->way_number != tmp->room->way_number)
			tmp = separation(tmp, inf);
		else
			tmp = tmp->next;
	}
	while (inf->common_rooms[common_room])
		inf->common_rooms[common_room] = NULL;
}
