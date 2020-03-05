/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_ek2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:38:38 by limry             #+#    #+#             */
/*   Updated: 2020/03/04 18:36:42 by limry            ###   ########.fr       */
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
				//printf("%d", ln->flow);
				ln->flow = 1;
				ln->mirror->flow = 1;
			}
			else if (ln->flow == 1)
			{
				//printf("%d", ln->flow);
				ln->flow = 0;
				ln->mirror->flow = -1;
			}
			break ;
		}
		ln = ln->next;
	}
}

int				go_pred_out(t_room **rm, int *flag_neg, int *flag_move)
{
	t_room		*rm_tmp;

	if ((*rm)->pred_out)
	{
		//printf("\033[0;31m%s\033[0m ", (*rm)->name);
		(*rm)->level = *flag_neg ? 0 : -1;
		fill_link_from_to((*rm)->pred_out, (*rm));
		rm_tmp = (*rm);
		(*rm) = (*rm)->pred_out;
		rm_tmp->pred_out = NULL;
		*flag_neg = 1;
		*flag_move = BACK;
		return (0);
	}
	return (1);
}

int				go_pred_in(t_room **rm, int *flag_neg, int *flag_move)
{
	t_room		*rm_tmp;

	if ((*rm)->pred_in)
	{
		//printf("\033[0;32m%s\033[0m ", (*rm)->name);
		(*rm)->level = 1;
		fill_link_from_to((*rm)->pred_in, (*rm));
		rm_tmp = (*rm);
		(*rm) = (*rm)->pred_in;
		rm_tmp->pred_in = NULL;
		*flag_neg = 0;
		*flag_move = BACK;
		return (0);
	}
	return (1);
}
void			fulfill_path(t_map *g)
{
	t_room		*rm;
	int 		flag_neg;
	int 		flag_move;

	rm = g->fin;
	flag_neg = 0;
	flag_move = NORM;
	while (rm != g->start)
	{
		if (flag_move == NORM)
		{
			if (go_pred_in(&rm, &flag_neg, &flag_move))
				go_pred_out(&rm, &flag_neg, &flag_move);
			if (rm->sim == 1)
				flag_move = NORM;
		}
		else if (flag_move == BACK)
		{
			if (go_pred_out(&rm, &flag_neg, &flag_move))
				go_pred_in(&rm, &flag_neg, &flag_move);
			if (rm->sim == 1)
				flag_move = BACK;
		}
	}
	//printf("\n");
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


t_room			*split_node(t_room *in, t_map *g)
{
	t_room		*out;
	t_link		*ln_in_out;
	t_link		*ln_out_in;

	if (!(out = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	out->level = 1;
	out->name = ft_strdup(in->name);
	out->linked_to = in->linked_to;
	in->linked_to = NULL;
	out->num_linked_to = in->num_linked_to;
	out->next = g->room_start;
	g->room_start->prev = out;
	out->prev = g->room_end;
	g->room_end->next = out;
	out->sign = 0;
	out->ant = 0;
	out->pred_in = NULL;
	out->pred_out = NULL;
	out->delta_in = INT64_MAX;
	out->delta_out = INT64_MAX;
	if (!(ln_in_out = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	ln_in_out->to = out;
	ln_in_out->flow = 0;
	ln_in_out->next = NULL;
	in->linked_to = ln_in_out;
	if (!(ln_out_in = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	ln_out_in->flow = -1;
	ln_out_in->to = in;
	ln_out_in->next = out->linked_to;
	out->linked_to = ln_out_in;
}

void			push_path(t_patha *path, t_map *g, t_link *lf)
{
	t_link		*ln;

	path->path_starts[path->path_id][0] = g->start;
	path->path_starts[path->path_id][1] = lf->to;
	lf->to->level = 1;
	path->path_lens[path->path_id] = 2;
	ln = lf->to->linked_to;
	while (ln)
	{
		if (ln->flow == 0 && (!g->paths || !is_in_res(ln->to, g->paths->path)))
		{
			path->path_starts[path->path_id][path->path_lens[path->path_id]++] = ln->to;
			split_node(ln->to, g);
			ln->to->level = 1;
			ln = ln->to->linked_to;
		}
		else
			ln = ln->next;
		if (ln->to == g->fin)
			break ;
	}
	if (ln && ln->to)
		path->path_starts[path->path_id][path->path_lens[path->path_id]] = (t_room*)ln->to;
	path->path_lens[path->path_id]++;
	//path->path_starts[path->path_id][path->path_lens[path->path_id]] = NULL;
}

void			find_all_paths(t_patha *path, t_map *g)
{
	t_link		*ln;

	ln = g->start->linked_to;
	while (ln)
	{
		if (ln->flow == 0)
		{
			push_path(path, g, ln);
			path->amt_steps_cost += path->path_lens[path->path_id];
			path->path_id++;
			path->path_starts[path->path_id] =((t_room**) (path->path_starts[path->path_id - 1] + path->path_lens[path->path_id - 1]));
		}
		ln = ln->next;
	}
}
