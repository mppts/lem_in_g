/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:03:07 by limry             #+#    #+#             */
/*   Updated: 2020/02/12 18:55:35 by limry            ###   ########.fr       */
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
	struct s_room	**path;
	struct s_path	*next;
}					t_path;

typedef struct		s_way
{
	int				way_number;
	int 			way_len;
	struct s_room	*room;
	struct s_way	*next;
	struct s_way	*prev_way;
}					t_way;

typedef struct 		s_graph_inf
{
	struct s_way	**ways;
	struct s_room	**common_rooms;
	int				current_way_number;
	int64_t			len_t;
	int64_t			enough_c;
	int64_t			enough_n;
	int 			max_ways;
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
	int64_t			level_rev;
	int				way_number;
	t_link			*linked_to;
	struct s_room	*room_from_we_came;
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
void				free_way(t_way *way);

/*
** solver_initialization.c
*/
void				initialization(t_map *map, t_graph_inf	*inf);
/*
** solver_algorithm.c
*/
void				algo(t_map *map, t_graph_inf *inf);

/*
** solver_algorithm_cleaning.c
*/
void		delite_mirror_links(t_graph_inf *inf);
void		clean_ways(t_room ***ways);
void		clean_levels_and_flows(t_room *source);
t_graph_inf	*time_to_do_some_cleaning(t_map *map, t_graph_inf *inf);


/*
** solver_bfs.c
*/
int				bellman_ford(t_map *map, t_room **line, t_graph_inf *inf);
int				bellman_ford_rev(t_map *map, t_room **line, t_graph_inf *inf);

/*
** solver_find_best_current_way.c
*/
int		find_best_current_way(t_map *map, t_room **way_1, t_room **way_2, t_graph_inf *inf);

/*
** solver_bf_find_way.c
*/
int					find_way_bf(t_map *map, t_room **line);
/*
** solver_bf_es_find_way.c
*/
int					find_way_bf_e_s(t_map *map, t_room **line);

/*
** solver_auxiliary_works_algo.c
*/
void				auxiliary_works(t_map *map, t_graph_inf *inf, t_room **way_1);

/*
** solver_auxiliary_works_algo_2.c
*/
void				sort_ways(t_graph_inf *inf);
void				give_right_numbers_to_ways(t_graph_inf *inf);
void				clear_common_rooms(t_graph_inf *inf);

/*
** solver_find_way.c
*/
void				find_way_1(t_map *map, t_room **line, t_graph_inf *inf);
/*
** solver_separation.c
*/
void				separate_cross_ways(t_graph_inf *inf, t_map *map);

/*
** solver_sufficienty_c.c
*/
int					sufficienty_c(t_graph_inf *inf, t_map *map);

/*
** solver_sufficienty_c_common_rooms_calc.c
*/
int					common_rooms_calc(t_graph_inf *inf);

void				writer(t_map *map);

#endif
