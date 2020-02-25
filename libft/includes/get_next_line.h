/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:40:50 by limry             #+#    #+#             */
/*   Updated: 2020/02/25 20:40:50 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_GET_NEXT_LINE_H
# define LEM_IN_GET_NEXT_LINE_H

# include "libft.h"
# include "dstr.h"

# define BUFF_SIZE 128

typedef struct		s_lst
{
	struct s_lst	*next;
	int				dn;
	uint64_t		rot;
	char			*nl;
	t_dstr			*str;
}					t_lst;

int					get_next_line(const int fd, char **line);
int					clean_all_gnl(t_lst *lst);

#endif
