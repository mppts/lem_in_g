
#include "lem_in.h"

int				conditions_checking_e_s(t_map *map, t_link *tmp_link, t_room *room)
{
	if (!room->room_from_we_came && room != map->fin)
		return (0);
	if (!tmp_link->mirror->flow && tmp_link->to != room->room_from_we_came && tmp_link->to != map->fin &&
		(tmp_link->to->way_number == room->way_number ||
		 (tmp_link->to->way_number != room->way_number &&
		  room->room_from_we_came->way_number == room->way_number) ||
		 (room->way_number !=  tmp_link->to->way_number &&
		  room->room_from_we_came->way_number != -1 && tmp_link->to->way_number == -1)))
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
		tmp = tmp->room_from_we_came;
	}
	if (!tmp)
		return (NULL);
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

	do_we_have_a_change = 1;
	while (do_we_have_a_change)
	{
		tmp_room = map->fin;
		do_we_have_a_change = 0;
		indicator = 0;
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
