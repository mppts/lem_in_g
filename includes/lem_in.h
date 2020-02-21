/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:03:07 by limry             #+#    #+#             */
/*   Updated: 2020/02/21 22:56:24 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H

# include <inttypes.h>
# include <libft.h>
# include <dstr.h>
# include <get_next_line.h>
# include <stdlib.h>
# include <fcntl.h>
# include <binary_heap.h>

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
	int				are_enough_ways_current;
	int				are_enough_ways_new;
}					t_graph_inf;

typedef struct		s_link
{
	struct s_room	*to;
	struct s_link	*next;
	struct s_link	*prev;
	struct s_link	*mirror;
	int64_t			path_id;
	int32_t			w;
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
	int64_t			potential;
	int64_t			sign;
	int				color;
	t_link			*linked_to;
	struct s_room	*pred;
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
	void			**deq;
	int64_t			rear;
	int64_t			num_elems;
	int64_t			size_of_elem;
	int64_t			begin;
}					t_deq;

typedef struct		s_paths_arr
{
	uint64_t		amt_steps_cost;
	int				current_path;
	int				num_paths;
	t_room			**path;
	t_room			***path_starts;
	int				*path_lens;
}					t_paths_arr;


typedef struct		s_solver
{
	t_bin_heap 		*heap;
	t_deq			*deq;
	t_paths_arr		*paths_arr;
	t_paths_arr		*paths_arr_solution;
}					t_solver;

/*
** parse_map.c
*/
void				parse_map(t_map *map, int fd);
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
void				restore_meta_graph_info(t_room *source);
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
int					dfs_pl(t_room *start, t_graph_inf *inf, t_map *map);
t_room				*bfs_level(t_room *sink, t_map *map);
void				put_zero_to_flows(t_room *source);
void				restore_meta_graph_info(t_room *source);
void				algo3(t_map *map, t_graph_inf *inf, t_graph_inf *inf_min);

/*
** dequeue.c
*/
t_deq				*deq_init_malloc(uint64_t num_elems, size_t size_of_elem);
void				*deq_pop_rear(t_deq *sdeq);
t_room				*deq_pop_front(t_deq *sdeq);
void				deq_push_back(void *room, t_deq *sdeq);
void				deq_remove_unsafe(t_deq *deq);
void				deq_clear_data(t_deq *deq, uint64_t num_elems, size_t size_of_elem);
/*
** solver_tools.c
*/
t_solver			*init_solver(t_map *g);
void				slv_clean_paths(t_paths_arr *path, t_map *g);
void				remove_solver(t_solver *slv);


int					bin_dijkstra(t_map *g, t_bin_heap *heap);
void				solver_edmonds_karp(t_map *g);
t_room				*bfs_potential(t_room *start, t_room *final, t_map *map, t_deq *deq);


#endif
