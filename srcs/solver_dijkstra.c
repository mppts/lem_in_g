/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:50:11 by limry             #+#    #+#             */
/*   Updated: 2020/03/03 18:54:45 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include "binary_heap.h"

int64_t			get_room_delta(void *rm)
{
	t_room		*trm;

	trm = (t_room*)rm;
	return (trm->delta_out);
}

int				neg_has_exit(t_room *rm, int64_t new_delta)
{
	t_link		*ln;

	ln = rm->linked_to;
	while (ln)
	{
		if (ln->flow == 1 && ln->to->level == 0 && ln->to->delta_out > new_delta)
			return (1);
		ln = ln->next;
	}
	return (0);
}

int				neg_can_go(t_room *rm, int64_t new_delta)
{
	t_link		*ln;
	int			i;

	ln = rm->linked_to;
	i = 1;
	while (ln)
	{
		if (ln->flow == -1 && rm->level != 0 && ln->to->level != 0 && ln->to->delta_out > new_delta - i)
		{
			if (neg_has_exit(ln->to, new_delta - 1))
				return (1);
			else
			{
				i++;
				ln = ln->to->linked_to;
			}
		}
		else
			ln = ln->next;
	}
	return (0);
}

static int		pass_qrit(t_room *tmp, t_link *ln, t_bin_heap *heap, t_map *m)
{
	if (ln->to->level == 1)
	{
		if (tmp->level == 0 && ln->flow == 1 && ln->to->delta_in > tmp->pot_out - ln->to->pot_in + ln->flow + tmp->delta_out)
		{
			ln->to->pred_in = tmp;
			ln->to->delta_in = tmp->pot_out - ln->to->pot_in + ln->flow + tmp->delta_out;
			bin_heap_insert(heap, ln->to, ln->to->delta_in);
		}
		else if (tmp->level == 1 && ln->flow == -1 && ln->to->delta_out > tmp->pot_in - ln->to->pot_out + ln->flow + tmp->delta_in)
		{
			ln->to->pred_out = tmp;
			ln->to->delta_out = tmp->pot_in - ln->to->pot_out + ln->flow + tmp->delta_in;
			if (ln->to->delta_out < ln->to->delta_in)
			{
				ln->to->sim = 1;
				ln->to->delta_in = ln->to->delta_out;
				bin_heap_insert(heap, ln->to, ln->to->delta_in);
			}
			else
				bin_heap_insert(heap, ln->to, ln->to->delta_out);
		}
		else if (tmp->level == 1 && ln->flow == 1 && ln->to->delta_in > tmp->pot_out - ln->to->pot_in + ln->flow + tmp->delta_out && ln->to->pred_out)
		{
			ln->to->pred_in = tmp;
			ln->to->delta_in = tmp->pot_out - ln->to->pot_in + ln->flow + tmp->delta_out;
			ln->to->delta_out = ln->to->delta_in;
			bin_heap_insert(heap, ln->to, ln->to->delta_in);
		}
	}
	else if (ln->to->level == 0)
	{
		if (tmp->level == 0 && ln->flow == 1 && ln->to->delta_in > tmp->pot_out - ln->to->pot_in + ln->flow + tmp->delta_out)
		{
			ln->to->pred_in = tmp;
			ln->to->delta_in = tmp->pot_out - ln->to->pot_in + ln->flow + tmp->delta_out;
			ln->to->delta_out = ln->to->delta_in;
			bin_heap_insert(heap, ln->to, ln->to->delta_in);
		}
		else if (tmp->level == 1 && tmp->pred_in && tmp->pred_in->level == 1 && tmp->pred_out == NULL)
		{
			if (ln->to->delta_in > tmp->pot_in - ln->to->pot_in + ln->flow + tmp->delta_in)
			{
				ln->to->pred_in = tmp;
				ln->to->delta_in = tmp->pot_out - ln->to->pot_in + ln->flow + tmp->delta_out;
				ln->to->delta_out = ln->to->delta_in;
				bin_heap_insert(heap, ln->to, ln->to->delta_in);
			}
		}
		else if (tmp->level == 1 && tmp->pred_out)
		{
			if (ln->to->delta_in > tmp->pot_out - ln->to->pot_in + ln->flow + tmp->delta_out)
			{
				ln->to->pred_in = tmp;
				ln->to->delta_in = tmp->pot_out - ln->to->pot_in + ln->flow + tmp->delta_out;
				ln->to->delta_out = ln->to->delta_in;
				bin_heap_insert(heap, ln->to, ln->to->delta_in);
			}
		}
	}
	return (0);
}

int				bin_dijkstra(t_map *g, t_bin_heap *heap)
{
	t_room		*tmp;
	t_link		*ln;
	int			flag;

	flag = 0;
	bin_heap_insert(heap, g->start, g->start->delta_out);
	g->start->flv = 1;
	while (heap->num_nodes > 1)
	{
		tmp = (t_room*)bin_pop_root(tmp, heap);
		tmp->sign = 1;
		tmp->flv = 0;
		ln = tmp->linked_to;
		while (ln)
		{
			while (ln && (ln->flow == 0 || ln->to == g->start))
				ln = ln->next;
			ln && pass_qrit(tmp, ln, heap, g);
			if (ln && ln->to == g->fin)
				flag = 1;
			if (ln)
				ln = ln->next;
		}
	}
	return (flag);
}
