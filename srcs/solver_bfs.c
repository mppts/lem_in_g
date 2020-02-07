#include "lem_in.h"

void			print_result(t_room **line, int size_of_line)
{
	u_int64_t	level;
	int			i;

	i = 0;
	level = 0;
	while (i < size_of_line)
	{
		ft_putstr("level ");
		ft_putnbr(level);
		ft_putstr(":   ");
		while (i < size_of_line && line[i]->level == level)
		{
			ft_putstr(line[i++]->name);
			ft_putstr("  ");
		}
		level++;
		ft_putstr("\n");
	}
}

t_room			*bfs(t_room *sink, t_map *map)
{
	t_link		*tmp_link;
	t_room		**line;
	int 		current_pos_in_line;
	int			current_addition_to_line;
	int			rooms_num;
	t_room		*find_source;

	if (!sink)
		return (NULL);
	find_source = NULL;
	current_addition_to_line = 1;
	current_pos_in_line = 0;
	rooms_num = rooms_calc(sink);
	line = (t_room **)malloc(sizeof(t_room *) * (rooms_num + 1));
	line[rooms_num] = NULL;
	line[current_pos_in_line] = sink;
	while (current_pos_in_line < rooms_num)
	{
		tmp_link = line[current_pos_in_line]->linked_to;
		while (tmp_link)
		{
			if (tmp_link->to->level == 0 && tmp_link->to != sink)
			{
				if (!find_source && (tmp_link->to == map->room_start))
					find_source = tmp_link->to;
				line[current_addition_to_line++] = tmp_link->to;
				tmp_link->to->level = line[current_pos_in_line]->level + 1;
			}
			tmp_link = tmp_link->next;
		}
		current_pos_in_line++;
	}
//	print_result(line, rooms_calc(sink));
	free(line);
	return (find_source);
}