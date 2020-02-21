/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:50:11 by limry             #+#    #+#             */
/*   Updated: 2020/02/21 22:48:48 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include "binary_heap.h"

int 			pass_qrit(t_room *tmp, t_link *ln)
{
	if (ln->to->sign == 0 && ln->to->potential >= tmp->potential + ln->flow)
		return (1);
	//else if (ln->flow < 0)
	//	return (1);
	else if (ln->to->sign == 1 && ln->to->potential > tmp->potential + ln->flow)
		return (1);
	return (0);
	/*if (ln->to->potential < tmp->potential + 1)
		return (0);
	if (tmp->level == 1 && ln->to->level == 0)
		return (0);
	return (1);*/
}

int				bin_dijkstra(t_map *g, t_bin_heap *heap)
{
	t_room		*tmp;
	t_link		*link;

	bin_heap_insert(heap, g->start, g->start->potential);
	while(heap->num_nodes > 1)
	{
		tmp = (t_room*)bin_pop_root(tmp, heap);
		tmp->sign = 1;
		link = tmp->linked_to;
		//if (link && (!ft_strcmp(tmp->name, "H_y7")))
		//	5;
		while (link)
		{
			while (link && (link->to == tmp || link->flow == 0))
				link = link->next;
			if (link && ((pass_qrit(tmp, link))))
			{
				link->to->pred = tmp;
				link->to->potential = tmp->potential + link->flow;
				bin_heap_insert(heap, link->to, link->to->potential);
			}
			if (link && link->to == g->fin)
				return (1);
			if (link)
				link = link->next;
		}
	}
	return (0);
}