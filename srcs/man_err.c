/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:00:51 by limry             #+#    #+#             */
/*   Updated: 2020/02/28 16:43:31 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void			del_room(t_room *room)
{
	t_link		*tmp;
	t_link		*tmp1;

	if (room)
	{
		tmp = room->linked_to;
		while (tmp)
		{
			tmp1 = tmp;
			tmp = tmp->next;
			free(tmp1);
		}
		free(room->name);
		free(room);
	}
}

void			del_paths(t_path *path)
{
	t_path		*tmp;
	t_path		*tmp1;

	if (!path)
		return ;
	tmp = path;
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1->path);
		tmp1->path = NULL;
		free(tmp1);
	}
}

void			del_map(t_map *map)
{
	t_room		*tmp;
	t_room		*tmp1;
	uint64_t	i;

	if (!map)
		return ;
	if (map->is_rooms_hashed)
		free(map->hashed_rooms);
	i = map->num_nodes;
	tmp = map->room_start;
	while (i--)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		del_room(tmp1);
	}
	if (map->path)
		del_paths(map->path);
	dstr_del(map->dstr);
}

void			man_err_map(char *msg, char **data,
				void (*f_todel)(char**), t_map *map)
{
	get_next_line(-1, &map->buf);
	if (msg)
		ft_putstr_fd(msg, 2);
	if (f_todel && data)
		f_todel(data);
	del_map(map);
	exit(1);
}
