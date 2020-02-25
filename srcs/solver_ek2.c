/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_ek2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:38:38 by limry             #+#    #+#             */
/*   Updated: 2020/02/25 15:47:25 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			fill_link_from_to(t_room *from, t_room *to)
{
	t_link		*ln;

	ln = from->linked_to;
	while (ln)
	{
		if (ln->to == to)
		{
			if (ln->flow == -1)
			{
				ln->flow = 1;
				ln->mirror->flow = 1;
			}
			else
			{
				ln->flow = 0;
				ln->mirror->flow = -1;
			}
			break ;
		}
		ln = ln->next;
	}
}

void			fulfill_path(t_map *g)
{
	t_room		*rm;

	rm = g->fin;
	while (rm != g->start)
	{
		rm->level = 1;
		fill_link_from_to(rm->pred, rm);
		rm = rm->pred;
	}
}

void			push_path(t_patha *path, t_map *g, t_link *lf)
{
	t_link		*link;

	path->path_starts[path->path_id][0] = g->start;
	path->path_starts[path->path_id][1] = lf->to;
	path->path_lens[path->path_id] = 2;
	link = lf->to->linked_to;
	while (link)
	{
		if (link->flow == 0)
		{
			path->path_starts[path->path_id]\
			[path->path_lens[path->path_id]++] = link->to;
			link = link->to->linked_to;
		}
		else
			link = link->next;
	}
	path->path_starts[path->path_id][path->path_lens[path->path_id]] = NULL;
}

void			find_all_paths(t_patha *path, t_map *g)
{
	t_link		*link;

	link = g->start->linked_to;
	while (link)
	{
		if (link->flow == 0)
		{
			push_path(path, g, link);
			path->amt_steps_cost += path->path_lens[path->path_id];
			path->path_id++;
			path->path_starts[path->path_id] =
					path->path_starts[path->path_id - 1] +
					path->path_lens[path->path_id - 1];
		}
		link = link->next;
	}
}
