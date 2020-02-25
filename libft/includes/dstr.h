/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:48:01 by limry             #+#    #+#             */
/*   Updated: 2020/02/25 20:41:32 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_DSTR_H
# define LEM_IN_DSTR_H

# include <stdlib.h>
# include <inttypes.h>
# include "libft.h"

typedef struct		s_dstr
{
	char			*data;
	char			*start;
	uint64_t		len;
	uint64_t		len_data;
	uint64_t		cap;
}					t_dstr;

void				dstr_del(t_dstr *str);
t_dstr				*dstr_init(char *data, uint64_t cap);
t_dstr				*dstr_joinstr(t_dstr *dstr, char *s);
char				*dstr_pop_front(t_dstr *dstr, char **res, uint64_t l);
char				*dstr_pop_back(t_dstr *dstr, char **res, uint64_t l);
void				dstr_remove_back(t_dstr *dstr, uint64_t l);
void				dstr_remove_front(t_dstr *dstr, uint64_t l);

#endif
