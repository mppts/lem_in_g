/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:03:07 by limry             #+#    #+#             */
/*   Updated: 2020/02/05 15:23:22 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H

# include <inttypes.h>
# include <libft.h>
# include <stdlib.h>

# define FALSE 0
# define TRUE 1


typedef struct		s_path
{
	uint64_t		len;
	struct s_room	**path;
	struct s_path	*next;
}					t_path;

typedef struct		s_paths
{
	uint64_t		num_paths;
	t_path			*paths;
}					t_paths;

typedef struct		s_link
{
	struct s_room	*to;
	struct s_link	*next;
	struct s_link	*prev;
	struct s_link	*mirror;
	int64_t			path_id;
}					t_link;
/*
** type: 1 is entrance; 2 is exit
*/
typedef struct		s_room
{
	int				x;
	int				y;
	int				checked;
	uint64_t		hash;
	uint64_t		hash_id;
	uint64_t		path_id;
	uint64_t		num_linked_to;
	int64_t			level;
	t_link			*linked_to;
	struct s_room	*next;
	struct s_room	*prev;
	char			*name;
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
	char			**splt;
	uint8_t			is_rooms_hashed;
	t_room			**hashed_rooms;
	char 			**buf;
	char 			*out;
	t_paths			*paths;
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
void				ft_del_splitter(char **pocket);

#endif
