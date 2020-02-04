#include "lem_in.h"

static void	add_mirror_links(t_link *link, t_graph_inf *inf)
{
	int		i;

	i = 0;
	while (inf->mirror_links[i])
		i++;
	inf->mirror_links[i] = link;
	inf->mirror_links[i + 1] = link->mirror_link;
	inf->two_flows++;
}

t_room		*find_vertex(t_link *link, t_graph_inf *inf)
{
	t_link	*min_level;

	if (!link)
		return (NULL);
	while (link)
	{
		if (!link->flow && link->to->color == WHITE)
			break ;
		link = link->next;
	}
	if (!link)
		return (NULL);
	min_level = link;
	link = link->next;
	while (link)
	{
		if (!link->flow && link->to->color == WHITE && link->to->level < min_level->to->level)
			min_level = link;
		link = link->next;
	}
	min_level->flow = 1;
	if (min_level->mirror_link->flow)
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

int			dfs(t_room *room, t_graph_inf *inf)
{
	room->color = GRAY;
	if (room->is_start_or_end == SOURCE)
		return (1);
	inf->ways[inf->current_way_number][inf->position_in_way] = find_vertex(room->linked_to, inf);
	if (inf->ways[inf->current_way_number][inf->position_in_way])
	{
		inf->position_in_way++;
		dfs(inf->ways[inf->current_way_number][inf->position_in_way - 1], inf);
	}
	else
	{
		if (room->is_start_or_end == SINK)
			return (0);
		else
		{
			room->color = BLACK;
			clear_flow(inf->ways[inf->current_way_number][inf->position_in_way - 1], room);
			inf->position_in_way--;
			dfs(inf->ways[inf->current_way_number][inf->position_in_way], inf);
		}
	}
}

