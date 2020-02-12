/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:23:42 by limry             #+#    #+#             */
/*   Updated: 2020/02/12 14:44:27 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include "deque.c"

void		make_color_white_again(t_room *source)
{
	t_room	*tmp;

	tmp = source->next;
	while (tmp != source)
	{
		tmp->color = WHITE;
		tmp = tmp->next;
	}
	tmp->color = WHITE;
}

void		put_zero_to_flows(t_room *source)
{
	t_room	*tmp_r;
	t_link	*tmp_link;

	tmp_link = source->linked_to;
	while  (tmp_link)
	{
		tmp_link->flow = 0;
		tmp_link = tmp_link->next;
	}
	tmp_r = source->next;
	while (tmp_r != source)
	{
		tmp_link = tmp_r->linked_to;
		while  (tmp_link)
		{
			tmp_link->flow = 0;
			tmp_link = tmp_link->next;
		}
		tmp_r = tmp_r->next;
	}
}

int				rooms_calc(t_room *source)
{
	t_room		*tmp_room;
	int			rooms_calc;

	if (!source)
		return (0);
	rooms_calc = 1;
	tmp_room = source->next;
	while (tmp_room != source)
	{
		rooms_calc++;
		tmp_room = tmp_room->next;
	}
	return (rooms_calc);
}

int				links_calc(t_room *source)
{
	t_link		*tmp_link;
	t_room		*tmp_room;
	int			link_calc;
	int			i;

	link_calc = 0;
	i = 0;
	tmp_room = source->next;
	while (tmp_room != source || !i)
	{
		tmp_link = tmp_room->linked_to;
		while (tmp_link)
		{
			link_calc++;
			tmp_link = tmp_link->next;
		}
		tmp_room = tmp_room->next;
		i++;
	}
	return (link_calc);
}

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

t_room		***memory_for_ways(t_map *map, t_room ***ways)
{
	int		i;
	int		e;
	int		rooms;
	int		max_ways;

	rooms = rooms_calc(map->start);
	i = 0;
	max_ways = find_num_of_ways(map);
	ways = (t_room ***)malloc(sizeof(t_room**) * (max_ways + 1));
	ways[max_ways] = NULL;
	while (i < max_ways)
	{
		e = 0;
		ways[i] = (t_room **)malloc(sizeof(t_room *) * (rooms + 1));
		while (e <= rooms)
			ways[i][e++] = NULL;
		i++;
	}
	return (ways);
}

t_link 		**memory_for_mirror_links(t_room *source, t_link **mirror_links)
{
	int		links;
	int		i;

	links = links_calc(source);
	i = 0;
	mirror_links = malloc(sizeof(t_link) * (links + 1));
	mirror_links[links] = NULL;
	while (i < links)
		mirror_links[i++] = NULL;
	return (mirror_links);
}

void		free_ways(t_graph_inf *inf)
{
	int		i;

	if (inf->ways[inf->current_way_number])
		i = inf->current_way_number + 1;
	else
		i = inf->current_way_number;
	while (inf->ways[i])
		free(inf->ways[i++]);
	free(inf->ways);
}

int			way_len_calc(t_room **way)
{
	int		i;

	i = 0;
	while (way[i])
		i++;
	return (i);
}

void		put_ways_to_list(t_graph_inf *inf, t_map *map)
{
	int		i;
	t_path	*tmp;
	t_path	*current;
	t_path	*head;

	i = 0;
	head = malloc(sizeof(t_path));
	head->len = way_len_calc((inf->ways[i]));
	head->path = (inf->ways[i++]);
	head->next = NULL;
	current = head;
	while (inf->ways[i] && inf->ways[i][0])
	{
		tmp = malloc(sizeof(t_path));
		tmp->len = way_len_calc((inf->ways[i]));
		tmp->path = (inf->ways[i++]);
		tmp->next = NULL;
		current->next = tmp;
		current = current->next;
	}
	map->path = head;
}

void		solver(t_map *map)
{
	t_graph_inf	inf;

	make_color_white_again(map->room_start);
	put_zero_to_flows(map->room_start);
	inf.ways = memory_for_ways(map, inf.ways);
	inf.mirror_links = memory_for_mirror_links(map->room_start, inf.mirror_links);
	inf.total_ways_len = 0;
	inf.are_enough_ways_current = 0;
	inf.are_enough_ways_new = 0;
	algo(map, &inf);
	put_ways_to_list(&inf, map);
//	print_ways(&inf);

	free_ways(&inf);
	free(inf.mirror_links);
}


