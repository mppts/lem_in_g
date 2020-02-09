
#include "lem_in.h"
#include "ft_writer.h"

void		generate_paths(t_map *map, t_path *paths[map->ants + 1], int offset[map->ants + 1])
{
	int		i;
	int		ants;
	int		filling;

	i = 0;
	filling = TRUE;
	while (filling)
	{
		ants = 1;
		filling = FALSE;
		while (offset[ants] == i && paths[ants]->len > offset[ants])
		{
			dstr_joinstr(map->dstr, "L");
			dstr_joinstr(map->dstr, ft_itoa(ants));
			dstr_joinstr(map->dstr, "-");
			dstr_joinstr(map->dstr, paths[ants]->path[offset[ants]]->name);
			ants++;
			offset[ants]++;
			filling = TRUE;
		}
		i++;
	}
}

 void		writer(t_map *map)
 {
	int		i;
	int		ants;
	t_path	*paths_q[map->ants + 1];
	int 	offset[map->ants + 1];
	t_path	*tmp;

	i = 0;
	ants = 1;
	while (map->ants - ants)
	{
		tmp = map->paths->paths;
		while(tmp && ants <= map->ants)
		{
			paths_q[ants] = tmp->path;
			offset[ants] = i;
			tmp = tmp->next;
			ants++;
		}
		i++;
	}
	generate_paths(map, paths_q, offset);
 }

