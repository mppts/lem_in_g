#include "lem_in.h"

t_room			*bfs(t_room *source)
{
	t_link		*tmp_link;
	t_room		**line;
	int 		current_pos_in_line;
	int			current_addition_to_line;
	int			rooms_num;
	t_room		*find_sink;

	find_sink = NULL;
	current_addition_to_line = 1;
	current_pos_in_line = 0;
	rooms_num = rooms_calc(source);
	line = (t_room **)malloc(sizeof(t_room *) * (rooms_num + 1));
	line[rooms_num] = NULL;
	line[current_pos_in_line] = source;
	while (current_pos_in_line < rooms_num)
	{
		tmp_link = line[current_pos_in_line]->linked_to;
		while (tmp_link)
		{
			if (tmp_link->to->level == 0 && tmp_link->to != source)
			{
				if (!find_sink && tmp_link->to->is_start_or_end == SINK)
					find_sink = tmp_link->to;
				line[current_addition_to_line++] = tmp_link->to;
				tmp_link->to->level = line[current_pos_in_line]->level + 1;
			}
			tmp_link = tmp_link->next;
		}
		current_pos_in_line++;
	}
	free(line);
	return (find_sink);
}