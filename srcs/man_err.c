/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:00:51 by limry             #+#    #+#             */
/*   Updated: 2020/02/07 18:53:02 by kona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void			ft_del_splitter(char **pocket)
{
	uint64_t	i;

	i = 0;
	if (!pocket)
		return ;
	while (pocket[i])
	{
		free(pocket[i]);
		i++;
	}
	free(pocket);
}

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
	dstr_del(map->dstr);
}

void			man_err_map(char *msg, char **data,
				void (*f_todel)(char**), t_map *map)
{
	get_next_line(-1, map->buf);
	write(1, map->dstr->data, map->dstr->len);
	if (msg)
		ft_putstr(msg);
	if (f_todel && data)
		f_todel(data);
	del_map(map);
	exit(1);
}
