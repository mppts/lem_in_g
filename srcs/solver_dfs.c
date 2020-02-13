#include "lem_in.h"

static void		add_mirror_links(t_link *link, t_graph_inf *inf)
{
	int			i;

	i = 0;
	while (inf->mirror_links[i])
		i++;
	inf->mirror_links[i] = link;
	inf->mirror_links[i + 1] = link->mirror;
	inf->two_flows += 2;
}
/*
int			check_links_to_white(t_room *current_room, t_room *checking_room, t_map *map)
{
	t_link	*tmp;

	if (checking_room->color != GRAY)
		return (0);
	tmp = checking_room->linked_to;
	while (tmp)
	{
		if (tmp->to->color == WHITE && tmp->to != map->fin && tmp->to != current_room)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_room		*find_vertex(t_room *room, t_graph_inf *inf, t_map *map)
{
	t_link *link;
	t_link *min_level;
	t_link *tmp_white;
	t_link *tmp_gray;

	link = room->linked_to;
	if (!link)
		return (NULL);
	tmp_white = NULL;
	tmp_gray = NULL;
	if (!inf->current_pos_in_way)
		while (link && (link->to->color != WHITE || link->flow))
			link = link->next;
	else
		while (link && (link->flow || link->to->color == BLACK || link->to == inf->ways[inf->current_way_number][inf->current_pos_in_way - 1] || check_links_to_white(room, link->to, map)))
			link = link->next;

	if (!link)
		return (NULL);
	if (link->to->color == WHITE)
		tmp_white = link;
	else
		tmp_gray = link;
	link = link->next;
	while (link)
	{
		if (link->to->color == WHITE)
		{
			if (!tmp_white || (!link->flow && link->to->level < tmp_white->to->level))
				tmp_white = link;
		}
		else if (link->to->color == GRAY && !tmp_white)
		{
			if (!inf->current_pos_in_way)
			{
				if (!link->flow && link->to != map->start && link->to->level < tmp_gray->to->level  && !check_links_to_white(room, link->to, map))
					tmp_gray = link;
			}
			else if (!link->flow && link->to != inf->ways[inf->current_way_number][inf->current_pos_in_way - 1] && link->to->level < tmp_gray->to->level  && !check_links_to_white(room, link->to, map))
				tmp_gray = link;
		}
		link = link->next;
	}
	if (tmp_white)
		min_level = tmp_white;
	else
		min_level = tmp_gray;
	min_level->flow = 1;
	if (min_level->mirror->flow)
		add_mirror_links(min_level, inf);
	return (min_level->to);
}
*/

void 		find_min_white_gray(t_link	*link, t_graph_inf *inf, t_link	**tmp_white, t_link	**tmp_gray)
{

	if (link->to->num_linked_to == 1 || link->to->color == BLACK)
	{
		link->to->color = BLACK;
		return ;
	}
	else if (link->flow)
		return ;
	else if (link->to != inf->ways[inf->current_way_number][inf->current_pos_in_way])
	{
		if(*tmp_white && link->to->color == WHITE)
			*tmp_white = (*tmp_white)->to->level > link->to->level ? link : *tmp_white;
		else if (link->to->color == WHITE)
			*tmp_white = link;
		else if (*tmp_gray && link->to->color == GRAY)
			*tmp_gray = (*tmp_gray)->to->level > link->to->level ? link : *tmp_gray;
		else if (link->to->color == GRAY)
			*tmp_gray = link;
	}
}

t_room		*find_vertex(t_room *room, t_graph_inf *inf, t_map *map)
{
	t_link	*link;
	t_link	*tmp_white;
	t_link	*tmp_gray;
	t_link	*tmp_white_or_gray;

	tmp_white = NULL;
	tmp_gray = NULL;
	link = room->linked_to;
	while (link)
	{
		if (link->to != map->start)
			find_min_white_gray(link, inf, &tmp_white, &tmp_gray);
		link = link->next;
	}
	tmp_white_or_gray = tmp_white ? tmp_white : tmp_gray;
	if (tmp_white_or_gray)
	{
		tmp_white_or_gray->flow = 1;
		return (tmp_white_or_gray->to);
	}
	return (NULL);
}


/*
t_room		*find_vertex_from_gray(t_room *room, t_graph_inf *inf, t_map *map)
{
	t_link *link;
	t_link *min_level;
	t_link *tmp_white;
	t_link *tmp_gray;

	link = room->linked_to;
	if (!link)
		return (NULL);
	tmp_white = NULL;
	tmp_gray = NULL;
	if (!inf->current_pos_in_way)
		while (link && (link->to->color != WHITE || link->flow))
			link = link->next;
	else
		while (link && (link->flow || link->to->color == BLACK || link->to == inf->ways[inf->current_way_number][inf->current_pos_in_way - 1]))
			link = link->next;
	if (!link)
		return (NULL);
	if (link->to->color == WHITE)
		tmp_white = link;
	else
		tmp_gray = link;
	link = link->next;
	while (link)
	{
		if (link->to->color == WHITE && !link->flow)
		{
			if (!tmp_white || (!link->flow && link->to->level < tmp_white->to->level))
				tmp_white = link;
		}
		else if (link->to->color == GRAY && !tmp_white)
		{
			if (!link->flow && link->to != inf->ways[inf->current_way_number][inf->current_pos_in_way - 1] && link->to->level < tmp_gray->to->level)
				tmp_gray = link;
		}
		link = link->next;
	}
	if (tmp_white)
		min_level = tmp_white;
	else
		min_level = tmp_gray;
	min_level->flow = 1;
	if (min_level->mirror->flow)
		add_mirror_links(min_level, inf);
	return (min_level->to);
}
*/

t_link		*find_link(t_room *from, t_room *to)
{
	t_link	*tmp;

	tmp = from->linked_to;
	while(tmp)
	{
		if (tmp->to == to)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		find_vertex_from_gray(t_room *room, t_graph_inf *inf, t_map *map)
{
	t_link	*link;
	t_link	*tmp_white;
	t_link	*tmp_gray;

	tmp_white = NULL;
	tmp_gray = NULL;
	link = room->linked_to;
	while (link)
	{
		find_min_white_gray(link, inf, &tmp_white, &tmp_gray);
		link = link->next;
	}
	if (tmp_white)
		add_mirror_links(find_link(inf->ways[inf->current_way_number][inf->current_pos_in_way - 2], room), inf);
	else if (tmp_gray)
		add_mirror_links(tmp_gray, inf);
}

void		clear_flow(t_room *prev_room, t_room *current_room)
{
	t_link	*tmp;

	tmp = prev_room->linked_to;
	while (tmp->to != current_room)
		tmp = tmp->next;
	tmp->flow = 0;
}

int			dfs(t_room *room, t_graph_inf *inf, t_map *map)
{
	if (room->color == GRAY)
	{
		find_vertex_from_gray(room, inf, map);
		return (0);
	}
	else if (room->color == WHITE)
		inf->ways[inf->current_way_number][inf->current_pos_in_way] = find_vertex(room, inf, map);
	if (inf->ways[inf->current_way_number][inf->current_pos_in_way])
	{
		if (inf->ways[inf->current_way_number][inf->current_pos_in_way] == map->fin)
		{
			inf->ways[inf->current_way_number][inf->current_pos_in_way + 1] = NULL;
			return (1);
		}
		else
		{
			room->color = GRAY;
			(inf->current_pos_in_way)++;
			if (dfs(inf->ways[inf->current_way_number][inf->current_pos_in_way - 1], inf, map))
				return (1);
			else
				return (0);
		}
	}
	else if (room == map->start)
		return (0);
	else
	{
		if (inf->ways[inf->current_way_number][inf->current_pos_in_way - 2] != map->start &&
		dfs(inf->ways[inf->current_way_number][inf->current_pos_in_way - 2], inf, map))
			return (1);
		else
			return (0);
	}
}

