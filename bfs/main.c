#include "lem_in.h"

t_room			*make_graph(void)
{
	/*
	 * so: A B
	 * A: so C
	 * B: so D
	 * C: A si
	 * D: B si
	 * si: C so D*/
	//rooms
	t_room *source = malloc(sizeof(t_room));
	t_room *room_a = malloc(sizeof(t_room));
	t_room *room_b = malloc(sizeof(t_room));
	t_room *room_c = malloc(sizeof(t_room));
	t_room *room_d = malloc(sizeof(t_room));
	t_room *sink = malloc(sizeof(t_room));


	//links
	t_link *source_sink = malloc(sizeof(t_link));
	t_link *sink_source = malloc(sizeof(t_link));
	t_link *source_a = malloc(sizeof(t_link));
	t_link *a_source = malloc(sizeof(t_link));
	t_link *source_b = malloc(sizeof(t_link));
	t_link *b_source = malloc(sizeof(t_link));
	t_link *a_c = malloc(sizeof(t_link));
	t_link *c_a = malloc(sizeof(t_link));
	t_link *b_d = malloc(sizeof(t_link));
	t_link *d_b = malloc(sizeof(t_link));
	t_link *c_sink = malloc(sizeof(t_link));
	t_link *sink_c = malloc(sizeof(t_link));
	t_link *d_sink = malloc(sizeof(t_link));
	t_link *sink_d = malloc(sizeof(t_link));


	//vertical links
	source->next = room_a;
	source->prev = sink;
	source->name = malloc(7);
	source->name[0] = 's';
	source->name[1] = 'o';
	source->name[2] = 'u';
	source->name[3] = 'r';
	source->name[4] = 'c';
	source->name[5] = 'e';
	source->name[6] = '\0';
	source->is_start_or_end = 1;
	source->color = WHITE;



	room_a->next = room_b;
	room_a->prev = source;
	room_a->name = malloc(2);
	room_a->name[0] = 'a';
	room_a->name[1] = '\0';
	room_a->is_start_or_end = 0;
	room_a->color = WHITE;

	room_b->next = room_c;
	room_b->prev = room_a;
	room_b->name = malloc(2);
	room_b->name[0] = 'b';
	room_b->name[1] = '\0';
	room_b->is_start_or_end = 0;
	room_b->color = WHITE;

	room_c->next = room_d;
	room_c->prev = room_b;
	room_c->name = malloc(2);
	room_c->name[0] = 'c';
	room_c->name[1] = '\0';
	room_c->is_start_or_end = 0;
	room_c->color = WHITE;

	room_d->next = sink;
	room_d->prev = room_c;
	room_d->name = malloc(2);
	room_d->name[0] = 'd';
	room_d->name[1] = '\0';
	room_d->is_start_or_end = 0;
	room_d->color = WHITE;

	sink->next = source;
	sink->prev = room_d;
	sink->name = malloc(5);
	sink->name[0] = 's';
	sink->name[1] = 'i';
	sink->name[2] = 'n';
	sink->name[3] = 'k';
	sink->name[4] = '\0';
	sink->is_start_or_end = 2;
	sink->color = WHITE;

	//add levels;
	source->level = 0;
	room_a->level = 0;
	room_b->level = 0;
	room_c->level = 0;
	room_d->level = 0;
	sink->level = 0;

	//horizontal links
	source->linked_to = source_sink;
	source_sink->from = source;
	source_sink->mirror_link = sink_source;
	source_sink->next = source_a;
	source_sink->prev = NULL;
	source_a->mirror_link = a_source;
	source_a->next = source_b;
	source_a->prev = source_sink;
	source_b->mirror_link = b_source;
	source_b->next = NULL;
	source_b->prev = source_a;
	source_sink->to = sink;
	source_a->to = room_a;
	source_a->from = source;
	source_b->to = room_b;
	source_b->from = source;



	room_a->linked_to = a_c;
	a_c->mirror_link = c_a;
	a_c->to = room_c;
	a_c->from = room_a;
	a_c->next = a_source;
	a_c->prev = NULL;
	a_source->mirror_link = source_a;
	a_source->to = source;
	a_source->from = room_a;
	a_source->next = NULL;
	a_source->prev = a_c;


	room_b->linked_to = b_d;
	b_d->mirror_link = d_b;
	b_d->to = room_d;
	b_d->from = room_b;
	b_d->next = b_source;
	b_d->prev = NULL;
	b_source->mirror_link = source_b;
	b_source->to = source;
	b_source->from = room_b;
	b_source->next = NULL;
	b_source->prev = b_d;



	room_c->linked_to = c_sink;
	c_sink->mirror_link = sink_c;
	c_sink->to = sink;
	c_sink->from = room_c;
	c_sink->next = c_a;
	c_sink->prev = NULL;
	c_a->mirror_link = a_c;
	c_a->to = room_a;
	c_a->from = room_c;
	c_a->next = NULL;
	c_a->prev = c_sink;



	room_d->linked_to = d_sink;
	d_sink->mirror_link = sink_d;
	d_sink->to = sink;
	d_sink->from = room_d;
	d_sink->next = d_b;
	d_sink->prev = NULL;
	d_b->mirror_link = b_d;
	d_b->to = room_b;
	d_b->from = room_d;
	d_b->next = NULL;
	d_b->prev = d_sink;

	sink->linked_to = sink_c;
	sink_c->mirror_link = c_sink;
	sink_c->to = room_c;
	sink_c->from = sink;
	sink_c->next = sink_d;
	sink_c->prev = NULL;
	sink_d->mirror_link = d_sink;
	sink_d->to = room_d;
	sink_d->from = sink;
	sink_d->next = sink_source;
	sink_d->prev = sink_c;
	sink_source->mirror_link = source_sink;
	sink_source->to = source;
	sink_source->from = sink;
	sink_source->next = NULL;
	sink_source->prev = sink_d;


/*
 * so: A B
 * A: so D C
 * B: so C
 * C: A B si
 * D: A si
 * si: D C
 * */

//	/////rooms
//	t_room *source = malloc(sizeof(t_room));
//	t_room *room_a = malloc(sizeof(t_room));
//	t_room *room_b = malloc(sizeof(t_room));
//	t_room *room_c = malloc(sizeof(t_room));
//	t_room *room_d = malloc(sizeof(t_room));
//	t_room *sink = malloc(sizeof(t_room));
//
//
//	/////links
//	t_link *source_a = malloc(sizeof(t_link));
//	t_link *a_source = malloc(sizeof(t_link));
//	t_link *source_b = malloc(sizeof(t_link));
//	t_link *b_source = malloc(sizeof(t_link));
//	t_link *a_c = malloc(sizeof(t_link));
//	t_link *c_a = malloc(sizeof(t_link));
//	t_link *a_d = malloc(sizeof(t_link));
//	t_link *d_a = malloc(sizeof(t_link));
//	t_link *b_c = malloc(sizeof(t_link));
//	t_link *c_b = malloc(sizeof(t_link));
//	t_link *d_sink = malloc(sizeof(t_link));
//	t_link *sink_d = malloc(sizeof(t_link));
//	t_link *c_sink = malloc(sizeof(t_link));
//	t_link *sink_c = malloc(sizeof(t_link));
//
//
//	/////vertical links
//	source->next = room_a;
//	source->prev = sink;
//	source->name = malloc(7);
//	source->name[0] = 's';
//	source->name[1] = 'o';
//	source->name[2] = 'u';
//	source->name[3] = 'r';
//	source->name[4] = 'c';
//	source->name[5] = 'e';
//	source->name[6] = '\0';
//	source->is_start_or_end = 1;
//
//
//
//	room_a->next = room_b;
//	room_a->prev = source;
//	room_a->name = malloc(2);
//	room_a->name[0] = 'a';
//	room_a->name[1] = '\0';
//	room_a->is_start_or_end = 0;
//
//	room_b->next = room_c;
//	room_b->prev = room_a;
//	room_b->name = malloc(2);
//	room_b->name[0] = 'b';
//	room_b->name[1] = '\0';
//	room_b->is_start_or_end = 0;
//
//	room_c->next = room_d;
//	room_c->prev = room_b;
//	room_c->name = malloc(2);
//	room_c->name[0] = 'c';
//	room_c->name[1] = '\0';
//	room_c->is_start_or_end = 0;
//
//	room_d->next = sink;
//	room_d->prev = room_c;
//	room_d->name = malloc(2);
//	room_d->name[0] = 'd';
//	room_d->name[1] = '\0';
//	room_d->is_start_or_end = 0;
//
//	sink->next = source;
//	sink->prev = room_d;
//	sink->name = malloc(5);
//	sink->name[0] = 's';
//	sink->name[1] = 'i';
//	sink->name[2] = 'n';
//	sink->name[3] = 'k';
//	sink->name[4] = '\0';
//	sink->is_start_or_end = 2;
//
//	/////horizontal links
//	source->linked_to = source_a;
//	source_a->from = source;
//	source_a->mirror_link = a_source;
//	source_a->next = source_b;
//	source_a->prev = NULL;
//	source_b->mirror_link = b_source;
//	source_b->next = NULL;
//	source_b->prev = source_a;
//	source_a->to = room_a;
//	source_a->from = source;
//	source_b->to = room_b;
//	source_b->from = source;
//
//
//
//	room_a->linked_to = a_c;
//	a_c->mirror_link = c_a;
//	a_c->to = room_c;
//	a_c->from = room_a;
//	a_c->next = a_d;
//	a_c->prev = NULL;
//	a_d->mirror_link = d_a;
//	a_d->to = room_d;
//	a_d->from = room_a;
//	a_d->next = a_source;
//	a_d->prev = a_c;
//	a_source->mirror_link = source_a;
//	a_source->to = source;
//	a_source->from = room_a;
//	a_source->next = NULL;
//	a_source->prev = a_d;
//
//
//	room_b->linked_to = b_c;
//	b_c->mirror_link = c_b;
//	b_c->to = room_c;
//	b_c->from = room_b;
//	b_c->next = b_source;
//	b_c->prev = NULL;
//	b_source->mirror_link = source_b;
//	b_source->to = source;
//	b_source->from = room_b;
//	b_source->next = NULL;
//	b_source->prev = b_c;
//
//
//
//	room_c->linked_to = c_sink;
//	c_sink->mirror_link = sink_c;
//	c_sink->to = sink;
//	c_sink->from = room_c;
//	c_sink->next = c_a;
//	c_sink->prev = NULL;
//	c_a->mirror_link = a_c;
//	c_a->to = room_a;
//	c_a->from = room_c;
//	c_a->next = c_b;
//	c_a->prev = c_sink;
//	c_b->mirror_link = b_c;
//	c_b->to = room_b;
//	c_b->from = room_c;
//	c_b->next = NULL;
//	c_b->prev = c_a;
//
//
//	room_d->linked_to = d_sink;
//	d_sink->mirror_link = sink_d;
//	d_sink->to = sink;
//	d_sink->from = room_d;
//	d_sink->next = d_a;
//	d_sink->prev = NULL;
//	d_a->mirror_link = a_d;
//	d_a->to = room_a;
//	d_a->from = room_d;
//	d_a->next = NULL;
//	d_a->prev = d_sink;
//
//	sink->linked_to = sink_c;
//	sink_c->mirror_link = c_sink;
//	sink_c->to = room_c;
//	sink_c->from = sink;
//	sink_c->next = sink_d;
//	sink_c->prev = NULL;
//	sink_d->mirror_link = d_sink;
//	sink_d->to = room_d;
//	sink_d->from = sink;
//	sink_d->next = NULL;
//	sink_d->prev = sink_c;



	t_room	*tmp_r;
	t_link	*tmp_l;
	int		indicator;

	tmp_r = source;
	indicator = 0;
	while (!indicator || tmp_r != source)
	{
		tmp_r->color = WHITE;
		tmp_r->level = 0;
		tmp_r->way_length = 0;
		tmp_r->current_ant_name = 0;
		tmp_l = tmp_r->linked_to;
		while (tmp_l)
		{
			tmp_l->flow = 0;
			tmp_l = tmp_l->next;
		}
		ft_putchar('\n');
		tmp_r = tmp_r->next;
		indicator++;
	}


	return (source);
}

int				rooms_calc(t_room *source)
{
	t_room		*tmp_room;
	int			rooms_calc;

	if (!source)
		return (0);
	rooms_calc = 1;
	tmp_room = source->next;
	while (tmp_room != source)
	{
		rooms_calc++;
		tmp_room = tmp_room->next;
	}
	return (rooms_calc);
}

int				links_calc(t_room *source)
{
	t_link		*tmp_link;
	t_room		*tmp_room;
	int			link_calc;
	int			i;

	link_calc = 0;
	i = 0;
	tmp_room = source->next;
	while (tmp_room != source || !i)
	{
		tmp_link = tmp_room->linked_to;
		while (tmp_link)
		{
			link_calc++;
			tmp_link = tmp_link->next;
		}
		tmp_room = tmp_room->next;
		i++;
	}
	return (link_calc);
}

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

t_room			*bfs(t_room *sink)
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
				if (!find_source && (tmp_link->to->is_start_or_end == SOURCE || tmp_link->to->is_start_or_end == SOURCE_AND_SINK))
					find_source = tmp_link->to;
				line[current_addition_to_line++] = tmp_link->to;
				tmp_link->to->level = line[current_pos_in_line]->level + 1;
			}
			tmp_link = tmp_link->next;
		}
		current_pos_in_line++;
	}
	print_result(line, rooms_calc(sink));
	free(line);
	return (find_source);
}



void		print_list(t_room *source)
{
	t_room	*tmp_r;
	t_link	*tmp_l;
	int		indicator;

	tmp_r = source;
	indicator = 0;
	ft_putstr("\n\n");
	while (!indicator || tmp_r != source)
	{
		ft_putstr("room ~~~[");
		ft_putstr(tmp_r->name);
		ft_putstr("]~~~ linked to:  ");
		tmp_l = tmp_r->linked_to;
		while (tmp_l)
		{
			ft_putstr(tmp_l->to->name);
			ft_putstr("  ");
			tmp_l = tmp_l->next;
		}
		ft_putchar('\n');
		tmp_r = tmp_r->next;
		indicator++;
	}
}

t_room		***memory_for_ways(t_room *source, t_room ***ways)
{
	int		i;
	int		e;
	int		rooms;

	rooms = rooms_calc(source);
	i = 0;
	ways = (t_room ***)malloc(sizeof(t_room**) * (rooms + 1));
	ways[rooms] = NULL;
	while (i < rooms)
	{
		e = 0;
		ways[i] = (t_room **)malloc(sizeof(t_room *) * (rooms + 1));
		while (e <= rooms)
			ways[i][e++] = NULL;
		i++;
	}
	return (ways);
}

t_link 		**memory_for_mirror_links(t_room *source, t_link **mirror_links)
{
	int		links;
	int		i;

	links = links_calc(source);
	i = 0;
	mirror_links = malloc(sizeof(t_link) * (links + 1));
	mirror_links[links] = NULL;
	while (i < links)
		mirror_links[i++] = NULL;
	return (mirror_links);
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

void		make_color_white_again(t_room **way)
{
	int		i;

	i = 0;
	while (way[i])
		way[i++]->color = WHITE;
}

void		delite_mirror_links(t_graph_inf *inf)
{
	int		i;
	t_link	*tmp;

	i = 0;
	while (inf->mirror_links[i])
	{
		tmp = inf->mirror_links[i];
		if (!tmp->prev)
			tmp->from->linked_to = tmp->next;
		if (tmp->next)
			tmp->next->prev = NULL;
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		free(tmp);
		inf->mirror_links[i] = NULL;
		i++;
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

t_room		*find_sink(t_room *source)
{
	t_room	*sink;

	if (source->is_start_or_end == SOURCE_AND_SINK)
		return (source);
	sink = source->next;
	while (sink->is_start_or_end != SINK && sink != source)
		sink = sink->next;
	if (sink == source)
		return (NULL);
	else
		return (sink);
}

void		algo(t_room *source, t_graph_inf *inf)
{
	t_room	*sinkkkk;

	sinkkkk = find_sink(source);
	while (bfs(sinkkkk))
	{
		inf->two_flows = 0;
		inf->current_way_number = 0;
		inf->position_in_way = 1;
		inf->ways[inf->current_way_number][0] = source;
		while (dfs(source, inf))
		{
			make_color_white_again(inf->ways[inf->current_way_number]);
			inf->position_in_way = 1;
			(inf->current_way_number)++;
			inf->ways[inf->current_way_number][0] = source;
		}
		if (!inf->two_flows)
		{
			if (inf->ways[inf->current_way_number][0] == source && !inf->ways[inf->current_way_number][1])
				inf->ways[inf->current_way_number][0] = NULL;
			break ;
		}
		else
		{
			if (inf->mirror_links[0])
				delite_mirror_links(inf);
			clean_ways(inf->ways);
			clean_levels_and_flows(source);
		}
	}
}

void		free_ways(t_room ***ways, t_room *source)
{
	int		i;
	int		rooms;

	i = 0;
	rooms = rooms_calc(source);
	while (i < rooms)
		free(ways[i++]);
	free(ways);
}

void		free_links(t_link *link)
{
	t_link	*tmp;

	while (link)
	{
		tmp = link;
		link = link->next;
		free(tmp);
		tmp = NULL;
	}
}

void		free_source(t_room *source)
{
	t_room	*tmp_r;

	tmp_r = source->prev;
	while (tmp_r != source)
	{
		free(tmp_r->name);
		free_links(tmp_r->linked_to);
		tmp_r = tmp_r->prev;
		free(tmp_r->next);
		tmp_r->next = NULL;
	}
	free(tmp_r->name);
	free_links(tmp_r->linked_to);
	free(tmp_r);
	tmp_r = NULL;
}

void		print_ways(t_graph_inf	*inf)
{
	int 	i;

	inf->current_way_number = 0;
	ft_putchar('\n');
	ft_putstr("So... we found:\n");
	while (inf->ways[inf->current_way_number])
	{
		i = 0;
		while (inf->ways[inf->current_way_number][i])
		{
			ft_putstr((inf->ways[inf->current_way_number][i++])->name);
			ft_putstr("  ");
		}
		ft_putchar('\n');
		inf->current_way_number++;
	}
}

void		put_ways_lengths(t_room ***ways)
{
	int		x;
	int		y;

	y = 0;
	while (ways[y][0])
	{
		x = 0;
		while (ways[y][x])
			x++;
		ways[y][1]->way_length = x - 1;
		y++;
	}
}

int     	main(void)
{
	t_room		*source;
	t_graph_inf	inf;

    source = make_graph();
    inf.ways = memory_for_ways(source, inf.ways);
    inf.mirror_links = memory_for_mirror_links(source, inf.mirror_links);
    algo(source, &inf);
    print_ways(&inf);
    put_ways_lengths(inf.ways);
//	print(inf.ways, 5, 0, 0);
    free_ways(inf.ways, source);
    free(inf.mirror_links);
    free_source(source);
    return (0);
}