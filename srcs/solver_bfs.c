/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:43:01 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/20 14:48:57 by limry            ###   ########.fr       */
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
			if (link && link->to->potential == 0 && link->to != room && link->flow == 0)
			{
				if (!find_source && (link->to == final))
					 find_source = link->to;
				if (link->to != final)
					deq_push_back(link->to, deq);
				link->to->potential = room->potential + 1;
			}
			link = link->next;
		}
	}
	return (find_source);
}
