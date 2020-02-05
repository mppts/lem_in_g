/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:37:39 by limry             #+#    #+#             */
/*   Updated: 2020/02/05 16:22:03 by limry            ###   ########.fr       */
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

static t_link	*add_new_link(t_room *from, t_room *to, t_map *map)
{
	t_link		*new;
	t_link		*tmp;

	if (!(new = (t_link*)malloc(sizeof(t_link))))
		man_err_map("Error: can't allocate new link\n",
				map->buf, ft_strdel, map);
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

void			add_links(t_room *from, t_room *to, t_map *map)
{
	t_link		*forward;
	t_link		*back;

	forward = add_new_link(from, to, map);
	back = add_new_link(to, from, map);
	forward->mirror = back;
	back->mirror = forward;
}

void			add_link(char *buf, t_map *map)
{
	t_room		*from;
	t_room		*to;
	char		*b;

	map->splt = ft_strsplit(buf, '-');
	b = NULL;
	if (!((b = ft_strchr(buf, '-')) && !ft_strchr(++b, '-')))
		man_err_map("Error: link line error\n", &buf, ft_strdel, map);
	if (!(from = find_hashed_room(map, map->splt[0])))
		man_err_map("Error: can't find from\n", &buf, ft_strdel, map);
	if (!(to = find_hashed_room(map, map->splt[1])))
		man_err_map("Error: can't find to\n", &buf, ft_strdel, map);
	if (error_in_link(map, from, to))
		man_err_map("Error: link already exists\n", &buf, ft_strdel, map);
	add_links(from, to, map);
	ft_del_splitter(map->splt);
	map->splt = NULL;
}
