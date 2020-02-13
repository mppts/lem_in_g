/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:03:07 by limry             #+#    #+#             */
/*   Updated: 2020/02/13 21:56:05 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H

# include <inttypes.h>
# include <libft.h>
# include <dstr.h>
# include <get_next_line.h>
# include <stdlib.h>

# define FALSE 0
# define TRUE 1
# define WHITE 0
# define GRAY 1
# define BLACK 2

typedef struct		s_r_reader
{
	char 			*name_room;
	char 			*sx;
	char 			*sy;
	char 			*from;
	char 			*to;
}					t_r_reader;

typedef struct		s_path
{
	int 			id;
	uint64_t		len;
	uint64_t		ants;
	uint64_t		ants_on;
	struct s_room	**path;
	struct s_path	*next;
}					t_path;

/*
** Пока что проще работать со своими структурами данных.
*/
typedef struct 		s_graph_inf
{
	struct s_room	***ways;
	struct s_link	**mirror_links;
	int				two_flows;
	int				current_way_number;
	int 			current_pos_in_way;
	int				position_in_way;
	int				total_ways_len;
	double			are_enough_ways_current;
	double			are_enough_ways_new;
}					t_graph_inf;

typedef struct		s_link
{
	struct s_room	*to;
	struct s_link	*next;
	struct s_link	*prev;
	struct s_link	*mirror;
	int64_t			path_id;
	int				flow;
}					t_link;
/*
** type: 1 is entrance; 2 is exit
*/
typedef struct		s_room
{
	int 			ant;
	char			*name;
	int64_t			level;
	int				color;
	t_link			*linked_to;
	struct s_room	*next;
	struct s_room	*prev;
	int				x;
	int				y;
	int				checked;
	uint64_t		hash;
	uint64_t		hash_id;
	uint64_t		path_id;
	uint64_t		num_linked_to;
}					t_room;

typedef struct		s_map
{
	uint8_t			no_path_exists;
	t_room			*room_start;
	t_room			*room_end;
	t_room			*start;
	t_room			*fin;
	uint64_t		num_nodes;
	uint64_t		num_links;
	int64_t			ants;
	uint8_t			is_rooms_hashed;
	uint64_t		len_rh;
	t_room			**hashed_rooms;
	char 			*buf;
	char 			*out;
	t_dstr 			*dstr;
	struct s_path	*path;
}					t_map;

typedef struct		s_flag
{
	int				flag_end;
	int				flag_start;
}					t_flag;

typedef struct		s_deq
{
	t_room			**deq;
	int64_t			rear;
	int64_t			begin;
}					t_deq;

typedef struct		s_positioner
{
	uint64_t		offset;
	t_path 			*path;
}					t_positioner;
/*
** parse_map.c
*/
void				parse_map(t_map *map);
void				init_map(t_map *map);
/*
** parse_room.c
*/
void				add_room(char *buf, t_flag *flag, t_map *map);
void				link_rooms(t_map *map, t_room *new);
void				init_room(t_room *new, int x, int y, char *name);
/*
** parse_links.c
*/
void				add_link(char *buf, t_map *map);

/*
** utils_utils.c
*/
int					is_num(char *str);
/*
** parse_hash.c
*/
void				hash_rooms(t_map *map);
uint64_t			get_hash(char *str, uint64_t size);
t_room				*find_hashed_room(t_map *map, char *name);
/*
** man_err.c
*/
void				del_map(t_map *map);
void				del_room(t_room *room);

void				man_err_map(char *msg, char **data,
					void (*f_todel)(char**), t_map *map);

/*
** solver.c
*/
void				solver(t_map *map);
void				make_color_white_again(t_room *source);
int					rooms_calc(t_room *source);
int					way_len_calc(t_room **way);

/*
** solve_algorithm.c
*/
void				algo(t_map *map, t_graph_inf *inf);
void				algo2(t_map *map, t_graph_inf *inf, t_graph_inf *inf_min);
t_room				***memory_for_ways(t_map *map, t_room ***ways);


/*
** solve_bfs.c
*/
t_room				*bfs(t_room *sink, t_map *map);

/*
** solve_dfs.c
*/
int					dfs(t_room *room, t_graph_inf *inf, t_map *map);

void				writer(t_map *map);
void				time_to_do_some_cleaning(t_map *map, t_graph_inf *inf);


#endif
