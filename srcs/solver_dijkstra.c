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

static void		pass_qrit(t_room *tmp, t_link *ln, t_bin_heap *heap, t_map *m)
{
	if (ln && (tmp->level == 0 && (ln->to->delta >
	tmp->potential - ln->to->potential + ln->flow + tmp->delta)))
	{
			ln->to->pred = tmp;
			ln->to->delta = tmp->potential - ln->to->potential + ln->flow + tmp->delta;
			if (m->fin != ln->to)
			bin_heap_insert(heap, ln->to, ln->to->delta);
	}
	else if (ln && ((tmp->level == 1 && ln->flow == -1 && ln->to->sign == 0)
	&& (ln->to->delta > tmp->potential - ln->to->potential + ln->flow + tmp->delta)))
	{
		ln->to->pred = tmp;
		ln->to->delta =\
		tmp->potential - ln->to->potential + ln->flow + tmp->delta;
		bin_heap_insert(heap, ln->to, ln->to->delta);
	}
	else if (ln && tmp->level == 1 && ln->flow == -1 && ln->to->sign == 1)
	{
		if (ln->to->pred != tmp)
		{
			ln->to->pred_neg = tmp;
			ln->to->delta =\
			tmp->potential - ln->to->potential + ln->flow + tmp->delta;
			bin_heap_insert(heap, ln->to, ln->to->delta);
		}
	}
	else if (ln && ((tmp->level == 1 && ((tmp->pred_neg && tmp->pred_neg->level == 1) || tmp->pred->level == 1))
	&& (ln->to->delta > tmp->potential - ln->to->potential + ln->flow + tmp->delta)))
	{
		ln->to->pred = tmp;
		ln->to->delta =\
		tmp->potential - ln->to->potential + ln->flow + tmp->delta;
		bin_heap_insert(heap, ln->to, ln->to->delta);
	}
}

int				bin_dijkstra(t_map *g, t_bin_heap *heap)
{
	t_room		*tmp;
	t_room		*tmp_pred;
	t_link		*ln;
	int			flag;

	flag = 0;
	tmp_pred = NULL;
	bin_heap_insert(heap, g->start, g->start->delta);
	while (heap->num_nodes > 1)
	{
		tmp = (t_room*)bin_pop_root(tmp, heap);
		tmp->sign = 1;
		ln = tmp->linked_to;
		while (ln)
		{
			while (ln && (tmp_pred == ln->to || ln->flow == 0 || ln->to == g->start))
				ln = ln->next;
			pass_qrit(tmp, ln, heap, g);
			if (ln && ln->to == g->fin)
				flag = 1;
			if (ln)
				ln = ln->next;
		}
		if (tmp != g->fin)
			tmp_pred = tmp;
	}
	return (flag);
}
