/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_auxiliary_works_algo_2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:20:58 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/27 18:21:01 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_sorted(t_way **ways)
{
	int		i;
	int		current_len;

	i = 0;
	current_len = ways[i]->way_len;
	i++;
	while (ways[i])
	{
		if (ways[i]->way_len < current_len)
			return (0);
		current_len = ways[i]->way_len;
		i++;
	}
	return (1);
}

void		give_right_numbers_to_ways(t_graph_inf *inf)
{
	int		i;
	t_way	*tmp;

	i = 0;
	while (inf->ways[i])
	{
		tmp = inf->ways[i];
		while (tmp)
		{
			tmp->way_number = i;
			tmp->room->way_number = i;
			tmp = tmp->next;
		}
		i++;
	}
}

void		clear_common_rooms(t_graph_inf *inf)
{
	int		i;

	i = 1;
	inf->common_rooms[0] = NULL;
	while (inf->common_rooms[i])
		inf->common_rooms[i++] = NULL;
}

void		sort_ways(t_graph_inf *inf)
{
	t_way	*tmp;
	int		i;

	while (!is_sorted(inf->ways))
	{
		i = 0;
		while (inf->ways[i + 1])
		{
			if (inf->ways[i + 1]->way_len < inf->ways[i]->way_len)
			{
				tmp = inf->ways[i];
				inf->ways[i] = inf->ways[i + 1];
				inf->ways[i + 1] = tmp;
			}
			i++;
		}
	}
}
