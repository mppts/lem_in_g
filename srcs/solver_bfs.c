/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:43:01 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/12 16:43:07 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//int				bfs(t_map *map, t_room **line, t_graph_inf *inf)
//{
//	t_link		*tmp_link;
//	int			current_pos;
//	int			current_addition;
//
//	current_pos = 0;
//	current_addition = 1;
//	line[current_pos] = map->fin;
//	while (line[current_pos] && current_addition < map->num_nodes && line[current_addition] != map->start)
//	{
//		tmp_link = line[current_pos]->linked_to;
//		while (tmp_link)
//		{
//			if (!tmp_link->flow && !tmp_link->to->level && tmp_link->to != map->fin && tmp_link->to != line[current_pos] &&
//				(tmp_link->to->way_number == line[current_pos]->way_number ||
//				(tmp_link->to->way_number != line[current_pos]->way_number && line[current_pos]->room_from_we_came->way_number == line[current_pos]->way_number) ||
//				(line[current_pos]->way_number !=  tmp_link->to->way_number && line[current_pos]->room_from_we_came->way_number != -1 && tmp_link->to->way_number == -1)))
//			{
//				if (tmp_link->mirror->flow)
//					tmp_link->to->level = line[current_pos]->level - 1;
//				else
//					tmp_link->to->level = line[current_pos]->level + 1;
//				tmp_link->to->room_from_we_came = line[current_pos];
//				line[current_addition] = tmp_link->to;
//				if (line[current_addition] == map->start)
//					break ;
//				current_addition++;
//			}
//			tmp_link = tmp_link->next;
//		}
//		if (!current_pos && current_addition == 1)
//			break ;
//		current_pos++;
//	}
//	if (line[current_addition] && line[current_addition] == map->start)
//		return (current_addition);
//	return (0);
//}


//int				conditions_checking(t_map *map, t_link *tmp_link, t_room **line, int current_pos)
//{
//	if (!tmp_link->flow && !tmp_link->to->level && tmp_link->to != map->fin && tmp_link->to != line[current_pos] &&
//			(tmp_link->to->way_number == line[current_pos]->way_number ||
//					(tmp_link->to->way_number != line[current_pos]->way_number && line[current_pos]->room_from_we_came->way_number == line[current_pos]->way_number) ||
//						(line[current_pos]->way_number !=  tmp_link->to->way_number && line[current_pos]->room_from_we_came->way_number != -1 && tmp_link->to->way_number == -1)))
//		return (1);
//	return (0);
//}


//int				bfs(t_map *map, t_room **line, t_graph_inf *inf)
//{
//	t_link		*tmp_link;
//	int			current_pos;
//	int			current_addition;
//
//	current_pos = 0;
//	current_addition = 1;
//	line[current_pos] = map->fin;
//	while (line[current_pos] && current_addition < map->num_nodes && line[current_addition] != map->start)
//	{
//		tmp_link = line[current_pos]->linked_to;
//		while (tmp_link)
//		{
//			if (conditions_checking(map, tmp_link, line, current_pos))
//			{
//				if (tmp_link->mirror->flow)
//					tmp_link->to->level = line[current_pos]->level - 1;
//				else
//					tmp_link->to->level = line[current_pos]->level + 1;
//				tmp_link->to->room_from_we_came = line[current_pos];
//				line[current_addition] = tmp_link->to;
//				if (line[current_addition] == map->start)
//					break ;
//				current_addition++;
//			}
//			tmp_link = tmp_link->next;
//		}
//		if (!current_pos && current_addition == 1)
//			break ;
//		current_pos++;
//	}
//	if (line[current_addition] && line[current_addition] == map->start)
//		return (current_addition);
//	return (0);
//}


int				conditions_checking(t_map *map, t_link *tmp_link, t_room *room)
{
	if (!room->room_from_we_came && room != map->start)
		return (0);
	if (!tmp_link->flow && tmp_link->to != room->room_from_we_came && tmp_link->to != map->start &&
		(tmp_link->to->way_number == room->way_number ||
		 (tmp_link->to->way_number != room->way_number &&
		 room->room_from_we_came->way_number == room->way_number) ||
		 (room->way_number !=  tmp_link->to->way_number &&
		 room->room_from_we_came->way_number != -1 && tmp_link->to->way_number == -1)))
		return (1);
	return (0);
}

void			work_with_links(t_map *map, t_room *room, char *do_we_have_a_change)
{
	t_link		*tmp;

	tmp = room->linked_to;
	while (tmp)
	{
		if (conditions_checking(map, tmp, room))
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
		tmp = tmp->next;
	}
}

t_room			*find_way_bf(t_map *map, t_room **line)
{
	int			i;
	int			k;
	t_room		*tmp;
	t_room		**tmp_line;

	i = 0;
	k = 0;
	tmp_line = (t_room **)malloc(sizeof(t_room) * (map->num_nodes + 1));
	tmp = map->fin;
	while (tmp && tmp != map->start)
	{
		tmp_line[i++] = tmp;
		tmp = tmp->room_from_we_came;
	}
	if (!tmp)
		return (NULL);
	tmp_line[i] = tmp;
	while (i >= 0)
		line[k++] = tmp_line[i--];
	free(tmp_line);
	if (line[0] == map->start)
		return (line[0]);
	return (NULL);
}

int				bellman_ford(t_map *map, t_room **line, t_graph_inf *inf)
{
	t_room		*tmp_room;
	char		do_we_have_a_change;
	int			indicator;

	do_we_have_a_change = 1;
	while (do_we_have_a_change)
	{
		tmp_room = map->start;
		do_we_have_a_change = 0;
		indicator = 0;
		while (!indicator || tmp_room != map->start)
		{
			if (tmp_room != map->fin)
				work_with_links(map, tmp_room, &do_we_have_a_change);
			tmp_room = tmp_room->next;
			indicator++;
		}
	}
	if (find_way_bf(map, line))
		return (1);
	return (0);
}
