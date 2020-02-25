/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:50:11 by limry             #+#    #+#             */
/*   Updated: 2020/02/25 21:21:15 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include "binary_heap.h"

static void		pass_qrit(t_room *tmp, t_link *ln, t_bin_heap *heap)
{
	if (ln && ((ln->to->delta >
	tmp->potential - ln->to->potential + ln->flow + tmp->delta)))
	{
		ln->to->pred = tmp;
		ln->to->delta =
		tmp->potential - ln->to->potential + ln->flow + tmp->delta;
		bin_heap_insert(heap, ln->to, ln->to->delta);
	}
}

int				bin_dijkstra(t_map *g, t_bin_heap *heap)
{
	t_room		*tmp;
	t_link		*ln;
	int			flag;

	flag = 0;
	bin_heap_insert(heap, g->start, g->start->delta);
	while (heap->num_nodes > 1)
	{
		tmp = (t_room*)bin_pop_root(tmp, heap);
		tmp->sign = 1;
		ln = tmp->linked_to;
		while (ln)
		{
			while (ln && (ln->to == tmp || ln->flow == 0))
				ln = ln->next;
			pass_qrit(tmp, ln, heap);
			if (ln && ln->to == g->fin)
				flag = 1;
			if (ln)
				ln = ln->next;
		}
	}
	return (flag);
}
