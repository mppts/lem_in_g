/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:37:39 by limry             #+#    #+#             */
/*   Updated: 2020/02/04 21:36:55 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		error_in_link(t_map *map, t_room *from, t_room *to)
{
	t_link		*tmp;

	if (from == to)
		return (1);
	tmp = from->linked_to;
	while (tmp)
	{
		if (tmp->to == to)
			return (1);
		tmp = tmp->next;
	}
	tmp = to->linked_to;
	while (tmp)
	{
		if (tmp->to == from)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static t_link	*add_new_link(t_room *from, t_room *to)
{
	t_link		*new;
	t_link		*tmp;

	if (!(new = (t_link*)malloc(sizeof(t_link))))
		man_err("Error in add_link_to_room\n", NULL, NULL);
	new->to = to;
	new->next = NULL;
	new->prev = NULL;
	new->mirror = NULL;
	new->path_id = 0;
	if (!from->linked_to)
		from->linked_to = new;
	else
	{
		tmp = from->linked_to;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	from->num_linked_to++;
	return (new);
}

void			add_links(t_room *from, t_room *to)
{
	t_link		*forward;
	t_link		*back;

	forward = add_new_link(from, to);
	back = add_new_link(to, from);
	forward->mirror = back;
	back->mirror = forward;
}

void			add_link(char *buf, t_map *map)
{
	int64_t		num;
	t_room		*from;
	t_room		*to;

	map->splt = ft_strsplit(buf, '-');
	num = 0;
	while (*(num + map->splt) != NULL)
		num++;
	if (num != 2)
	{
		ft_del_splitter(map->splt);
		man_err_map("Error\n", NULL, NULL, map);
	}
	if (!(from = find_hashed_room(map, map->splt[0])))
		man_err("Error finding from\n", NULL, NULL);
	if (!(to = find_hashed_room(map, map->splt[1])))
		man_err("Error finding to\n", NULL, NULL);
	if (error_in_link(map, from, to))
		man_err("Error\n", NULL, NULL);
	add_links(from, to);
	ft_del_splitter(map->splt);
	map->splt = NULL;
}
