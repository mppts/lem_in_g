#include "lem_in.h"

static void		add_mirror_links(t_link *link, t_graph_inf *inf)
{
	int			i;

	i = inf->two_flows;
	inf->mirror_links[i] = link;
	inf->mirror_links[i + 1] = link->mirror;
	inf->two_flows += 2;
}

void 		find_min_white_gray(t_link	*link, t_graph_inf *inf, t_link	**tmp_white, t_link	**tmp_gray)
{
	if (link->to->num_linked_to == 1 || link->to->color == BLACK)
	{
		link->to->color = BLACK;
		return ;
	}
	else if (link->flow)
		return ;
	else if (link->to != inf->ways[inf->current_way_number][inf->current_pos_in_way - 1])
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

	tmp_white = NULL;
	tmp_gray = NULL;
	link = room->linked_to;
	while (link)
	{
		if (link->to != inf->ways[inf->current_way_number][inf->current_pos_in_way - 1] && link->flow == 0)
			find_min_white_gray(link, inf, &tmp_white, &tmp_gray);
		link = link->next;
	}
	link = NULL;
	if (tmp_white && tmp_gray)
		link = ((tmp_white->to->level) <= (tmp_gray->to->level)) ? tmp_white : tmp_gray;
	else if (tmp_gray && !tmp_white)
		link = tmp_gray;
	else if (!tmp_gray && tmp_white)
		link = tmp_white;
	if (link)
	{
		link->flow = 1;
		return (link->to);
	}
	return (NULL);
}

t_link		*find_link_with_mirror_flow(t_room *to)
{
	t_link	*tmp;

	tmp = to->linked_to;
	while(tmp)
	{
		if (tmp->mirror->flow)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room		*find_vertex_from_gray(t_room *room, t_graph_inf *inf, t_map *map)
{
	t_link	*link;
	t_link	*tmp_white;
	t_link	*tmp_gray;

	tmp_white = NULL;
	tmp_gray = NULL;
	link = room->linked_to;
	/*
	while (link)
	{
		find_min_white_gray(link, inf, &tmp_white, &tmp_gray);
		link = link->next;
	}
	if (tmp_white && tmp_gray)
	link = tmp_white->to->level > tmp_gray->to->level ? tmp_gray : tmp_white;
	else if (tmp_white && !tmp_gray)
		link = tmp_white;
	else if (!tmp_white && tmp_gray)
		link = tmp_gray;
	else
		return (NULL);
	if (link->mirror->flow)
		link->mirror->flow = 0;
	return (link->to);
	*/
	if((tmp_gray = find_link_with_mirror_flow(room)))
	{
		//add_mirror_links(tmp_gray, inf);
		tmp_gray->mirror->flow = 0;
		return (tmp_gray->to);
	}

}

int 		push_vertex(t_room *room, t_graph_inf *inf, t_map *map)
{
	if (room->color == GRAY)
	{
		find_vertex_from_gray(room, inf, map);
		return (1);
	}
	else if (room->color == WHITE)
	{
		if (room != map->start)
			room->color = GRAY;
		inf->ways[inf->current_way_number][inf->current_pos_in_way] = find_vertex(room, inf, map);
		return (0);
	}
	else
	{
		inf->ways[inf->current_way_number][inf->current_pos_in_way - 1] = NULL;
		inf->current_pos_in_way--;
		return (0);
	}
}

int			dfs(t_room *start, t_graph_inf *inf, t_map *map)
{
	inf->current_pos_in_way = 0;
	inf->ways[inf->current_way_number][inf->current_pos_in_way] = start;
	while (inf->ways[inf->current_way_number][inf->current_pos_in_way] && inf->ways[inf->current_way_number][inf->current_pos_in_way] != map->fin)
	{
		inf->current_pos_in_way++;
		if (push_vertex(inf->ways[inf->current_way_number][inf->current_pos_in_way - 1], inf, map) || inf->current_pos_in_way < 1)
			return (0);
		if (inf->ways[inf->current_way_number][inf->current_pos_in_way] == NULL && inf->current_pos_in_way > 1)
			inf->current_pos_in_way -= 2;
	}
	if (inf->ways[inf->current_way_number][inf->current_pos_in_way] == NULL)
		return (0);
	else
		return (1);
}


void		find_min_lev_m_pot_vertex(t_graph_inf *inf, t_link *link, t_link **min)
{
	if (link->to->num_linked_to == 1 || link->to->color == BLACK)
	{
		link->to->color = BLACK;
		return ;
	}
	else if (link->flow)
		return ;
	else if (link->to != inf->ways[inf->current_way_number][inf->current_pos_in_way - 2])
	{
		if (*min == NULL)
			*min = link;
		else
			*min = link->to->lev_m_pot < (*min)->to->lev_m_pot ? link : *min;
	}
}

t_room		*find_vertex_pl(t_room *room, t_graph_inf *inf, t_map *map)
{
	t_link	*link;
	t_link	*tmp_min;

	tmp_min = NULL;
	link = room->linked_to;
	while (link)
	{
		if (link->to != inf->ways[inf->current_way_number][inf->current_pos_in_way - 2] && link->flow == 0)
			find_min_lev_m_pot_vertex(inf, link,  &tmp_min);
		link = link->next;
	}
	if (tmp_min)
	{
		if (tmp_min->mirror->flow)
		{
			add_mirror_links(tmp_min, inf);
			return (NULL);
		}
		else
			tmp_min->flow = 1;
		return (tmp_min->to);
	}
	return (NULL);
}

int 		push_vertex_pl(t_room *room, t_graph_inf *inf, t_map *map)
{
	if (room->color == GRAY)
	{
		inf->ways[inf->current_way_number][inf->current_pos_in_way] = find_vertex_from_gray(room, inf, map);
		return (0);
	}
	else if (room->color == WHITE)
	{
		if (room != map->start)
			room->color = GRAY;
		if ((inf->ways[inf->current_way_number][inf->current_pos_in_way] = find_vertex_pl(room, inf, map)))
			return (0);
		else
			return (1);
	}
	else
	{
		inf->ways[inf->current_way_number][inf->current_pos_in_way - 1] = NULL;
		inf->current_pos_in_way--;
		return (0);
	}
}

int			dfs_pl(t_room *start, t_graph_inf *inf, t_map *map)
{
	inf->current_pos_in_way = 0;
	inf->ways[inf->current_way_number][inf->current_pos_in_way] = start;
	while (inf->ways[inf->current_way_number][inf->current_pos_in_way] && inf->ways[inf->current_way_number][inf->current_pos_in_way] != map->fin)
	{
		inf->current_pos_in_way++;
		if (push_vertex_pl(inf->ways[inf->current_way_number][inf->current_pos_in_way - 1], inf, map) || inf->current_pos_in_way < 1)
			return (0);
		if (inf->ways[inf->current_way_number][inf->current_pos_in_way] == NULL && inf->current_pos_in_way > 1)
			inf->current_pos_in_way -= 2;
	}
	if (inf->ways[inf->current_way_number][inf->current_pos_in_way] == NULL)
		return (0);
	else
		return (1);
}

