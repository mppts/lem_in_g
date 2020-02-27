#include <lem_in.h>

int			find_num_of_ways(t_map *map)
{
	int		links_start;
	int		links_end;
	t_link	*tmp;

	links_end = 0;
	links_start = 0;
	tmp = map->start->linked_to;
	while (tmp)
	{
		links_start++;
		tmp = tmp->next;
	}
	tmp = map->fin->linked_to;
	while (tmp)
	{
		links_end++;
		tmp = tmp->next;
	}
	if (links_end > links_start)
		return (links_end);
	return (links_start);
}

void		put_zero_to_flows(t_room *source)
{
	t_room	*tmp_r;
	t_link	*tmp_link;

	tmp_link = source->linked_to;
	source->way_number = -1;
	source->level = 0;
	while  (tmp_link)
	{
		tmp_link->flow = 0;
		tmp_link = tmp_link->next;
	}
	tmp_r = source->next;
	while (tmp_r != source)
	{
		tmp_r->level = 0;
		tmp_r->way_number = -1;
		tmp_link = tmp_r->linked_to;
		while  (tmp_link)
		{
			tmp_link->flow = 0;
			tmp_link = tmp_link->next;
		}
		tmp_r = tmp_r->next;
	}
}

void	 		put_null_to_precessor(t_map *map)
{
	t_room		*tmp;
	int			indicator;

	tmp = map->start;
	indicator = 0;
	while (!indicator || tmp != map->start)
	{
		tmp->level_rev = 0;
		tmp->room_from_we_came = NULL;
		tmp = tmp->next;
		indicator++;
	}
}

void			initialization(t_map *map, t_graph_inf	*inf)
{
	int i;

	i = 0;
	inf->max_ways = find_num_of_ways(map);
	inf->ways = malloc(sizeof(t_way *) * (inf->max_ways + 1));
	inf->current_way_number = 0;
	inf->total_ways_len = 0;
	inf->are_enough_ways_current = 0;
	inf->are_enough_ways_new = 0;
	inf->common_rooms = malloc(sizeof(t_room *) * (map->num_nodes + 1));
	while (i <= inf->max_ways)
		inf->ways[i++] = NULL;
	i = 0;
	while (i <= map->num_nodes)
		inf->common_rooms[i++] = NULL;
	put_zero_to_flows(map->room_start);
	put_null_to_precessor(map);
	map->path = NULL;
}

t_path			*add_one_way(int i, t_graph_inf *inf, t_map *map)
{
	t_path		*tmp;
	t_way 		*way_in_list;
	int			room;

	room = 0;
	tmp = (t_path *)malloc(sizeof(t_path));
	tmp->next = NULL;
	tmp->len = inf->ways[i]->way_len;
	tmp->path = (t_room **)malloc(sizeof(t_room *) * (inf->ways[i]->way_len));
	tmp->path[inf->ways[i]->way_len] = NULL;
	tmp->ants = map->ants;
	way_in_list = inf->ways[i];
	while (room < inf->ways[i]->way_len)
	{
		tmp->path[room++] = way_in_list->room;
		way_in_list = way_in_list->next;
	}
	return (tmp);
}

void			put_ways_to_map(t_graph_inf *inf, t_map *map)
{
	int			i;
	t_path		*path;

	i = 0;
	map->path = add_one_way(i, inf, map);
	i++;
	path = map->path;
	while (inf->ways[i])
	{
		path->next = add_one_way(i, inf, map);
		path = path->next;
		i++;
	}
}

void			free_way(t_way *way)
{
	t_way		*tmp;

	while (way)
	{
		tmp = way;
		way = way->next;
		free(tmp);
		tmp = NULL;
	}
}

void			free_inf_content(t_graph_inf *inf)
{
	int			i;

	i = 0;
	while (inf->ways[i])
		free_way(inf->ways[i++]);
	free(inf->ways);
	free(inf->common_rooms);
	inf->ways = NULL;
	inf->common_rooms = NULL;
}

void			solver(t_map *map)
{
	t_graph_inf	inf;

	initialization(map, &inf);
	algo(map, &inf);
	if (inf.ways[0])
		put_ways_to_map(&inf, map);
	free_inf_content(&inf);
}