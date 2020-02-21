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

//void		make_color_white_again(t_room *source)
//{
//	t_room	*tmp;
//
//	tmp = source->next;
//	while (tmp != source)
//	{
//		tmp->color = WHITE;
//		tmp = tmp->next;
//	}
//	tmp->color = WHITE;
//}
//
//void		put_zero_to_flows(t_room *source)
//{
//	t_room	*tmp_r;
//	t_link	*tmp_link;
//
//	tmp_link = source->linked_to;
//	while  (tmp_link)
//	{
//		tmp_link->flow = 0;
//		tmp_link = tmp_link->next;
//	}
//	tmp_r = source->next;
//	while (tmp_r != source)
//	{
//		tmp_link = tmp_r->linked_to;
//		while  (tmp_link)
//		{
//			tmp_link->flow = 0;
//			tmp_link = tmp_link->next;
//		}
//		tmp_r = tmp_r->next;
//	}
//}
//
//int				rooms_calc(t_room *source)
//{
//	t_room		*tmp_room;
//	int			rooms_calc;
//
//	if (!source)
//		return (0);
//	rooms_calc = 1;
//	tmp_room = source->next;
//	while (tmp_room != source)
//	{
//		rooms_calc++;
//		tmp_room = tmp_room->next;
//	}
//	return (rooms_calc);
//}
//
//int				links_calc(t_room *source)
//{
//	t_link		*tmp_link;
//	t_room		*tmp_room;
//	int			link_calc;
//	int			i;
//
//	link_calc = 0;
//	i = 0;
//	tmp_room = source->next;
//	while (tmp_room != source || !i)
//	{
//		tmp_link = tmp_room->linked_to;
//		while (tmp_link)
//		{
//			link_calc++;
//			tmp_link = tmp_link->next;
//		}
//		tmp_room = tmp_room->next;
//		i++;
//	}
//	return (link_calc);
//}
//
//int			find_num_of_ways(t_map *map)
//{
//	int		links_start;
//	int		links_end;
//	t_link	*tmp;
//
//	links_end = 0;
//	links_start = 0;
//	tmp = map->start->linked_to;
//	while (tmp)
//	{
//		links_start++;
//		tmp = tmp->next;
//	}
//	tmp = map->fin->linked_to;
//	while (tmp)
//	{
//		links_end++;
//		tmp = tmp->next;
//	}
//	if (links_end > links_start)
//		return (links_end);
//	return (links_start);
//}
//
//t_room		***memory_for_ways(t_map *map, t_room ***ways)
//{
//	int		i;
//	int		e;
//	int		rooms;
//	int		max_ways;
//
//	rooms = rooms_calc(map->start);
//	i = 0;
//	max_ways = find_num_of_ways(map);
//	ways = (t_room ***)malloc(sizeof(t_room**) * (max_ways + 1));
//	ways[max_ways] = NULL;
//	while (i < max_ways)
//	{
//		e = 0;
//		ways[i] = (t_room **)malloc(sizeof(t_room *) * (rooms + 1));
//		while (e <= rooms)
//			ways[i][e++] = NULL;
//		i++;
//	}
//	return (ways);
//}
//
//t_link 		**memory_for_mirror_links(t_room *source, t_link **mirror_links)
//{
//	int		links;
//	int		i;
//
//	links = links_calc(source);
//	i = 0;
//	mirror_links = malloc(sizeof(t_link) * (links + 1));
//	mirror_links[links] = NULL;
//	while (i < links)
//		mirror_links[i++] = NULL;
//	return (mirror_links);
//}
//
//void		free_ways(t_graph_inf *inf)
//{
//	int		i;
//
//	if (inf->ways[inf->current_way_number])
//		i = inf->current_way_number + 1;
//	else
//		i = inf->current_way_number;
//	while (inf->ways[i])
//		free(inf->ways[i++]);
//	free(inf->ways);
//}
//
//int			way_len_calc(t_room **way)
//{
//	int		i;
//
//	i = 0;
//	while (way[i])
//		i++;
//	return (i);
//}
//
//void		put_ways_to_list(t_graph_inf *inf, t_map *map)
//{
//	int		i;
//	t_path	*tmp;
//	t_path	*current;
//	t_path	*head;
//
//	i = 0;
//	head = malloc(sizeof(t_path));
//	head->len = way_len_calc((inf->ways[i]));
//	head->path = (inf->ways[i++]);
//	head->next = NULL;
//	current = head;
//	while (inf->ways[i] && inf->ways[i][0])
//	{
//		tmp = malloc(sizeof(t_path));
//		tmp->len = way_len_calc((inf->ways[i]));
//		tmp->path = (inf->ways[i++]);
//		tmp->next = NULL;
//		current->next = tmp;
//		current = current->next;
//	}
//	map->path = head;
//}
//
//void		print_ways(t_graph_inf	*inf)
//{
//	int 	i;
//
//	inf->current_way_number = 0;
//	ft_putchar('\n');
//	ft_putstr("So... we found:\n");
//	while (inf->ways[inf->current_way_number] && inf->ways[inf->current_way_number][0])
//	{
//		i = 0;
//		while (inf->ways[inf->current_way_number][i])
//		{
//			ft_putstr((inf->ways[inf->current_way_number][i++])->name);
//			ft_putstr("  ");
//		}
//		ft_putchar('\n');
//		inf->current_way_number++;
//	}
//}
//
//t_graph_inf	*create_inf(t_map *map)
//{
//	t_graph_inf	*inf;
//
//	inf = (t_graph_inf *)malloc(sizeof(t_graph_inf));
//	inf->ways = memory_for_ways(map, inf->ways);
//	inf->mirror_links = memory_for_mirror_links(map->room_start, inf->mirror_links);
//	inf->total_ways_len = 0;
//	inf->are_enough_ways_current = 0;
//	inf->are_enough_ways_new = 0;
//	inf->next = NULL;
//	return (inf);
//}
//
//t_graph_inf	*find_best_solution(t_map *map)
//{
//	t_graph_inf *tmp;
//	t_graph_inf *best;
//
//	best = map->inf;
//	tmp = map->inf->next;
//	while (tmp)
//	{
//		if (best->are_enough_ways_current > tmp->are_enough_ways_current)
//			best = tmp;
//		tmp = tmp->next;
//	}
//	return (best);
//}
//
//int			sorted(t_path *path)
//{
//	t_path	*tmp;
//
//	tmp = path;
//	while (path)
//	{
//		tmp = path;
//		path = path->next;
//		if (path && tmp->len > path->len)
//			return (0);
//	}
//	return (1);
//}
//
//void		sort_list(t_path *path)
//{
//	t_path	*tmp;
//	int 	swap;
//	t_room 	**swap_ways;
//
//	while (!sorted(path))
//	{
//		tmp = path;
//		while (tmp)
//		{
//			if (tmp->next && tmp->len > tmp->next->len)
//			{
//				swap = tmp->len;
//				tmp->len = tmp->next->len;
//				tmp->next->len = swap;
//				swap_ways = tmp->path;
//				tmp->path = tmp->next->path;
//				tmp->next->path = swap_ways;
//			}
//			tmp = tmp->next;
//		}
//	}
//}
//
//void		check_list(t_map *map)
//{
//	t_path	*tmp;
//	double	index_current;
//	double	index_new;
//	int 	i;
//	int 	current_way_len;
//	t_path	*tmp_2;
//
//
//	i = 1;
//	sort_list(map->path);
//	tmp = map->path;
//	current_way_len = tmp->len;
//	index_current = ((double)map->ants + (double)current_way_len) / i;
//	index_new = 0;
//	while (tmp->next)
//	{
//		i++;
//		index_new = ((double)map->ants + (double)current_way_len + (double)tmp->next->len) / i;
//		if (index_new > index_current)
//		{
//			tmp_2 = tmp->next;
//			tmp->next = NULL;
//			while (tmp_2)
//			{
//				free(tmp_2->path);
//				tmp = tmp_2;
//				tmp_2 = tmp_2->next;
//				free(tmp);
//			}
//			break ;
//		}
//		current_way_len += tmp->next->len;
//		index_current = index_new;
//		tmp = tmp->next;
//	}
//
//}
//
//void		solver(t_map *map)
//{
//	t_graph_inf	*inf;
//
//	make_color_white_again(map->room_start);
//	put_zero_to_flows(map->room_start);
//	inf = create_inf(map);
//	map->inf = inf;
//	algo(map, inf);
//	inf = find_best_solution(map);
//	put_ways_to_list(inf, map);
//	check_list(map);
//	print_ways(inf);
//
////	free_ways(inf);
////	free(inf->mirror_links);
//}

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
	while  (tmp_link)
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
		while  (tmp_link)
		{
			tmp_link->flow = 0;
			tmp_link = tmp_link->next;
		}
		tmp_r = tmp_r->next;
	}
}

//void			memory_for_rooms_from_we_came(t_map *map)
//{
//	t_room		*tmp;
//
//	map->start->room_from_we_came = malloc(sizeof(t_room) * map->num_nodes);
//	tmp =  map->start->next;
//	tmp->unvisited_room = 0;
//	while (tmp != map->start)
//	{
//		tmp = malloc(sizeof(t_room) * map->num_nodes);
//		tmp->unvisited_room = 0;
//		tmp = tmp->next;
//	}
//}

void	 		put_null_to_precessor(t_map *map)
{
	t_room		*tmp;
	int			indicator;

	tmp = map->start;
	indicator = 0;
	while (!indicator || tmp != map->start)
	{
		tmp->room_from_we_came = NULL;
		tmp = tmp->next;
		indicator++;
	}
}

void			initialization(t_map *map, t_graph_inf	*inf)
{
	int i;

	i = 0;
	inf->max_ways = find_num_of_ways(map);
	inf->ways = malloc(sizeof(t_way *) * (inf->max_ways + 1));
	inf->current_way_number = 0;
	inf->current_pos_in_way = 0;
	inf->position_in_way = 0;
	inf->total_ways_len = 0;
	inf->are_enough_ways_current = 0;
	inf->are_enough_ways_new = 0;
	inf->two_flows = 0;
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

t_path			*add_one_way(int i, t_graph_inf *inf, t_map *map)
{
	t_path		*tmp;
	t_way 		*way_in_list;
	int			room;

	room = 0;
	tmp = (t_path *)malloc(sizeof(t_path));
	tmp->next = NULL;
	tmp->len = inf->ways[i]->way_len;
	tmp->path = (t_room **)malloc(sizeof(t_room *) * (inf->ways[i]->way_len));
	tmp->path[inf->ways[i]->way_len] = NULL;
	tmp->ants = map->ants;
	way_in_list = inf->ways[i];
	while (room < inf->ways[i]->way_len)
	{
		tmp->path[room++] = way_in_list->room;
		way_in_list = way_in_list->next;
	}
	return (tmp);
}

void			put_ways_to_map(t_graph_inf *inf, t_map *map)
{
	int			i;
	t_path		*path;

	i = 0;
	map->path = add_one_way(i, inf, map);
	i++;
	path = map->path;
	while (inf->ways[i])
	{
		path->next = add_one_way(i, inf, map);
		path = path->next;
		i++;
	}
}

void			free_way(t_way *way)
{
	t_way		*tmp;

	while (way)
	{
		tmp = way;
		way = way->next;
		free(tmp);
	}
}

void			free_inf_content(t_graph_inf *inf)
{
	int			i;

	i = 0;
	while (inf->ways[i])
		free_way(inf->ways[i++]);
	free(inf->ways);
	free(inf->common_rooms);
}

void			print_ways_len(t_map *map)
{
	t_path		*path;
	int 		i;

	i = 0;
	path = map->path;
	while (path)
	{
		ft_putnbr(path->len);
		ft_putstr("  ");
		path = path->next;
	}
	ft_putchar('\n');
}

void			solver(t_map *map)
{
	t_graph_inf	inf;

	initialization(map, &inf);
	algo(map, &inf);
	if (inf.ways[0])
		put_ways_to_map(&inf, map);

//	t_path *tmp = map->path;
//	int i = 0;
//	while (i < 8)
//	{
//		tmp = tmp->next;
//		i++;
//	}
//	tmp->next = NULL;



//	print_ways_len(map);
//	free_inf_content(&inf);
}