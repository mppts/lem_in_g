/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:23:42 by limry             #+#    #+#             */
/*   Updated: 2020/01/29 14:04:37 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include "deque.c"

void	remove_room(t_map *g, t_room *room, t_link *link)
{
	//delete all links to room
	//delete room
}

void	path_is_founded(t_deq *deq, t_paths *paths);

void	dfs(t_map *g, t_deq *deq, int64_t levs[g->num_nodes], t_paths *paths)
{
	t_room	*tmp;
	t_link	*link;

	while(-1 != deq->rear)
	{
		tmp = pop_rear(g, deq);
		link = tmp->linked_to;
		while (link)
		{
			if (levs[tmp->hash_id] + 1 ==  levs[link->to->hash_id] && link->path_id == 0)
			{
				if (link->to == g->fin)
					path_is_founded(deq, paths);
				else if (!link->to->num_linked_to)
					remove_room(g, link->to, link);
				else
				{
					push_back(g, tmp, deq);
					dfs (g, deq, levs, paths);
				}
			}
			link = link->next;
		}
	}
}


int		bfs(t_map *g, t_room *start, t_deq *deq, int64_t levs[g->num_nodes])
{
	int64_t lev;
	t_room	*tmp;
	t_link	*link;

	lev = 0;
	init_dequeue(g, deq);
	push_back(g, start, deq);
	levs[start->hash_id] = lev;
	g->fin->level = INT64_MAX - 2;
	while(deq->begin != deq->rear)
	{
		tmp = pop_front(g, deq);
		lev = levs[tmp->hash_id] + 1;
		link = tmp->linked_to;
		while (link)
		{
			if (link->to->path_id)
				continue ;
			if (levs[link->to->hash_id] == -1)
			{
				levs[link->to->hash_id]= lev;
				push_back(g, link->to, deq);
			}
			else if (link->to == g->fin)
				g->no_path_exists = FALSE;
			link = link->next;
		}
	}
}

void			dinic(t_map *g, int ants, t_deq *deq, t_paths *paths)
{
	int64_t		lev[g->num_nodes];
	uint64_t	n;

	n = 0;
	while (n < g->num_nodes)
		lev[n++] = -1;
	g->no_path_exists = FALSE;
	while (!g->no_path_exists)
	{
		g->no_path_exists = TRUE;
		bfs(g, g->start, deq, lev);
		if (!g->no_path_exists)
			break ;
		else
		{
			init_dequeue(g, deq);
			push_back(g, g->start, deq);
			dfs(g, deq, lev, paths);
		}
	}
}

void		prep_for_solver(t_map *g, int ants)
{
	t_deq	deq;
	t_room	*q[g->num_nodes];
	t_paths *paths;

	deq.deq = q;
	init_paths(g, paths);
	init_dequeue(g, &deq);
	dinic(g, ants, &deq, paths);
}

