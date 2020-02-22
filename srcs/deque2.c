/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:50:28 by limry             #+#    #+#             */
/*   Updated: 2020/02/20 21:05:12 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		deq_clear_data(t_deq *deq, uint64_t num_elems, size_t size_of_elem)
{
	ft_bzero(deq->deq, num_elems * size_of_elem);
	deq->rear = -1;
	deq->begin = 0;
	deq->num_elems = num_elems;
	deq->size_of_elem = size_of_elem;
}

void		*deq_get_rear(t_deq *sdeq)
{
	if (sdeq->rear > - 1)
		return (sdeq->deq[(sdeq->rear)]);
	else
		return (NULL);
}