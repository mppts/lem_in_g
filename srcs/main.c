/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:38:25 by limry             #+#    #+#             */
/*   Updated: 2020/02/25 20:58:19 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		parse_errors(t_map *map)
{
	if (!map->start)
		man_err_map("ERROR: no start point. Set '##start'\n", NULL, NULL, map);
	if (!map->fin)
		man_err_map("ERROR: no end point. Set '##end'\n", NULL, NULL, map);
	if (!map->num_nodes)
		man_err_map("ERROR: no paths at all. Set links in map\n",
				NULL, NULL, map);
	if (!map->num_links)
		man_err_map("ERROR: farm has no paths. Just wait for ant-workers...\n",
					NULL, NULL, map);
	if (map->start == map->fin)
		man_err_map("ERROR: all ants are sleep in their start-end point\n",
					NULL, NULL, map);
}

int			main(void)
{
	t_map	map;

	init_map(&map);
	parse_map(&map);
	parse_errors(&map);
	solver_edmonds_karp(&map);
	if (map.paths == NULL)
		man_err_map("ERROR: no way for the honest ant...=(\n",
					NULL, NULL, &map);
	writer(&map);
	//if (map.dstr->data)
	//	write(1, map.dstr->data, map.dstr->len);
	del_map(&map);
	return (0);
}
