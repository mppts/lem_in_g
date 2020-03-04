/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_works_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:14:45 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/27 18:14:50 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clear_levels(t_room *source)
{
	t_room	*tmp_r;

	source->level = 0;
	source->level_rev = 0;
	source->c_in_way = 0;
	source->room_from_we_came = NULL;
	tmp_r = source->next;
	while (tmp_r != source)
	{
		tmp_r->c_in_way = 0;
		tmp_r->level = 0;
		tmp_r->level_rev = 0;
		tmp_r->room_from_we_came = NULL;
		tmp_r = tmp_r->next;
	}
}

void		clear_line(t_room **line)
{
	int		i;

	i = 0;
	while (line[i])
		line[i++] = NULL;
}

int			find_len_in_list(t_way *way)
{
	int		i;

	i = 0;
	while (way)
	{
		way = way->next;
		i++;
	}
	return (i);
}

void		find_ways_len(t_graph_inf *inf)
{
	int		i;
	t_way	*tmp;
	int		len;

	i = 0;
	while (inf->ways[i])
	{
		len = find_len_in_list(inf->ways[i]);
		tmp = inf->ways[i];
		while (tmp)
		{
			tmp->way_len = len;
			tmp = tmp->next;
		}
		i++;
	}
}

void		auxiliary_works(t_map *map, t_graph_inf *inf, t_room **way_1)
{
	clear_levels(map->start);
	clear_line(way_1);
	find_ways_len(inf);
	sort_ways(inf);
	give_right_numbers_to_ways(inf);
	map->start->way_number = -1;
	map->fin->way_number = -1;
	clear_common_rooms(inf);
}
