/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:23:42 by limry             #+#    #+#             */
/*   Updated: 2020/01/29 16:30:26 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include "deque.c"

//void	path_is_founded(t_deq *deq, t_paths *paths);
//{
//	deq->
//}
//
//void	dfs(t_map *g, t_deq *deq, int64_t levs[g->num_nodes], t_paths *paths)
//{
//	t_room	*tmp;
//	t_link	*link;
//
//	while(-1 != deq->rear)
//	{
//		tmp = pop_rear(g, deq);
//		link = tmp->linked_to;
//		while (link)
//		{
//			if (levs[tmp->hash_id] + 1 ==  levs[link->to->hash_id] && link->to->path_id != 0)
//			{
//				if (link->to == g->fin)
//					path_is_founded(deq, paths);
//				else if (!link->to->num_linked_to)
//					link->to->path_id = 0;
//				else
//				{
//					push_back(g, tmp, deq);
//					dfs (g, deq, levs, paths);
//				}
//			}
//			link = link->next;
//		}
//	}
//}
//
//int		bfs(t_map *g, t_room *start, t_deq *deq, int64_t levs[g->num_nodes])
//{
//	int64_t lev;
//	t_room	*tmp;
//	t_link	*link;
//
//	lev = 0;
//	init_dequeue(g, deq);
//	push_back(g, start, deq);
//	levs[start->hash_id] = lev;
//	g->fin->level = INT64_MAX - 2;
//	while(deq->begin != deq->rear)
//	{
//		tmp = pop_front(g, deq);
//		lev = levs[tmp->hash_id] + 1;
//		link = tmp->linked_to;
//		while (link)
//		{
//			while (link && link->to->path_id)
//				link = link->next;
//			if (link && levs[link->to->hash_id] == -1)
//			{
//				levs[link->to->hash_id]= lev;
//				push_back(g, link->to, deq);
//			}
//			else if (link && link->to == g->fin)
//				g->no_path_exists = FALSE;
//		}
//	}
//}
//
//void			dinic(t_map *g, int ants, t_deq *deq, t_paths *paths)
//{
//	int64_t		lev[g->num_nodes];
//	uint64_t	n;
//
//	n = 0;
//	while (n < g->num_nodes)
//		lev[n++] = -1;
//	g->no_path_exists = FALSE;
//	while (!g->no_path_exists)
//	{
//		g->no_path_exists = TRUE;
//		bfs(g, g->start, deq, lev);
//		if (!g->no_path_exists)
//			break ;
//		else
//		{
//			init_dequeue(g, deq);
//			push_back(g, g->start, deq);
//			dfs(g, deq, lev, paths);
//		}
//	}
//}
//
//void		prep_for_solver(t_map *g, int ants)
//{
//	t_deq	deq;
//	t_room	*q[g->num_nodes];
//	t_paths *paths;
//
//	deq.deq = q;
//	init_paths(g, paths);
//	init_dequeue(g, &deq);
//	dinic(g, ants, &deq, paths);
//}

void		print_list(t_room *source)
{
	t_room	*tmp_r;
	t_link	*tmp_l;
	int		indicator;

	tmp_r = source;
	indicator = 0;
	ft_putstr("\n\n");
	while (!indicator || tmp_r != source)
	{
		ft_putstr("room ~~~[");
		ft_putstr(tmp_r->name);
		ft_putstr("]~~~ linked to:  ");
		tmp_l = tmp_r->linked_to;
		while (tmp_l)
		{
			ft_putstr(tmp_l->to->name);
			ft_putstr("  ");
			tmp_l = tmp_l->next;
		}
		ft_putchar('\n');
		tmp_r = tmp_r->next;
		indicator++;
	}
}

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

t_room		***memory_for_ways(t_map *map, t_room ***ways)
{
	int		i;
	int		e;
	int		rooms;

	rooms = rooms_calc(map->start);
	i = 0;
	ways = (t_room ***)malloc(sizeof(t_room**) * (rooms + 1));
	ways[rooms] = NULL;
	while (i < rooms)
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

t_link		**memory_for_bad_links(t_room *source, t_link **links_to_gray_dot)
{
	int		links;
	int		i;

	links = links_calc(source);
	i = 0;
	links_to_gray_dot = malloc(sizeof(t_link) * (links + 1));
	links_to_gray_dot[links] = NULL;
	while (i < links)
		links_to_gray_dot[i++] = NULL;
	return (links_to_gray_dot);
}

void		print_ways(t_graph_inf	*inf)
{
	int 	i;

	inf->current_way_number = 0;
	ft_putchar('\n');
	ft_putstr("So... we found:\n");
	while (inf->ways[inf->current_way_number][0])
	{
		i = 0;
		while (inf->ways[inf->current_way_number][i])
		{
			ft_putstr((inf->ways[inf->current_way_number][i++])->name);
			ft_putstr("  ");
		}
		ft_putchar('\n');
		inf->current_way_number++;
	}
}

void		free_ways(t_room ***ways, t_room *source)
{
	int		i;
	int		rooms;

	i = 0;
	rooms = rooms_calc(source);
	while (i < rooms)
		free(ways[i++]);
	free(ways);
}

void		solver(t_map *map)
{
	t_graph_inf	inf;

	make_color_white_again(map->room_start);
	put_zero_to_flows(map->room_start);
//	print_list(map->room_start);
	inf.ways = memory_for_ways(map, inf.ways);
	inf.mirror_links = memory_for_mirror_links(map->room_start, inf.mirror_links);
	inf.links_to_gray_dot = memory_for_bad_links(map->room_start, inf.links_to_gray_dot);
	algo(map, &inf);
	print_ways(&inf);


	free_ways(inf.ways, map->start);
	free(inf.mirror_links);
	free(inf.links_to_gray_dot);
}


