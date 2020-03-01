/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:14:21 by limry             #+#    #+#             */
/*   Updated: 2020/02/28 16:32:31 by limry            ###   ########.fr       */
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
			man_err_map("ERROR: too many entries\n", NULL, NULL, map);
		}
	}
	if (flag->flag_end == 1)
	{
		if (!map->fin)
			map->fin = new;
		else
		{
			del_room(new);
			man_err_map("ERROR: too many exits\n", NULL, NULL, map);
		}
	}
	flag->flag_start = 0;
	flag->flag_end = 0;
}

static int		no_room_with_this_name(t_map *map, t_r_reader r)
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
		if (!ft_strcmp(tmp->name, r.name_room))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static t_room	*new_room(t_r_reader r, t_map *map)
{
	t_room		*new;
	int64_t		x;
	int64_t		y;

	if (!is_num(r.sx) || !is_num(r.sy))
		man_err_map("ERROR: coords not numbers\n",
		&r.name_room, ft_strdel, map);
	x = ft_atoli(r.sx);
	y = ft_atoli(r.sy);
	if (x > INT32_MAX || y > INT32_MAX ||
		x < INT32_MIN || y < INT32_MIN)
		man_err_map("ERROR: coords bigger than int\n",
				&map->buf, ft_strdel, map);
	if (ft_strchr(r.name_room, '-'))
		man_err_map("ERROR: dash in room name\n", &map->buf, ft_strdel, map);
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		man_err_map("ERROR: can't allocate room\n", &map->buf, ft_strdel, map);
	init_room(new, (int)x, (int)y, r.name_room);
	return (new);
}

void			add_room(char *buf, t_flag *flag, t_map *map)
{
	t_room		*new;
	char		*b;
	t_r_reader	r;

	r.name_room = buf;
	if (!((b = ft_strchr(buf, ' ')) &&
	(*(r.sx = ++b) != '\0' &&
	(b = ft_strchr(b, ' '))) &&
	(*(r.sy = ++b) != '\0' && !(ft_strchr(b, ' ')))))
		man_err_map("ERROR: wrong room line\n", &buf, ft_strdel, map);
	*(r.sx - 1) = '\0';
	*(r.sy - 1) = '\0';
	new = NULL;
	if (no_room_with_this_name(map, r))
		new = new_room(r, map);
	else
		man_err_map("ERROR: this room already exists\n", &buf, ft_strdel, map);
	set_start_and_fin(new, map, flag);
	if (new)
		link_rooms(map, new);
}
