/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_algorithm_ceaning.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:47:57 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/26 11:16:15 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delite_mirror_links(t_graph_inf *inf)
{
	int		i;
	t_link	*tmp;

	i = 0;
	while (i < inf->two_flows)
	{
		tmp = inf->mirror_links[i];
		tmp->to->num_linked_to--;
		if (!tmp->prev)
			tmp->mirror->to->linked_to = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		free(tmp);
		inf->mirror_links[i] = NULL;
		i++;
	}
}

void		clean_ways(t_room ***ways)
{
	int		y;
	int		x;

	y = 0;
	while (ways[y])
	{
		x = 0;
		while (ways[y][x])
			ways[y][x++] = NULL;
		y++;
	}
}

void		clean_levels_and_flows(t_room *source)
{
	t_room	*tmp;
	t_link	*tmp_l;

	tmp = source->next;
	source->level = 0;
	tmp_l = source->linked_to;
	while (tmp_l)
	{
		tmp_l->flow = 0;
		tmp_l = tmp_l->next;
	}
	while (tmp != source)
	{
		tmp->level = 0;
		tmp_l = tmp->linked_to;
		while (tmp_l)
		{
			tmp_l->flow = 0;
			tmp_l = tmp_l->next;
		}
		tmp = tmp->next;
	}
}

void		time_to_do_some_cleaning(t_map *map, t_graph_inf *inf)
{
	if (inf->mirror_links[0])
		delite_mirror_links(inf);
	restore_meta_graph_info(map->start->next);
	clean_ways(inf->ways); // set right bounds
	clean_levels_and_flows(map->start);
	inf->are_enough_ways_current = 0;
	inf->are_enough_ways_new = 0;
	inf->total_ways_len = 0;
}
