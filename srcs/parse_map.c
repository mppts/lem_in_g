/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:09:29 by limry             #+#    #+#             */
/*   Updated: 2020/02/05 17:28:15 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_room_or_path(char *buf, t_flag *flag, t_map *map)
{
	if (ft_strchr(buf, ' '))
	{
		if (map->is_rooms_hashed)
			man_err_map("Error: add room after links\n", &buf, ft_strdel, map);
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
		man_err_map("Error: non compliant line\n", &buf, ft_strdel, map);
}

static void		parse_ants(t_map *map, char *buf)
{
	int64_t		ants;

	if (!is_num(buf))
	{
		man_err_map("Error: not only numbers in first line\n",
					&buf, ft_strdel, map);
	}
	ants = ft_atoli(buf);
	if (ants < 1 || ants >= INT32_MAX)
	{
		man_err_map("Error: no or too many ants\n", &buf, ft_strdel, map);
	}
	map->ants = ants;
}

static int		parse_line(char *buf, t_flag *flag, t_map *map)
{
	if (!buf)
		return (1);
	if (*buf == '#')
	{
		if (!ft_strcmp(buf, "##start"))
			flag->flag_start = 1;
		else if (!ft_strcmp(buf, "##end"))
			flag->flag_end = 1;
	}
	else if (!map->ants)
		parse_ants(map, buf);
	else if (*buf != 'L')
		add_room_or_path(buf, flag, map);
	else
		man_err_map("Room starts with L\n", &buf, ft_strdel, map);
	return (0);
}

void			init_map(t_map *map)
{
	map->num_links = 0;
	map->num_nodes = 0;
	map->is_rooms_hashed = FALSE;
	map->room_start = NULL;
	map->room_end = NULL;
	map->start = NULL;
	map->fin = NULL;
	map->no_path_exists = 1;
	map->ants = 0;
	map->splt = NULL;
	map->hashed_rooms = NULL;
	map->buf = NULL;
	map->out = NULL;
}

void			parse_map(t_map *map)
{
	char		*buf;
	t_flag		flag;
	int			ret;

	flag.flag_end = 0;
	flag.flag_start = 0;
	buf = NULL;
	while ((ret = get_next_line(0, &buf)))
	{
		map->buf = &buf;

		if (ret == -1)
			break ;
		map->out = ft_strjoin(map->out, buf);
		map->out = ft_strjoin(map->out, "\n");
		if (parse_line(buf, &flag, map))
		{
			free(buf);
			break ;
		}
		free(buf);
	}
}
