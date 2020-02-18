/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:43:01 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/16 04:38:40 by kona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			initialization_bfs(t_room **find_source, int *c_a, int *c_p)
{
	*find_source = NULL;
	*c_a = 1;
	*c_p = 0;
}

t_room			*bfs_potential(t_room *start, t_map *map)
{
	t_link		*tmp_link;
	t_room		**line;
	int			current_pos;
	int			current_addition;
	t_room		*find_source;

	if (!start)
		return (NULL);
	initialization_bfs(&find_source, &current_addition, &current_pos);
	line = (t_room **)malloc(sizeof(t_room *) * (map->num_nodes + 1));
	ft_bzero(line, sizeof(t_room *) * (map->num_nodes + 1));
	line[map->num_nodes] = NULL;
	line[current_pos] = start;
	while (line[current_pos])
	{
		tmp_link = line[current_pos]->linked_to;
		while (tmp_link)
		{
			if (tmp_link->to->potential == 0 && tmp_link->to != start && tmp_link->flow == 0)
			{
				if (!find_source && (tmp_link->to == map->fin))
					 find_source = tmp_link->to;
				if (tmp_link->to != map->start)
					line[current_addition++] = tmp_link->to;
				tmp_link->to->potential = line[current_pos]->potential + 1;
				tmp_link->to->lev_m_pot = tmp_link->to->level - tmp_link->to->potential;
			}
			tmp_link = tmp_link->next;
		}
		current_pos++;
	}
	free(line);
	return (find_source);
}



t_room			*bfs_level(t_room *sink, t_map *map)
{
	t_link		*tmp_link;
	t_room		**line;
	int			current_pos;
	int			current_addition;
	t_room		*find_source;

	if (!sink)
		return (NULL);
	initialization_bfs(&find_source, &current_addition, &current_pos);
	line = (t_room **)malloc(sizeof(t_room *) * (map->num_nodes + 1));
	ft_bzero(line, sizeof(t_room *) * (map->num_nodes + 1));
	line[map->num_nodes] = NULL;
	line[current_pos] = sink;
	while (line[current_pos])
	{
		tmp_link = line[current_pos]->linked_to;
		while (tmp_link)
		{
			if (tmp_link->to->level == 0 && tmp_link->to != sink && tmp_link->flow == 0)
			{
				if (!find_source && (tmp_link->to == map->start))
					 find_source = tmp_link->to;
				if (tmp_link->to != map->start)
					line[current_addition++] = tmp_link->to;
				tmp_link->to->level = line[current_pos]->level + 1;
			}
			tmp_link = tmp_link->next;
		}
		current_pos++;
	}
	free(line);
	return (find_source);
}
