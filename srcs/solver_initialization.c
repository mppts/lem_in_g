/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:38:12 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/27 19:38:14 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			find_num_of_ways(t_map *map)
{
	int		links_start;
	int		links_end;
	t_link	*tmp;

	links_end = 0;
	links_start = 0;
	tmp = map->start->linked_to;
	while (tmp)
	{
		links_start++;
		tmp = tmp->next;
	}
	tmp = map->fin->linked_to;
	while (tmp)
	{
		links_end++;
		tmp = tmp->next;
	}
	if (links_end > links_start)
		return (links_end);
	return (links_start);
}

void		put_zero_to_flows(t_room *source)
{
	t_room	*tmp_r;
	t_link	*tmp_link;

	tmp_link = source->linked_to;
	source->way_number = -1;
	source->level = 0;
	while (tmp_link)
	{
		tmp_link->flow = 0;
		tmp_link = tmp_link->next;
	}
	tmp_r = source->next;
	while (tmp_r != source)
	{
		tmp_r->level = 0;
		tmp_r->way_number = -1;
		tmp_link = tmp_r->linked_to;
		while (tmp_link)
		{
			tmp_link->flow = 0;
			tmp_link = tmp_link->next;
		}
		tmp_r = tmp_r->next;
	}
}

void		put_null_to_precessor(t_map *map)
{
	t_room	*tmp;
	int		indicator;

	tmp = map->start;
	indicator = 0;
	while (!indicator || tmp != map->start)
	{
		tmp->level_rev = 0;
		tmp->c_in_way = 0;
		tmp->room_from_we_came = NULL;
		tmp = tmp->next;
		indicator++;
	}
}

void		initialization(t_map *map, t_graph_inf *inf)
{
	int		i;

	i = 0;
	map->cycle_found = 0;
	inf->helper = -5;
	inf->max_ways = find_num_of_ways(map);
	inf->ways = malloc(sizeof(t_way *) * (inf->max_ways + 1));
	inf->current_way_number = 0;
	inf->len_t = 0;
	inf->enough_c = 0;
	inf->enough_n = 0;
	inf->common_rooms = malloc(sizeof(t_room *) * (map->num_nodes + 1));
	while (i <= inf->max_ways)
		inf->ways[i++] = NULL;
	i = 0;
	while (i <= map->num_nodes)
		inf->common_rooms[i++] = NULL;
	put_zero_to_flows(map->room_start);
	put_null_to_precessor(map);
	map->path = NULL;
}
