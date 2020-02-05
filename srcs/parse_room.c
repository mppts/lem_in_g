/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:14:21 by limry             #+#    #+#             */
/*   Updated: 2020/02/05 16:58:14 by limry            ###   ########.fr       */
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
		{
			del_room(new);
			man_err_map("Error: too many entries\n", map->buf, ft_strdel, map);
		}
	}
	if (flag->flag_end == 1)
	{
		if (!map->fin)
			map->fin = new;
		else
		{
			del_room(new);
			man_err_map("Error: too many exits\n", map->buf, ft_strdel, map);
		}
	}
	flag->flag_start = 0;
	flag->flag_end = 0;
}

static int		no_room_with_this_name(t_map *map)
{
	t_room		*tmp;
	uint64_t	i;

	if (!map->num_nodes)
		return (1);
	i = map->num_nodes;
	tmp = NULL;
	if (map->room_start)
		tmp = map->room_start;
	while (i-- && tmp)
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
	int64_t	x;
	int64_t	y;

	if (!is_num(splt[1]) || !is_num(splt[2]))
		man_err_map("Error: coords not numbers\n", map->buf, ft_strdel, map);
	x = ft_atoli(splt[1]);
	y = ft_atoli(splt[2]);
	if (x > INT32_MAX || y > INT32_MAX ||
		x < INT32_MIN || y < INT32_MIN)
		man_err_map("Error: coords bigger than int\n",
				map->buf, ft_strdel, map);
	if (ft_strchr(splt[0], '-'))
		man_err_map("Error: dash in room name\n", map->buf, ft_strdel, map);
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		man_err_map("Error: can't allocate room\n", map->buf, ft_strdel, map);
	init_room(new, (int)x, (int)y, splt[0]);
	return (new);
}

void			add_room(char *buf, t_flag *flag, t_map *map)
{
	t_room		*new;
	char 		*b;

	if (!((b = ft_strchr(buf, ' ')) &&
	(*(++b) != '\0' && (b = ft_strchr(b , ' '))) &&
	(*(++b) != '\0' &&!(ft_strchr(b, ' ')))))
		man_err_map("Error: wrong room line\n", &buf, ft_strdel, map);
	new = NULL;
	map->splt = ft_strsplit(buf, ' ');
	if (no_room_with_this_name(map))
		new = new_room(map->splt, flag, map);
	else
		man_err_map("Error: this room already exists\n", &buf, ft_strdel, map);
	set_start_and_fin(new, map, flag);
	if (new)
		link_rooms(map, new);
	ft_del_splitter(map->splt);
	map->splt = NULL;
}
