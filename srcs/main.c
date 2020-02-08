#include "lem_in.h"

int			main(void)
{

	t_map	map;

	init_map(&map);
	//parse input
	// parse ants
	// parse map
	parse_map(&map);
	//check ant farm
	if (!map.start || !map.fin || !map.num_nodes)
		man_err_map("Error: no start or end...or no rooms or map is empty\n",
				NULL, NULL, &map);
	if (map.dstr->data)
		write(1, map.dstr->data, map.dstr->len);
	//algorithm processing
//	solver(&map);
	//output
	// VISUALIZATION??
	del_map(&map);
	return 0;

}