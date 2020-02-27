/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_sufficienty_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:27:45 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/27 18:27:49 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clean_way_in_list(t_way **ways, int current_way)
{
	t_way	*tmp;
	t_way	*tmp_2;

	tmp = ways[current_way];
	tmp_2 = tmp->next;
	while (tmp_2)
	{
		free(tmp);
		tmp = tmp_2;
		tmp_2 = tmp_2->next;
	}
	free(tmp);
	ways[current_way] = NULL;
}

int			way_len_calc(t_way *way)
{
	int		i;

	i = 0;
	while (way)
	{
		way = way->next;
		i++;
	}
	return (i - 1);
}

int			has_common_rooms(t_map *map, t_graph_inf *inf, int len_c)
{
	int		i;

	i = common_rooms_calc(inf);
	if (((int)map->ants + (inf->len_t + len_c - i)) %
				(inf->current_way_number + 1))
		inf->enough_n = ((int)map->ants + (inf->len_t + len_c - i))
				/ (inf->current_way_number + 1);
	else
		inf->enough_n = (((int)map->ants + (inf->len_t + len_c - i))
				/ (inf->current_way_number + 1)) - 1;
	if (inf->enough_n >= inf->enough_c)
	{
		clean_way_in_list(inf->ways, inf->current_way_number);
		return (1);
	}
	inf->len_t += len_c - i;
	inf->enough_c = inf->enough_n;
	return (0);
}

int			no_common_rooms(t_map *map, t_graph_inf *inf, int len_c)
{
	if (((int)map->ants + (inf->len_t + len_c)) % (inf->current_way_number + 1))
		inf->enough_n = ((int)map->ants + (inf->len_t + len_c))
				/ (inf->current_way_number + 1);
	else
		inf->enough_n = (((int)map->ants + (inf->len_t + len_c))
				/ (inf->current_way_number + 1)) - 1;
	if (inf->enough_n >= inf->enough_c)
	{
		clean_way_in_list(inf->ways, inf->current_way_number);
		return (1);
	}
	inf->len_t += len_c;
	inf->enough_c = inf->enough_n;
	return (0);
}

int			sufficienty_c(t_graph_inf *inf, t_map *map)
{
	int		len_c;

	len_c = way_len_calc(inf->ways[inf->current_way_number]);
	if (!inf->enough_c)
	{
		if (map->ants == 1)
			return (1);
		if ((map->ants + len_c) % (inf->current_way_number + 1))
			inf->enough_c = ((int)map->ants + len_c) /
					(inf->current_way_number + 1);
		else
			inf->enough_c = (((int)map->ants + len_c) /
					(inf->current_way_number + 1)) - 1;
		inf->len_t += len_c;
		return (0);
	}
	else
	{
		if (!inf->common_rooms[0])
			return (no_common_rooms(map, inf, len_c));
		else
			return (has_common_rooms(map, inf, len_c));
	}
}
