#include <lem_in.h>

void	copy_2_to_1(t_room **way_1, t_room **way_2)
{
	int	one;
	int	two;

	one = 0;
	two = 0;
	while (way_1[one])
		way_1[one++] = NULL;
	one = 0;
	while (way_2[two])
		way_1[one++] = way_2[two++];
	two = 0;
	while (way_2[two])
		way_2[two++] = NULL;
}

int		compare_ways(t_room **way_1, t_room **way_2)
{
	int	one;
	int	two;

	if (!way_1[1] && !way_2[1])
		return (0);
	else if (!way_2[1])
		return (1);
	else if (!way_1[1])
	{
		copy_2_to_1(way_1, way_2);
		return (1);
	}
	one = 0;
	two = 0;
	while (way_1[one])
		one++;
	while (way_2[two])
		two++;
	if (two < one)
		copy_2_to_1(way_1, way_2);
	else
	{
		while (two >= 0)
			way_2[two--] = NULL;
	}
	return (1);
}

void		clear_precessors(t_map *map)
{
	t_room	*tmp;
	int		indicator;

	tmp = map->start;
	indicator = 0;
	while (!indicator || tmp != map->start)
	{
		tmp->room_from_we_came = NULL;
		tmp = tmp->next;
		indicator++;
	}
}

void	check_common_rooms(t_map *map, t_room **way_1, t_graph_inf *inf)
{
	int common_rooms;
	int i;
	int	common_room_way;
	int	indicator;

	t_room *tmp;
	t_room *tmp2;

	i = 0;
	indicator = 0;
	while (way_1[i])
	{
		common_rooms = 0;
		common_room_way = way_1[1]->way_number;
		if (way_1[i]->way_number != common_room_way)
			common_room_way = way_1[i]->way_number;
		while (way_1[i]->way_number != way_1[1]->way_number && common_room_way == way_1[i]->way_number)
		{
			tmp = way_1[i];
			common_rooms++;
			i++;
			tmp2 = way_1[i];
		}
		if (common_rooms == 1)
		{
			indicator = 1;
			break ;
		}
		i++;
	}
	i = 0;
	if (indicator)
		while (way_1[i])
			way_1[i++] = NULL;
}

int		find_best_current_way(t_map *map, t_room **way_1, t_room **way_2, t_graph_inf *inf)
{
	bellman_ford(map, way_1, inf);
//	check_common_rooms(map, way_1, inf); ///// Дописать/переписать на свежую голову
	clear_precessors(map);
	bellman_ford_rev(map, way_2, inf);
//	check_common_rooms(map, way_2, inf);
	if (!compare_ways(way_1, way_2))
		return (0);
	return (1);
}