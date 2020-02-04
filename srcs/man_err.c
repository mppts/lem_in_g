/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:00:51 by limry             #+#    #+#             */
/*   Updated: 2020/02/04 22:07:04 by limry            ###   ########.fr       */
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

	if(!map)
		return ;
	if (map->splt)
		ft_del_splitter(map->splt);
	if (map->hashed_rooms)
		free(map->hashed_rooms);
	tmp = map->room_start;
	while(tmp)
	{
		tmp1 = tmp;
		del_room(tmp1);
		tmp = tmp->next;
	}
}

void			man_err(char *msg, void *data, void (*f_todel)(void**))
{
	if (f_todel && data)
		f_todel(&data);
	if (msg)
		ft_putstr(msg);
	exit(1);
}


void			man_err_map(char *msg, void *data,
				void (*f_todel)(void**), t_map *map)
{
	if (f_todel && data)
		f_todel(&data);
	if (map)
		del_map(map);
	if (msg)
		ft_putstr(msg);
	exit(1);
}