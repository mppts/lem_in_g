/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:50:11 by limry             #+#    #+#             */
/*   Updated: 2020/02/26 20:26:21 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include "binary_heap.h"

int64_t			get_room_delta(void *rm)
{
	t_room		*trm;

	trm = (t_room*)rm;
	return (trm->delta);
}

int				neg_can_go(t_room *rm, int64_t new_delta)
{
	t_link		*ln;

	ln = rm->linked_to;
	while (ln)
	{
		if (ln->flow == -1 && ln->to->delta > new_delta)
			return (1);
		ln = ln->next;
	}
	return (0);
}

static int		pass_qrit(t_room *tmp, t_link *ln, t_bin_heap *heap, t_map *m)
{
	int 	flag;

	flag = 0;
	if (ln->to->delta > tmp->potential - ln->to->potential + ln->flow + tmp->delta)
	{
		if (tmp->level == 0)
		{
			if ((ln->to->level == 0 || neg_can_go(ln->to, tmp->potential - ln->to->potential + ln->flow + tmp->delta)))
			{
				ln->to->pred = tmp;
				ln->to->delta = tmp->potential - ln->to->potential + ln->flow + tmp->delta;
				if (m->fin != ln->to)
					ln->to->flv = bin_heap_insert(heap, ln->to, ln->to->delta);
				flag = 1;
			}
			else
				ln->to->delta = INT64_MAX;
		}
		else if (tmp->level != 0 && ln->flow == 1 && (tmp->pred_neg || (tmp->pred && tmp->pred->level != 0)))
		{
			ln->to->pred = tmp;
			ln->to->delta = tmp->potential - ln->to->potential + ln->flow + tmp->delta;
			if (m->fin != ln->to)
				ln->to->flv = bin_heap_insert(heap, ln->to, ln->to->delta);
			flag = 2;
		}
		else if (tmp->level != 0 && ln->flow == -1)
		{
			ln->to->pred_neg = tmp;
			ln->to->delta = tmp->potential - ln->to->potential + ln->flow + tmp->delta;
			if (m->fin != ln->to)
				ln->to->flv = bin_heap_insert(heap, ln->to, ln->to->delta);
			flag = 3;
		}
		//if (!flag)
		//	tmp->delta = heap->nodes[heap->num_nodes].key;
		return (1);
	}
	/*else if (tmp->level != 0 && ln->flow == -1)
	{
		ln->to->delta = tmp->potential - ln->to->potential + ln->flow + tmp->delta;
		if (ln->to->flv)
		{
			bin_refresh_keys(heap, get_room_delta);
			bin_heap_restore(heap);
		}
		else
			ln->to->flv = bin_heap_insert(heap, ln->to, ln->to->delta);
	}*/
	return (0);
}

int				bin_dijkstra(t_map *g, t_bin_heap *heap)
{
	t_room		*tmp;
	t_link		*ln;
	int			flag;

	flag = 0;
	bin_heap_insert(heap, g->start, g->start->delta);
	g->start->flv = 1;
	while (heap->num_nodes > 1)
	{
		tmp = (t_room*)bin_pop_root(tmp, heap);
		tmp->sign = 1;
		tmp->flv = 0;
		ln = tmp->linked_to;
		while (ln)
		{
			while (ln && (ln->flow == 0))
				ln = ln->next;
			ln && pass_qrit(tmp, ln, heap, g);
			if (ln && ln->to == g->fin)
				flag = 1;
			if (ln)
				ln = ln->next;
		}
	}
	printf("\n");
	return (flag);
}
