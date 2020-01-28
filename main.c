#include "lem_in.h"

int 			check_if_not_nmbrs(char **splt, int coord)
{
	size_t 		l;

	l = 0;
	while(splt[coord][l] != '\0')
	{
		if (!ft_isdigit(splt[coord][l]))
			return (1);
		l++;
	}
	return (0);
}

void			set_flag(t_room *new,t_flag *flag)
{
	if (flag->flag_start && !flag->flag_end)
		new->type = 1;
	else if(!flag->flag_start && flag->flag_end)
		new->type = 2;
	else if(flag->flag_start && flag->flag_end)
		new->type = 3;
	else
		new->type = 0;
	flag->flag_end = 0;
	flag->flag_start = 0;
}

t_room			*new_room(char **splt, t_flag *flag, int64_t id)
{
	t_room		*new;
	int64_t 	coord_x;
	int64_t 	coord_y;

	if(!(new = (t_room*)malloc(sizeof(t_room))))
		man_err("Error", NULL, NULL);//memory managenment
	set_flag(new, flag);
	ft_strcpy(new->name, splt[0]);
	if (check_if_not_nmbrs(splt, 1) || check_if_not_nmbrs(splt, 2))
		man_err("Error", NULL, NULL);//memory managenment
	coord_x = ft_atoli(splt[1]);
	coord_y = ft_atoli(splt[2]);
	if (coord_x > INT32_MAX || coord_y > INT32_MAX ||
	coord_x < INT32_MIN || coord_y < INT32_MIN)
		man_err("Error", NULL, NULL);//memory managenment
	new->x = coord_x;
	new->y = coord_y;
	new->id = id;
	new->linked_to = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->num_linked_to = 0;
	new->level = -1;
	return (new);
}

void			link_rooms(t_map *map, t_room *new)
{
	if (map->num_nodes == 0)
	{
		map->room_start = new;
		map->room_end = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		map->room_end->next = new;
		new->prev = map->room_end;
		new->next = map->room_start;
		map->room_start->prev = map->room_end;
		map->room_end = new;
	}
}

int				check_room_name(char *buf, t_map *map)
{
	t_room		*tmp;

	tmp = map->room_start;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, buf))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			add_room(char *buf, t_flag *flag, t_map *map)
{
	int64_t 	num;
	t_room		*new;

	map->splt = ft_strsplit(buf, ' ');
	num = 0;
	while (num + map->splt != NULL)
		num++;
	if (num != 2)
	{
		ft_del_splitter(map->splt);
		man_err("Error", NULL, NULL);
	}
	if (check_room_name(buf, map))
		new = new_room(map->splt, flag, map->num_nodes);
	if (flag->flag_start && !flag->flag_end)
		map->start = new;
	else if (!flag->flag_start && flag->flag_end)
		map->fin = new;
	else if (flag->flag_start && flag->flag_end)
		case_in_and_out(map);
	link_rooms(map, new);
	ft_del_splitter(map->splt);
}

void			del_hashed_rooms(t_map *map)
{
	if (map && map->hashed_rooms)
		free(map->hashed_rooms);
}

uint64_t 		get_hash(char *str, uint64_t size)
{
	uint64_t hash;
	uint64_t c;

	hash = 5381UL;
	while (*str)
		hash = ((hash << 5UL) + hash) + *str++; /* hash * 33 + c */
	return (hash / size);
}

void			hash_rooms(t_map *map)
{
	t_room		**hashed_rooms;
	t_room		*tmp;
	uint64_t	num;

	hashed_rooms = (t_room**)malloc(map->num_nodes * sizeof(t_room*));
	map->hashed_rooms = hashed_rooms;
	num = 0;
	while (num < map->num_nodes)
		hashed_rooms[num++] = NULL;
	tmp = map->room_start;
	while (tmp != map->room_end)
	{
		tmp->hash = get_hash(tmp->name, map->num_nodes);
		num = 0;
		while (hashed_rooms[tmp->hash + num] && num < map->num_nodes)
			if (++num == map->num_nodes)
				num = 0;
		hashed_rooms[tmp->hash + num] = tmp;
		tmp->hash_id = tmp->hash + num;
		tmp = tmp->next;
	}
	if (map->room_end == map->room_start)
		map->room_start->hash = get_hash(map->room_start->name, map->num_nodes);
	map->is_rooms_hashed = TRUE;
}

t_room			*find_hashed_room(t_map *map, char *name)
{
	uint64_t 	hash;
	uint64_t 	loop;

	hash = get_hash(name, map->num_nodes);
	loop = 0;
	while (!ft_strcmp(map->hashed_rooms[hash]->name, name))
	{
		hash++;
		if (hash == map->num_nodes)
		{
			hash = 0;
			loop++;
		}
		if (loop > 1)
			break ;
	}
	if (loop > 1)
		return (NULL);
	return (map->hashed_rooms[hash]);
}

void			add_link_to_room(t_room *from, t_room *to)
{
	t_link		*new;
	t_link		*tmp;

	if ((new = (t_link*)malloc(sizeof(t_link))))
		man_err("Error\n", NULL, NULL);
	new->to = to;
	new->next = NULL;
	new->path_id = 0;
	if (!from->linked_to)
		from->linked_to = new;
	else
	{
		tmp = from->linked_to;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	from->num_linked_to++;
}

int 			error_in_link(t_map *map, t_room *from, t_room *to)
{
	t_link		*tmp;
	if (from == to)
		return (1);
	tmp = from->linked_to;
	while(tmp)
	{
		if (tmp->to == to)
			return (1);
		tmp = tmp->next;
	}
	tmp = to->linked_to;
	while(tmp)
	{
		if (tmp->to == from)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			add_link(char *buf, t_map *map)
{
	int64_t 	num;
	t_room		*from;
	t_room		*to;

	map->splt = ft_strsplit(buf, '-');
	num = 0;
	while (num + map->splt != NULL)
		num++;
	if (num != 1)
	{
		ft_del_splitter(map->splt);
		man_err_map("Error\n", NULL, NULL. map);
	}
	if (!(from = find_hashed_room(map, map->splt[0])))
		man_err("Error\n", NULL, NULL);
	if (!(to = find_hashed_room(map, map->splt[1])))
		man_err("Error\n", NULL, NULL);
	if (error_in_link(map, from, to))
		man_err("Error\n", NULL, NULL);
	add_link_to_room(from, to);
	add_link_to_room(to, from);
}

void			add_room_or_path(char *buf,int *flag, t_map *map)
{
	if (ft_strchr(buf, ' '))
	{
		add_room(buf, flag, map);
		map->num_nodes++;
	}
	else if (ft_strchr(buf, '-'))
	{
		if (!map->is_rooms_hashed)
			hash_rooms(map);
		add_link(buf, map);
		map->num_links++;
	}
	else
		man_err("Error\n", NULL, NULL);
}


static void		parse_line(char *buf, t_flag *flag, t_map *map)
{

	if (*buf == '#')
	{
		if (!ft_strcmp(buf, "##start"))
			flag->flag_start = 1;
		else if (!ft_strcmp(buf, "##end"))
			flag->flag_end = 1;
	}
	else if (*buf != 'L')
		add_room_or_path(buf, flag, map);
}

void			parse_map(t_map *map)
{
	char		*buf;
	t_flag 		flag;

	flag.flag_end = 0;
	flag.flag_start = 0;
	while (get_next_line(1, &buf))
	{
		parse_line(buf, &flag, map);
		free(buf);
	}
}

void			parse_ants(t_map *map)
{
	char 		*buf;
	u_int64_t	ants;

	while (get_next_line(1, &buf))
	{
		if (*buf != '#')
			break ;
		free(buf);
	}
	if (!ft_isdigit(*buf))
		man_err("Error\n", buf, ft_memdel);
	ants = ft_atoli(buf);
	if (ants < 0 || ants >= INT32_MAX)
		man_err("Error\n", buf, ft_memdel);
	free(buf);
}

int			main(int ac, char *av[])
{
	t_map	map;

	map.num_links = 0;
	map.num_nodes = 0;
	map.is_rooms_hashed = FALSE;
	//parse input
	// parse ants
	parse_ants(&map);
	// parse map
	parse_map(&map);
	//algorithm processing
	//output
	// VISUALIZATION??
	return 0;
}