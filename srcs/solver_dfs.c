#include "lem_in.h"

void		delite_links_for_gray_dots(t_graph_inf *inf)
{
	int		i;
	t_link	*tmp;

	i = 0;
	while (inf->links_to_gray_dot[i])
	{
		tmp = inf->links_to_gray_dot[i];
		if (!tmp->prev)
			tmp->mirror->to->linked_to = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		free(tmp);
		inf->links_to_gray_dot[i] = NULL;
		i++;
	}
}

static void	add_mirror_links(t_link *link, t_graph_inf *inf)
{
	int		i;

	i = 0;
	while (inf->mirror_links[i])
		i++;
	inf->mirror_links[i] = link;
	inf->mirror_links[i + 1] = link->mirror;
	inf->two_flows++;
}

t_room		*find_vertex(t_link *link, t_graph_inf *inf, t_map *map)
{
	t_link	*min_level;
	t_link	*tmp;

	if (!link)
		return (NULL);
	tmp = link;
	while (link)
	{
		if (!link->flow && link->to->color == WHITE)
			break ;
		link = link->next;
	}
	if (!link)
	{
		link = tmp;
		while (link)
		{
			if (!link->flow && link->to->color == GRAY)
				break ;
			link = link->next;
		}
		if (!link)
			return (NULL);
	}
	min_level = link;
	link = link->next;
	while (link)
	{
		if (!link->flow && link->to->color == min_level->to->color && link->to->level < min_level->to->level)
			min_level = link;
		link = link->next;
	}

	if ((inf->position_in_way >= 2 && min_level->to == inf->ways[inf->current_way_number][inf->position_in_way - 2]) || (inf->position_in_way == 1 && min_level->to == inf->ways[inf->current_way_number][inf->position_in_way - 1]))
		return (NULL);

	min_level->flow = 1;


	int i;

	i = 0;
	if (min_level->to != map->room_end && min_level->to->color == GRAY)
	{
		while (inf->links_to_gray_dot[i])
			i++;
		inf->links_to_gray_dot[i++] = min_level;
		inf->links_to_gray_dot[i] = min_level->mirror;
	}


	if (min_level->mirror->flow)
		add_mirror_links(min_level, inf);
	return (min_level->to);
}

void		clear_flow(t_room *prev_room, t_room *current_room)
{
	t_link	*tmp;

	tmp = prev_room->linked_to;
	while (tmp->to != current_room)
		tmp = tmp->next;
	tmp->flow = 0;
}

void		clear_way(t_graph_inf *inf)
{
	int		i;
	t_link	*tmp;

	i = 1;
	while (inf->ways[inf->current_way_number][i])
	{
		tmp = inf->ways[inf->current_way_number][i - 1]->linked_to;
		while (tmp && tmp->to != inf->ways[inf->current_way_number][i])
			tmp = tmp->next;
		if (tmp)
			tmp->flow = 0;
		i++;
	}
	i = 1;
	while (inf->ways[inf->current_way_number][i])
	{
		inf->ways[inf->current_way_number][i]->color = WHITE;
		inf->ways[inf->current_way_number][i++] = NULL;
	}
	inf->position_in_way = 1;
}

int			dfs(t_room *room, t_graph_inf *inf, t_map *map)
{
	if (room->color == WHITE)
		room->color = GRAY;
	if (room == map->room_end)
	{
		if (!inf->mirror_links[0] && inf->links_to_gray_dot[0])
		{
			delite_links_for_gray_dots(inf);
			clear_way(inf);
			if (!dfs(inf->ways[inf->current_way_number][0], inf, map))
				return (0);
			else
				return (1);
		}
		else
			return (1);
	}
	inf->ways[inf->current_way_number][inf->position_in_way] = find_vertex(room->linked_to, inf, map);
	if (inf->ways[inf->current_way_number][inf->position_in_way])
	{
		inf->position_in_way++;
		if (!dfs(inf->ways[inf->current_way_number][inf->position_in_way - 1], inf, map))
			return (0);
		else
			return (1);
	}
	else
	{
		if (room == map->room_start)
			return (0);
		else
		{
			room->color = BLACK;
			clear_flow(inf->ways[inf->current_way_number][inf->position_in_way - 2], room);
			inf->position_in_way--;
			if (!dfs(inf->ways[inf->current_way_number][inf->position_in_way - 1], inf, map))
				return (0);
			else
				return (1);
		}
	}
}

