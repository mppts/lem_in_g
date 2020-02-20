/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:43:01 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/19 17:48:07 by kona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*bfs_potential(t_room *start, t_room *final,
				t_map *map, t_deq *deq)
{
	t_link		*link;
	t_room		*room;
	t_room		*find_source;

	deq_push_back(start, deq);
	while (deq->begin <= deq->rear)
	{
		room = (t_room*)deq_pop_front(deq);
		link = room->linked_to;
		while (link)
		{
			if (link->to->potential == 0 && link->to != room && link->flow == 0)
			{
				if (!find_source && (link->to == final))
					 find_source = link->to;
				if (link->to != final)
					deq_push_back(link->to, deq);
				link->to->potential = room->potential + 1;
				link->to->lev_m_pot = link->to->level - link->to->potential;
				link->w = room->potential - link->to->potential + link->w;
			}
			link = link->next;
		}
	}
	return (find_source);
}

/*

t_room			*bfs_level(t_room *sink, t_map *map)
{
	t_link		*tmp_link;
	t_room		**line;
	int			current_pos;
	int			current_addition;
	t_room		*find_source;

	if (!sink)
		return (NULL);
	initialization_bfs(&find_source, &current_addition, &current_pos);
	line = (t_room **)malloc(sizeof(t_room *) * (map->num_nodes + 1));
	ft_bzero(line, sizeof(t_room *) * (map->num_nodes + 1));
	line[map->num_nodes] = NULL;
	line[current_pos] = sink;
	while (line[current_pos])
	{
		tmp_link = line[current_pos]->linked_to;
		while (tmp_link)
		{
			if (tmp_link->to->level == 0 && tmp_link->to != sink && tmp_link->flow == 0)
			{
				if (!find_source && (tmp_link->to == map->start))
					 find_source = tmp_link->to;
				if (tmp_link->to != map->start)
					line[current_addition++] = tmp_link->to;
				tmp_link->to->level = line[current_pos]->level + 1;
			}
			tmp_link = tmp_link->next;
		}
		current_pos++;
	}
	free(line);
	return (find_source);
}
*/