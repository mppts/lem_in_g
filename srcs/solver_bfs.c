/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:43:01 by dorphan           #+#    #+#             */
/*   Updated: 2020/03/03 17:38:29 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*bfs_potential(t_room *start, t_room *final, t_deq *deq)
{
	t_link		*ln;
	t_room		*rm;
	t_room		*find_source;

	find_source = NULL;
	deq_push_back(start, deq);
	start->delta_out = 0;
	start->delta_in = 0;
	start->sign = 1;
	while (deq->begin <= deq->rear)
	{
		rm = (t_room*)deq_pop_front(deq);
		ln = rm->linked_to;
		while (ln)
		{
			if (ln && ln->to->sign == 0 && ln->to != rm && ln->flow == 1)
			{
				if (!find_source && (ln->to == final))
					find_source = ln->to;
				if (ln->to != final)
				{
					deq_push_back(ln->to, deq);
					ln->to->sign = 1;
				}
				ln->to->pot_out = rm->pot_out + ln->flow;
				ln->to->pot_in = rm->pot_out + ln->flow;
			}
			if (ln)
				ln = ln->next;
		}
	}
	return (find_source);
}
