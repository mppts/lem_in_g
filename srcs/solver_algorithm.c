#include "lem_in.h"

void		delite_mirror_links(t_graph_inf *inf)
{
	int		i;
	t_link	*tmp;

	i = 0;
	while (inf->mirror_links[i])
	{
		tmp = inf->mirror_links[i];
		if (!tmp->prev)
			tmp->mirror->to->linked_to = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		free(tmp);
		inf->mirror_links[i] = NULL;
		i++;
	}
}

void		clean_ways(t_room ***ways)
{
	int 	y;
	int		x;

	y = 0;
	while (ways[y])
	{
		x = 0;
		while (ways[y][x])
			ways[y][x++] = NULL;
		y++;
	}
}

void		clean_levels_and_flows(t_room *source)
{
	t_room	*tmp;
	t_link	*tmp_l;

	tmp = source->next;
	source->level = 0;
	tmp_l = source->linked_to;
	while (tmp_l)
	{
		tmp_l->flow = 0;
		tmp_l = tmp_l->next;
	}
	while (tmp != source)
	{
		tmp->level = 0;
		tmp_l = tmp->linked_to;
		while (tmp_l)
		{
			tmp_l->flow = 0;
			tmp_l = tmp_l->next;
		}
		tmp = tmp->next;
	}
}

void		clean_links_to_gray_dots(t_link **link)
{
	int		i;

	i = 0;
	while (link[i])
		link[i++] = NULL;
}

void		time_to_do_some_cleaning(t_map *map, t_graph_inf *inf)
{
	if (inf->mirror_links[0])
		delite_mirror_links(inf);
	make_color_white_again(map->start);
	clean_ways(inf->ways);
	clean_levels_and_flows(map->start);
	clean_links_to_gray_dots(inf->links_to_gray_dot);
}

void		algo(t_map *map, t_graph_inf *inf)
{
	while (bfs(map->fin, map))
	{
		inf->two_flows = 0;
		inf->current_way_number = 0;
		inf->position_in_way = 1;
		inf->ways[inf->current_way_number][0] = map->start;
		while ((dfs(map->start, inf, map)))
		{
			inf->position_in_way = 1;
			(inf->current_way_number)++;
			inf->ways[inf->current_way_number][0] = map->start;
		}
		if (!inf->two_flows)
		{
			if (inf->ways[inf->current_way_number][0] == map->start && !inf->ways[inf->current_way_number][1])
				inf->ways[inf->current_way_number][0] = NULL;
			break ;
		}
		else
			time_to_do_some_cleaning(map, inf);
	}
}

