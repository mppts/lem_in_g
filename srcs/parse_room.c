/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:14:21 by limry             #+#    #+#             */
/*   Updated: 2020/02/04 22:00:19 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			link_rooms(t_map *map, t_room *new)
{
	if (map->num_nodes == 0)
	{
		map->room_start = new;
		map->room_end = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		map->room_end->next = new;
		new->prev = map->room_end;
		new->next = map->room_start;
		map->room_start->prev = map->room_end;
		map->room_end = new;
	}
}

static void		set_start_and_fin(t_room *new, t_map *map, t_flag *flag)
{
	if (flag->flag_start == 1)
	{
		if (!map->start)
			map->start = new;
		else
			man_err_map("Error: too many entries\n", NULL, NULL, map);
	}
	if (flag->flag_end == 1)
	{
		if (!map->fin)
			map->fin = new;
		else
			man_err_map("Error: too many exits\n", NULL, NULL, map);
	}
	flag->flag_start = 0;
	flag->flag_end = 0;
}

static int		no_room_with_this_name(t_map *map)
{
	t_room		*tmp;
	uint64_t	i;

	i = map->num_nodes;
	tmp = NULL;
	if (map->room_start)
		tmp = map->room_start;
	while (tmp && i--)
	{
		if (!ft_strcmp(tmp->name, map->splt[0]))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_room			*new_room(char **splt, t_flag *flag, t_map *map)
{
	t_room		*new;
	int64_t		coord_x;
	int64_t		coord_y;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		man_err_map("Error: cant allocate room\n", NULL, NULL, map);
	new->name = ft_strdup(splt[0]);
	if (!is_num(splt[1]) || !is_num(splt[2]))
		man_err_map("Error: coords not numbers\n", NULL, NULL, map);
	coord_x = ft_atoli(splt[1]);
	coord_y = ft_atoli(splt[2]);
	if (coord_x > INT32_MAX || coord_y > INT32_MAX ||
		coord_x < INT32_MIN || coord_y < INT32_MIN)
		man_err_map("Error: coords bigger than int\n", NULL, NULL, map);
	new->x = coord_x;
	new->y = coord_y;
	new->linked_to = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->num_linked_to = 0;
	new->level = -1;
	new->path_id = 0;
	return (new);
}

void			add_room(char *buf, t_flag *flag, t_map *map)
{
	int64_t		num;
	t_room		*new;

	new = NULL;
	map->splt = ft_strsplit(buf, ' ');
	num = 0;
	while (*(num + map->splt) != NULL)
		num++;
	if (num != 3)
		man_err_map("Error: wrong room line\n", buf, ft_strdel, map);
	if (no_room_with_this_name(map))
		new = new_room(map->splt, flag, map);
	set_start_and_fin(new, map, flag);
	if (new)
		link_rooms(map, new);
	ft_del_splitter(map->splt);
	map->splt = NULL;
}
