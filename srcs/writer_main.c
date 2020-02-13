/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:42:37 by limry             #+#    #+#             */
/*   Updated: 2020/02/13 21:11:07 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				count_ants_for_paths(t_map *map)
{
	t_path			*tmp;
	t_path			*head;
	int64_t			to_div;
	int64_t			spreaded;
	int64_t			iter;

	head = map->path;
	spreaded = 0;
	while (head)
	{
		to_div = map->ants - spreaded;
		iter = 0;
		tmp = head->next;
		while (tmp)
		{
			to_div -= (head->len - tmp->len);
			iter++;
			tmp = tmp->next;
		}
		head->ants = to_div > 0 ? to_div / (iter + 1) : 0;
		head->ants = head->ants > (map->ants - spreaded) ?
		map->ants - spreaded : head->ants;
		spreaded += head->ants;
		head = head->next;
	}
}

void				log_ant_move(t_room *room, t_map *map, t_path *path)
{
	int 			color;

	color = path->id % 8 + 30;
	//dstr_joinstr(map->dstr, "\033[1;");
	//dstr_joinstr(map->dstr, ft_itoa(color));
	//dstr_joinstr(map->dstr, "m");
	dstr_joinstr(map->dstr, "L");
	dstr_joinstr(map->dstr, ft_itoa(room->ant));
	dstr_joinstr(map->dstr, "-");
	dstr_joinstr(map->dstr, room->name);
	//dstr_joinstr(map->dstr, "\033[0m");
}

int				move_ant(t_path *path, int cur_pos, int *ants_out, int *cur_ant, t_map *map)
{

	if (path->path[cur_pos]->ant ||
	(cur_pos != 0 && path->path[cur_pos - 1]->ant == 0))
		return (0);
	else if (cur_pos == 0 && path->ants)
	{
		path->path[cur_pos]->ant = *cur_ant;
		(*cur_ant)++;
		path->ants_on++;
		path->ants--;
		log_ant_move(path->path[cur_pos], map, path);
		return (1);
	}
	else if (path->path[cur_pos] == map->fin && path->path[cur_pos - 1]->ant != 0)
	{
		path->path[cur_pos]->ant = path->path[cur_pos - 1]->ant;
		log_ant_move(path->path[cur_pos], map, path);
		(*ants_out)++;
		path->ants_on--;
		path->path[cur_pos - 1]->ant = 0;
		path->path[cur_pos]->ant = 0;
		return (1);
	}
	else if (path->path[cur_pos - 1]->ant != 0)
	{
		path->path[cur_pos]->ant = path->path[cur_pos - 1]->ant;
		path->path[cur_pos - 1]->ant = 0;
		log_ant_move(path->path[cur_pos], map, path);
		return (1);
	}
	return (0);
}

void				push_ants(t_map *map)
{
	int64_t			step;
	int64_t			step_iter;
	int				ants_out;
	int				cur_ant;
	t_path			*cur_path;

	ants_out = 0;
	step = 1;
	cur_ant = 1;
	while (ants_out < map->ants)
	{
		step_iter = step;
		while (step_iter--)
		{
			cur_path = map->path;
			while (cur_path)
			{
				if (cur_path->ants_on || step_iter % cur_path->len == 0)
					if (move_ant(cur_path, step_iter % cur_path->len, &ants_out, &cur_ant, map))
						dstr_joinstr(map->dstr, " ");
				cur_path = cur_path->next;
			}
		}
		dstr_joinstr(map->dstr, "\n");
		step++;
	}
}

void				swap_paths(t_path *bigger, t_path *smaller)
{
	t_path			swap;

	swap.path = bigger->path;
	swap.len = bigger->len;
	bigger->path = smaller->path;
	bigger->len = smaller->len;
	smaller->path = swap.path;
	smaller->len = swap.len;
}

void 				sort_paths(t_map *map)
{
	t_path			*tmp1;
	t_path			*tmp2;
	int 			i;

	i = 1;
	tmp1 = map->path;
	tmp2 = tmp1->next;
	while (i)
	{
		i = 0;
		while (tmp1 && tmp2)
		{
			if (tmp1->len > tmp2->len)
			{
				swap_paths(tmp1, tmp2);
				i = 1;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		tmp1 = map->path;
		tmp2 = tmp1->next;
	}
}

void				print_paths(t_path *p, t_map *map)
{
	t_path			*tmp;
	uint64_t		i;

	tmp = p;
	while(tmp)
	{
		i = 0;
		while (i < tmp->len)
		{
			printf("[%s] ", tmp->path[i]->name);
			i++;
		}
		printf("\n");
		tmp = tmp->next;
	}
}

void				prep_paths(t_path *p)
{
	t_path			*tmp;
	int 			i;

	tmp = p;
	i = 0;
	while(tmp)
	{
		tmp->path = tmp->path + 1;
		tmp->len = tmp->len - 1;
		tmp->id = i++;
		tmp->ants_on = 0;
		tmp = tmp->next;
	}
}

void				writer(t_map *map)
{
	sort_paths(map);
	dstr_joinstr(map->dstr, "\n");
	//print_paths(map->path, map);
	prep_paths(map->path);
	count_ants_for_paths(map);
	push_ants(map);
}