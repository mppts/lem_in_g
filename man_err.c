#include <lem_in.h>

void			ft_del_splitter(char **pocket)
{
	if (!pocket)
		return ;
	while (*pocket)
	{
		free(*pocket);
		pocket++;
	}
	free(pocket);
}

void		ft_delroom(t_room *room)
{
	if (!room)
		return ;
	if(room->name)
		free(room->name);
	free(room);
}

void		ft_delmap(t_map *map)
{
	t_room	*tmp;

	if(!map)
		return ;
	if (map->splt)
		ft_del_splitter(map->splt);
	if (map->hashed_rooms)
		free(map->hashed_rooms);
	while(map->room_start)
	{
		tmp = map->room_start;
		map->room_start = map->room_start->next;
		ft_delroom(tmp);
	}
}

void	man_err(char *msg, void *data, void (*f_todel)(void**))
{
	if (f_todel && data)
		f_todel(&data);
	if (msg)
		ft_putstr(msg);
	exit(1);
}


void	man_err_map(char *msg, void *data, void (*f_todel)(void**), t_map *map)
{
	if (f_todel && data)
		f_todel(&data);
	if (map)
		ft_delmap(map);
	if (msg)
		ft_putstr(msg);
	exit(1);
}