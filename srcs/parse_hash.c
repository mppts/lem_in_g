/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:40:26 by limry             #+#    #+#             */
/*   Updated: 2020/02/04 20:43:14 by limry            ###   ########.fr       */
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
	uint64_t	num;
	uint64_t	i;

	map->hashed_rooms = (t_room**)malloc(map->num_nodes * sizeof(t_room*));
	ft_bzero(map->hashed_rooms, map->num_nodes * sizeof(t_room*));
	tmp = map->room_start;
	i = 0;
	while (i++ < map->num_nodes)
	{
		tmp->hash = get_hash(tmp->name, map->num_nodes);
		num = 0;
		while (map->hashed_rooms[tmp->hash + num])
			if (++num + tmp->hash >= map->num_nodes)
				num = -tmp->hash;
		map->hashed_rooms[tmp->hash + num] = tmp;
		tmp->hash_id = tmp->hash + num;
		tmp = tmp->next;
	}
	if (map->room_end == map->room_start)
		map->room_start->hash = get_hash(map->room_start->name, map->num_nodes);
	map->is_rooms_hashed = TRUE;
}

t_room			*find_hashed_room(t_map *map, char *name)
{
	uint64_t	hash;
	uint8_t		loop;

	hash = get_hash(name, map->num_nodes);
	loop = 0;
	while (!map->hashed_rooms[hash] ||
	ft_strcmp(map->hashed_rooms[hash]->name, name))
	{
		hash++;
		if (hash >= map->num_nodes)
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
