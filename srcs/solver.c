/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:40:28 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/27 19:40:31 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_path			*add_one_way(int i, t_graph_inf *inf, t_map *map)
{
	t_path		*tmp;
	t_way		*way_in_list;
	int			room;

	room = 0;
	tmp = (t_path *)malloc(sizeof(t_path));
	tmp->next = NULL;
	tmp->len = inf->ways[i]->way_len;
	tmp->path = (t_room **)malloc(sizeof(t_room *) *
			(inf->ways[i]->way_len + 1));
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
		tmp = NULL;
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
	inf->ways = NULL;
	inf->common_rooms = NULL;
}

void			solver(t_map *map)
{
	t_graph_inf	inf;

	initialization(map, &inf);
	algo(map, &inf);
	if (inf.ways[0])
		put_ways_to_map(&inf, map);
	free_inf_content(&inf);
}
