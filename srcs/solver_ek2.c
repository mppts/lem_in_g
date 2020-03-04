/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_ek2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:38:38 by limry             #+#    #+#             */
/*   Updated: 2020/03/04 08:54:06 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int is_in_res(struct s_room *room, t_room **paths);

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
				printf("%d", ln->flow);
				ln->flow = 1;
				ln->mirror->flow = 1;
			}
			else if (ln->flow == 1)
			{
				printf("%d", ln->flow);
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
	t_room		*rm_tmp;
	int 		flag_neg;

	rm = g->fin;
	flag_neg = 0;
	while (rm != g->start)
	{
		if (rm->pred_neg)
		{
			printf("\033[0;31m%s\033[0m ", rm->name);
			rm->level = flag_neg ? 0 : -1;
			fill_link_from_to(rm->pred_neg, rm);
			rm_tmp = rm;
			rm = rm->pred_neg;
			rm_tmp->pred_neg = NULL;
			flag_neg = 1;
		}
		else
		{
			printf("\033[0;32m%s\033[0m ", rm->name);
			rm->level = 1;
			fill_link_from_to(rm->pred, rm);
			rm = rm->pred;
			flag_neg = 0;
		}
	}
	printf("\n");
}

int				is_in_res(struct s_room *room, t_room **paths)
{
	t_room		*tmp;

	tmp = *paths;
	while(tmp)
	{
		if (tmp == room)
			return (1);
		tmp++;
	}
	return (0);
}
void			push_path(t_patha *path, t_map *g, t_link *lf)
{
	t_link		*link;

	path->path_starts[path->path_id][0] = g->start;
	path->path_starts[path->path_id][1] = lf->to;
	lf->to->level = 1;
	path->path_lens[path->path_id] = 2;
	link = lf->to->linked_to;
	while (link)
	{
		if (link->flow == 0 && (!g->paths || !is_in_res(link->to, g->paths->path)))
		{
			path->path_starts[path->path_id][path->path_lens[path->path_id]++] = link->to;
			link->to->level = 1;
			link = link->to->linked_to;
		}
		else
			link = link->next;
		if (link->to == g->fin)
			break ;
	}
	path->path_starts[path->path_id][path->path_lens[path->path_id]++] = link->to;
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
