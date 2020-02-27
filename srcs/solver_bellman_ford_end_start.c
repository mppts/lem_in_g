#include "lem_in.h"

int				has_way_to_same_way_e_s(t_room *room)
{
	t_link		*tmp;

	tmp = room->linked_to;
	if (room->way_number == -1)
		return (1);
	while (tmp)
	{
		if (tmp->to->way_number == room->way_number && tmp->flow && !tmp->mirror->flow)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				conditions_checking_e_s(t_map *map, t_link *tmp_link, t_room *room)
{
	int			indicator;

	if (!room->room_from_we_came && room != map->fin)
		return (0);
	if (room == map->fin && !tmp_link->mirror->flow)
		return (1);
	if (!tmp_link->mirror->flow && tmp_link->to != room->room_from_we_came && tmp_link->to != map->fin &&
		(room->way_number == tmp_link->to->way_number ||

		(room->way_number != tmp_link->to->way_number && room->room_from_we_came->way_number == room->way_number &&
		 (indicator = has_way_to_same_way_e_s(tmp_link->to))) ||

		(room->way_number != tmp_link->to->way_number && room->way_number == -1 && indicator)))
		 return (1);
	return (0);
}

void			work_with_links_e_s(t_map *map, t_room *room, char *do_we_have_a_change)
{
	t_link		*tmp;

	tmp = room->linked_to;
	while (tmp)
	{
		if (conditions_checking_e_s(map, tmp, room))
		{
			if (tmp->flow)
			{
				if (!tmp->to->level_rev || room->level_rev - 1 < tmp->to->level_rev)
				{
					tmp->to->level_rev = room->level_rev - 1;
					tmp->to->room_from_we_came = room;
					(*do_we_have_a_change)++;
				}
			}
			else
			{
				if (!tmp->to->level_rev || room->level_rev + 1 < tmp->to->level_rev)
				{
					tmp->to->level_rev = room->level_rev + 1;
					tmp->to->room_from_we_came = room;
					(*do_we_have_a_change)++;
				}
			}
		}
		tmp = tmp->next;
	}
}

t_room			*find_way_on_fork_e_s(t_room *room, t_room *room_prev)
{
	t_link		*link;

	link = room->linked_to;
	while (link)
	{
		if (link->to != room_prev && (link->to->level_rev - 1 == room->level_rev ||
				link->to->level_rev + 1 == room->level_rev))
			return (link->to);
		link = link->next;
	}
	return (NULL);
}

t_room			*find_way_bf_e_s(t_map *map, t_room **line)
{
	int			i;
	int			k;
	t_room		*tmp;
	t_room		**tmp_line;

	i = 0;
	tmp_line = (t_room **)malloc(sizeof(t_room) * (map->num_nodes + 1));
	tmp = map->start;
	while (tmp && tmp != map->fin)
	{
		tmp_line[i++] = tmp;
		if (tmp->room_from_we_came && (tmp->room_from_we_came->level_rev - 1 == tmp->level_rev||
				tmp->room_from_we_came->level_rev + 1 == tmp->level_rev))
			tmp = tmp->room_from_we_came;
		else
			tmp = find_way_on_fork_e_s(tmp, tmp_line[i - 2]);
	}
	if (!tmp)
	{
		free(tmp_line);
		return (NULL);
	}
	tmp_line[i] = tmp;
	k = i;
	while (i >= 0)
		line[k--] = tmp_line[i--];
	free(tmp_line);
	if (line[0] == map->start)
		return (line[0]);
	return (NULL);
}

int				bellman_ford_rev(t_map *map, t_room **line, t_graph_inf *inf)
{
	t_room		*tmp_room;
	char		do_we_have_a_change;
	int			indicator;
	int			cycles;

	do_we_have_a_change = 1;
	cycles = 0;
	while (do_we_have_a_change)
	{
		tmp_room = map->fin;
		do_we_have_a_change = 0;
		indicator = 0;
		cycles++;
		if (cycles > map->num_nodes + 2)
			break ;
		while (!indicator || tmp_room != map->fin)
		{
			if (tmp_room != map->start)
				work_with_links_e_s(map, tmp_room, &do_we_have_a_change);
			tmp_room = tmp_room->next;
			indicator++;
		}
	}
	if (find_way_bf_e_s(map, line))
		return (1);
	return (0);
}
