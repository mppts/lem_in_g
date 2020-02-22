/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:38:24 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/12 16:38:29 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//int			enough_ways(t_map *map, t_graph_inf *inf)
//{
//	int		current_way_len;
//
//	current_way_len = way_len_calc(inf->ways[inf->current_way_number]) - 1;
//	if (!inf->are_enough_ways_current)
//	{
//		if (map->ants == 1)
//			return (1);
//		if ((map->ants + current_way_len) % (inf->current_way_number + 1))
//			inf->are_enough_ways_current = ((int)map->ants + current_way_len) / (inf->current_way_number + 1) + 1;
//		else
//			inf->are_enough_ways_current = ((int)map->ants + current_way_len) / (inf->current_way_number + 1);
//		inf->total_ways_len += current_way_len;
//		return (0);
//	}
//	else
//	{
//		if (((int)map->ants + (inf->total_ways_len + current_way_len)) % (inf->current_way_number + 1))
//			inf->are_enough_ways_new = ((int)map->ants + (inf->total_ways_len + current_way_len)) / (inf->current_way_number + 1) + 1;
//		else
//			inf->are_enough_ways_new = ((int)map->ants + (inf->total_ways_len + current_way_len)) / (inf->current_way_number + 1);
//		if (inf->are_enough_ways_new >= inf->are_enough_ways_current)
//		{
//			inf->ways[inf->current_way_number][0] = NULL;
//			return (1);
//		}
//		inf->total_ways_len += current_way_len;
//		inf->are_enough_ways_current = inf->are_enough_ways_new;
//		return (0);
//	}
//}
//
//void		initialization_algo(t_graph_inf *inf, t_map *map)
//{
//	inf->two_flows = 0;
//	inf->current_way_number = 0;
//	inf->current_pos_in_way = 0;
//	inf->position_in_way = 1;
//	inf->ways[inf->current_way_number][0] = map->start;
//	inf->are_enough_ways_current = 0;
//	inf->total_ways_len = 0;
//}
//
//void		algo(t_map *map, t_graph_inf *inf)
//{
//	while (bfs(map->fin, map))
//	{
//		initialization_algo(inf, map);
//		while ((dfs(map->start, inf, map)))
//		{
//			map->fin->color = WHITE;
//			if (inf->mirror_links[0])
//				break ;
//			if (!inf->mirror_links[0] && enough_ways(map, inf))
//				break ;
//			inf->position_in_way = 1;
//			(inf->current_way_number)++;
//			inf->current_pos_in_way = 0;
//			if (inf->ways[inf->current_way_number])
//				inf->ways[inf->current_way_number][0] = map->start;
//		}
//		if (!inf->mirror_links[0])
//		{
//			if (inf->ways[inf->current_way_number] && inf->ways[inf->current_way_number][0] == map->start && !inf->ways[inf->current_way_number][1])
//				inf->ways[inf->current_way_number][0] = NULL;
//			break ;
//		}
//		else
//			inf = time_to_do_some_cleaning(map, inf);
//	}
//}

void		clear_levels(t_room *source)
{
	t_room	*tmp_r;

	source->level = 0;
	source->level_rev = 0;
	source->room_from_we_came = NULL;
	tmp_r = source->next;
	while (tmp_r != source)
	{
		tmp_r->level = 0;
		tmp_r->level_rev = 0;
		tmp_r->room_from_we_came = NULL;
		tmp_r = tmp_r->next;
	}
}

t_way		*add_new_way_pos(t_room	*room, t_graph_inf *inf, t_map *map)
{
	t_way	*tmp;

	tmp = (t_way *)malloc(sizeof(t_way));
	tmp->room = room;
	if (tmp->way_number == -1)
		tmp->room->way_number = inf->current_way_number;
	tmp->way_number = inf->current_way_number;
	tmp->next = NULL;
	tmp->prev_way = NULL;
	tmp->way_len = map->start->level;
	return (tmp);
}

void		add_flow(t_room *room, t_room *next_room)
{
	t_link	*link;

	if (next_room)
	{
		link = room->linked_to;
		while (link->to != next_room)
			link = link->next;
		link->flow = 1;
	}
}

void			add_to_common_rooms(t_graph_inf *inf, t_room *room)
{
	int 		i;

	i = 0;
	while (inf->common_rooms[i])
		i++;
	inf->common_rooms[i] = room;
}

void		find_way_1(t_map *map, t_room **line, t_graph_inf *inf)
{
	int		i;
	t_way	*current_vertex;

	i = 0;
	inf->ways[inf->current_way_number] = add_new_way_pos(line[i], inf, map);
	map->start->way_number = -1;
	current_vertex = inf->ways[inf->current_way_number];
	add_flow(line[i], line[i + 1]);
	i++;
	while (line[i])
	{
		if (line[i]->way_number == -1)
			line[i]->way_number = inf->current_way_number;
		else
			add_to_common_rooms(inf, line[i]);
		current_vertex->next = add_new_way_pos(line[i], inf, map);
		current_vertex = current_vertex->next;
		add_flow(line[i], line[i + 1]);
		i++;
	}
//	current_vertex->next = add_new_way_pos(line[i], inf, map);
}

//void		find_way(t_map *map, t_room	**line, int source, t_graph_inf *inf)
//{
//	t_room	*room;
//	t_way	*current_vertex;
//
//	room = line[source];
//	inf->ways[inf->current_way_number] = add_new_way_pos(room, inf, map);
//	map->start->way_number = -1;
//	current_vertex = inf->ways[inf->current_way_number];
//	add_flow(room);
//	room = room->room_from_we_came;
//	while (room != map->fin)
//	{
//		if (room->way_number == -1)
//			room->way_number = inf->current_way_number;
//		else
//			add_to_common_rooms(inf, room);
//		current_vertex->next = add_new_way_pos(room, inf, map);
//		current_vertex = current_vertex->next;
//		add_flow(room);
//		room = room->room_from_we_came;
//	}
//	current_vertex->next = add_new_way_pos(room, inf, map);
//}

void		clear_line(t_room **line)
{
	int		i;

	i = 0;
	while (line[i])
		line[i++] = NULL;
}

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
	ways[current_way] = NULL;
}

//int			crosses_calc(t_graph_inf *inf)
//{
//	int		crosses;
//	t_way	*tmp;
//
//	crosses = 0;
//	tmp = inf->ways[inf->current_way_number]->next;
//	while (tmp)
//	{
//		if (tmp->way_number != tmp->room->way_number)
//			crosses++;
//	}
//}
//
//int				sufficienty_c(t_graph_inf *inf, t_map *map)
//{
//	uint64_t	crosses;
//	uint64_t	current_len;
//	t_way		*tmp;
//
//	tmp = inf->ways[inf->current_way_number];
//	current_len = inf->total_ways_len + map->start->level;
//	if (inf->current_way_number == 0)
//	{
//		inf->total_ways_len += current_len;
//		inf->are_enough_ways_current = map->ants + inf->total_ways_len;
//	}
//	else
//	{
//		while (tmp)
//		{
//			if
//			tmp = tmp->next;
//		}
//		crosses = crosses_calc(inf);
//	}
//}

void		clear_flow(t_map *map, t_room *room_1, t_room *room_2)
{
	t_link	*tmp;

	tmp = room_1->linked_to;
	while (tmp->to != room_2)
		tmp = tmp->next;
	tmp->flow = 0;
	tmp->mirror->flow = 0;
}

t_way		*separation(t_way *tmp, t_graph_inf *inf, t_map *map)
{
	t_way	*tmp_sep;
	t_way	*way_2;

	way_2 = inf->ways[tmp->room->way_number];
	while (way_2 && way_2->room != tmp->room)
		way_2 = way_2->next;
	tmp->prev_way = tmp->next;
	tmp->next = way_2->next;
	tmp_sep = tmp->prev_way;
	clear_flow(map, tmp->room, tmp_sep->room);
	// tmp_sep->next->way_number != tmp_sep->next->room->way_number
	while (tmp_sep->room->way_number == tmp_sep->next->room->way_number)
	{
		clear_flow(map, tmp_sep->room, tmp_sep->next->room);
		tmp = tmp_sep;
		tmp_sep->room->way_number = -1;
		tmp_sep = tmp_sep->next;
		free(tmp);
	}
	way_2 = inf->ways[tmp_sep->room->way_number];
	while (way_2 && way_2->room != tmp_sep->room)
		way_2 = way_2->next;
	way_2->next = tmp_sep->next;
	return (tmp_sep->next);
}


void		separate_cross_ways(t_graph_inf *inf, t_map *map)
{
	t_way	*tmp;
	int		common_room;

	common_room = 0;
	tmp = inf->ways[inf->current_way_number];
	while (tmp->room != map->fin)
	{
		if (tmp->room != map->start && tmp->way_number != tmp->room->way_number)
			tmp = separation(tmp, inf, map);
		else
			tmp = tmp->next;
	}
	while (inf->common_rooms[common_room])
		inf->common_rooms[common_room] = NULL;
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

int			common_rooms_calc(t_graph_inf *inf)
{
	int		i;
	int		total_result;
	int		current_result;

	i = 1;
	total_result = 0;
	current_result = 1;
	while (inf->common_rooms[i])
	{
		if (inf->common_rooms[i]->way_number != inf->common_rooms[i - 1]->way_number)
		{
			total_result += ((current_result - 1) * 2);
			current_result = 1;
			i++;
		}
		else
		{
			current_result++;
			i++;
		}
	}
	if (!inf->common_rooms[i])
		total_result += ((current_result - 1) * 2);
	return (total_result);
}

int			sufficienty_c(t_graph_inf *inf, t_map *map)
{
	int		current_way_len;
	int 	i;

	current_way_len = inf->ways[inf->current_way_number]->way_len;
	if (!inf->are_enough_ways_current)
	{
		if (map->ants == 1)
			return (1);
		if ((map->ants + current_way_len) % (inf->current_way_number + 1))
			inf->are_enough_ways_current = ((int)map->ants + current_way_len) / (inf->current_way_number + 1) + 1;
		else
			inf->are_enough_ways_current = ((int)map->ants + current_way_len) / (inf->current_way_number + 1);
		inf->total_ways_len += current_way_len;
		return (0);
	}
	else
	{
		if (!inf->common_rooms[0])
		{
//			if (((int)map->ants + (inf->total_ways_len + current_way_len)) % (inf->current_way_number + 1))
//				inf->are_enough_ways_new = ((int)map->ants + (inf->total_ways_len + current_way_len)) / (inf->current_way_number + 1);
//			else
				inf->are_enough_ways_new = ((int)map->ants + (inf->total_ways_len + current_way_len)) / (inf->current_way_number + 1);
			if (inf->are_enough_ways_new >= inf->are_enough_ways_current)
			{
				clean_way_in_list(inf->ways, inf->current_way_number);
				return (1);
			}
			inf->total_ways_len += current_way_len;
			inf->are_enough_ways_current = inf->are_enough_ways_new;
			return (0);
		}
		else
		{
			i = common_rooms_calc(inf);
//			if (((int)map->ants + (inf->total_ways_len + current_way_len - i)) % (inf->current_way_number + 1))
				inf->are_enough_ways_new = ((int)map->ants + (inf->total_ways_len + current_way_len - i)) / (inf->current_way_number + 1);
//			else
//				inf->are_enough_ways_new = ((int)map->ants + (inf->total_ways_len + current_way_len - i)) / (inf->current_way_number + 1);
			if (inf->are_enough_ways_new >= inf->are_enough_ways_current)
			{
				clean_way_in_list(inf->ways, inf->current_way_number);
				return (1);
			}
			inf->total_ways_len += current_way_len - i;
			inf->are_enough_ways_current = inf->are_enough_ways_new;
			return (0);
		}
	}
}

void			print_ways_len_2(t_graph_inf *inf)
{
	int 		i;

	i = 0;
	while (inf->ways[i])
	{
		ft_putnbr(inf->ways[i++]->way_len);
		ft_putstr("  ");
	}
	ft_putchar('\n');
}

void		nulls_to_ways(t_room **way_1, t_room **way_2, int len)
{
	int		i;

	i = 0;
	while (i <= len)
	{
		way_1[i] = NULL;
		way_2[i++] = NULL;
	}
}

void		algo(t_map *map, t_graph_inf *inf)
{
	t_room		**way_1;
	t_room		**way_2;
	int			indicator;

	way_1 = (t_room **)malloc(sizeof(t_room) * (map->num_nodes + 1));
	way_2 = (t_room **)malloc(sizeof(t_room) * (map->num_nodes + 1));
	nulls_to_ways(way_1, way_2, map->num_nodes);
	indicator = 0;
	while (!indicator && (find_best_current_way(map, way_1, way_2, inf)))
	{
		find_way_1(map, way_1, inf);
//		if (sufficienty_c(inf, map))
//			indicator = 1;
		if (!indicator && inf->common_rooms[0])
			separate_cross_ways(inf, map);
		clear_levels(map->start);
		clear_line(way_1);
		find_ways_len(inf);
		sort_ways(inf);
		give_right_numbers_to_ways(inf);
		map->start->way_number = -1;
		map->fin->way_number = -1;
		if (!indicator)
			inf->current_way_number++;
		print_ways_len_2(inf);
	}
	free(way_1);
	free(way_2);
}
