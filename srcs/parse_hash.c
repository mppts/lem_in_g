/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:40:26 by limry             #+#    #+#             */
/*   Updated: 2020/02/10 11:35:56 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

uint64_t		get_hash(char *str, uint64_t size)
{
	uint64_t hash;
	uint64_t c;

	hash = 5381UL;
	while ((c = *str))
	{
		hash = ((hash << 5UL) + hash) + c;
		str++;
	}
	return (hash % size);
}

void			hash_rooms(t_map *map)
{
	t_room		*tmp;
	int64_t		num;
	int64_t		i;

	if (!map->room_start)
		man_err_map("ERROR: no rooms\n", &map->buf, ft_strdel, map);
	map->len_rh = map->num_nodes * 3;
	map->hashed_rooms = (t_room**)malloc(map->len_rh * sizeof(t_room*));
	ft_bzero(map->hashed_rooms, map->len_rh * sizeof(t_room*));
	tmp = map->room_start;
	i = 0;
	while (i++ < map->num_nodes)
	{
		tmp->hash = get_hash(tmp->name, map->len_rh);
		num = 0;
		while (map->hashed_rooms[tmp->hash + num])
			if (++num + tmp->hash >= map->len_rh)
				num = -tmp->hash;
		map->hashed_rooms[tmp->hash + num] = tmp;
		tmp->hash_id = tmp->hash + num;
		tmp = tmp->next;
	}
	if (map->room_end == map->room_start)
		map->room_start->hash = get_hash(map->room_start->name, map->len_rh);
	map->is_rooms_hashed = TRUE;
}

t_room			*find_hashed_room(t_map *map, char *name)
{
	uint64_t	hash;
	uint8_t		loop;

	hash = get_hash(name, map->len_rh);
	loop = 0;
	while (!map->hashed_rooms[hash] ||
	ft_strcmp(map->hashed_rooms[hash]->name, name))
	{
		hash++;
		if (hash >= map->len_rh)
		{
			hash = 0;
			loop++;
		}
		if (loop > 1)
			break ;
	}
	if (loop > 1)
		return (NULL);
	return (map->hashed_rooms[hash]);
}
