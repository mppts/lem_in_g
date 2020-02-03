#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include <inttypes.h>
#include <libft.h>
#include <stdlib.h>

# define FALSE 0
# define TRUE 1

typedef struct		s_paths
{
	struct s_room	**path;
	uint64_t 		path_len;
}					t_paths;

typedef struct 		s_link
{
	struct s_room	*to;
	struct s_link	*next;
	int64_t 		path_id;
}					t_link;
/*
** type: 1 is entrance; 2 is exit
*/
typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	char			type;
	int 			checked;
	int64_t			id;
	uint64_t 		hash;
	uint64_t 		hash_id;
	uint64_t 		path_id;
	uint64_t 		num_linked_to;
	int64_t			level;
	t_link			*linked_to;
	struct s_room	*next;
	struct s_room	*prev;

}					t_room;

typedef struct		s_map
{
	uint8_t 		no_path_exists;
	t_room			*room_start;
	t_room			*room_end;
	t_room			*start;
	t_room			*fin;
	uint64_t		num_nodes;
	uint64_t		num_links;
	int64_t			ants;
	char 			**splt;
	uint8_t			is_rooms_hashed;
	t_room			**hashed_rooms;
}					t_map;

typedef struct 		s_flag
{
	int 			flag_end;
	int 			flag_start;
}					t_flag;

typedef struct 		s_deq
{
	t_room			**deq;
	int64_t 		rear;
	int64_t 		begin;
}					t_deq;

void				man_err(char *msg, void *data, void (*f_todel)(void**));
void				man_err_map(char *msg, void *data, void (*f_todel)(void**), t_map *map);
void				ft_del_splitter(char **pocket);


#endif
