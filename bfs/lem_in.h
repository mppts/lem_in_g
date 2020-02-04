
#ifndef BFS_H
# define BFS_H
# define WHITE 0
# define GRAY 1
# define BLACK 2
# define SOURCE 1
# define SINK 2

# include <inttypes.h>
# include "libft/libft.h"
//linka->from = b;
//linkb->mirrorlink->to = a;

typedef struct 		s_link
{
    struct s_room	*to;
	struct s_room	*from;
    struct s_link	*next;
	struct s_link	*prev;
    uint64_t 		path_id;
    uint8_t			is_del;
    char			flow;
    struct s_link	*mirror_link;
}					t_link;
/*
** type: 1 is entrance; 2 is exit
*/
typedef struct		s_room
{
    char			*name;
    int				is_start_or_end;
    int				color;
	int64_t			level;
	t_link			*linked_to;
	struct s_room	*next;
	struct s_room	*prev;
//    int				x;
//    int				y;
//    u_char			type;
//    int 			checked;
//    int64_t			id;
//    uint64_t 		hash;
//    uint64_t 		hash_id;
//    uint64_t 		num_linked_to;

}					t_room;

typedef struct 		s_graph_inf
{
	struct s_room	***ways;
	struct s_link	**mirror_links;
	int				two_flows;
	int				current_way_number;
	int				position_in_way;
}					t_graph_inf;

int					dfs(t_room *room, t_graph_inf *inf);

#endif
