#include <lem_in.h>

int		compare_ways(t_room **way_1, t_room **way_2)
{
	int	one;
	int	two;

	if (!way_1[1] && !way_2[1])
		return (0);
	if (!way_2[1])
		return (1);
	one = 0;
	two = 0;
	while (way_1[one])
		one++;
	while (way_2[two])
		two++;
	if (one <= two)
	{
		while (one >= 0)
			way_2[one--] = NULL;
		return (1);
	}
	while (one >= 0)
		way_1[one--] = NULL;
	one = 0;
	while (way_2[one])
	{
		way_1[one] = way_2[one];
		one++;
	}
	while (one >= 0)
		way_2[one--] = NULL;
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

int		find_best_current_way(t_map *map, t_room **way_1, t_room **way_2, t_graph_inf *inf)
{
	bellman_ford(map, way_1, inf);
	clear_precessors(map);
	bellman_ford_rev(map, way_2, inf);
	if (!compare_ways(way_1, way_2))
		return (0);
	return (1);
}