/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_main2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:57:27 by limry             #+#    #+#             */
/*   Updated: 2020/02/28 16:58:41 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				count_ants_for_paths(t_map *map)
{
	t_path			*tmp;
	t_path			*head;
	int64_t			to_div;
	int64_t			spreaded;
	int64_t			iter;

	head = map->path;
	spreaded = 0;
	while (head)
	{
		to_div = map->ants - spreaded;
		iter = 0;
		tmp = head->next;
		while (tmp)
		{
			to_div -= (head->len - tmp->len);
			iter++;
			tmp = tmp->next;
		}
		head->ants = to_div > 0 ? to_div / (iter + 1) : 0;
		head->ants = head->ants > (map->ants - spreaded) ?
		map->ants - spreaded : head->ants;
		spreaded += head->ants;
		head = head->next;
	}
}

void				prep_paths(t_path *p, int pos)
{
	t_path			*tmp;
	int				i;

	tmp = p;
	i = 0;
	while (tmp)
	{
		tmp->path = pos ? tmp->path + 1 : tmp->path - 1;
		tmp->len = pos ? tmp->len - 1 : tmp->len + 1;
		tmp->id = i++;
		tmp = tmp->next;
	}
}
