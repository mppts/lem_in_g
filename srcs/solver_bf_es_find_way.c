/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_bf_es_find_way.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:24:41 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/27 17:24:45 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*find_way_on_fork_e_s(t_room *room, t_room *room_prev)
{
	t_link		*link;

	link = room->linked_to;
	while (link)
	{
		if (link->to != room_prev &&
				((link->to->level_rev - 1 == room->level_rev &&
					link->flow && !link->to->c_in_way) ||
				(link->to->level_rev + 1 == room->level_rev &&
					!link->flow && !link->to->c_in_way)))
			return (link->to);
		link = link->next;
	}
	return (NULL);
}

int				copy_to_line_e_s(t_room **line, int i, t_room **tmp_line,
								t_map *map)
{
	int			k;

	k = i;
	while (i >= 0)
		line[k--] = tmp_line[i--];
	free(tmp_line);
	if (line[0] == map->start)
		return (1);
	return (0);
}

int				i_have_to_save_one_line_e_s(t_room **tmp_line)
{
	free(tmp_line);
	return (0);
}

int				find_way_bf_e_s(t_map *map, t_room **line)
{
	int			i;
	t_room		*tmp;
	t_room		**tmp_line;

	i = 0;
	tmp_line = (t_room **)malloc(sizeof(t_room) * (map->num_nodes + 1));
	tmp = map->start;
	while (tmp && tmp != map->fin)
	{
		tmp_line[i++] = tmp;
		if (tmp == map->start || (tmp->room_from_we_came && !tmp->c_in_way &&
			(tmp->room_from_we_came->level_rev - 1 == tmp->level_rev ||
				tmp->room_from_we_came->level_rev + 1 == tmp->level_rev)))
		{
			tmp->c_in_way = 1;
			tmp = tmp->room_from_we_came;
		}
		else
			tmp = find_way_on_fork_e_s(tmp, tmp_line[i - 2]);
	}
	if (!tmp)
		return (i_have_to_save_one_line_e_s(tmp_line));
	tmp_line[i] = tmp;
	return (copy_to_line_e_s(line, i, tmp_line, map));
}
