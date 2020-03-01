/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:30:03 by limry             #+#    #+#             */
/*   Updated: 2020/02/25 20:23:19 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"

char			*dstr_pop_back(t_dstr *dstr, char **res, uint64_t l)
{
	if (l <= dstr->len_data)
	{
		if (res)
			*res = ft_strsub(dstr->start, dstr->len_data - l, l);
		dstr->len_data -= l;
		dstr->len -= l;
		if (res)
			return (*res);
		else
			return (NULL);
	}
	*res = ft_strsub(dstr->start, 0, dstr->len_data);
	ft_bzero(dstr->data, dstr->cap);
	dstr->len = 0;
	dstr->start = dstr->data;
	dstr->len_data = 0;
	return (*res);
}

void			dstr_remove_back(t_dstr *dstr, uint64_t l)
{
	if (l <= dstr->len_data)
	{
		dstr->len_data -= l;
		dstr->start[dstr->len_data] = '\0';
		dstr->len -= l;
		return ;
	}
	dstr->len = 0;
	dstr->start = dstr->data;
	dstr->start[0] = '\0';
	dstr->len_data = 0;
}

void			dstr_remove_front(t_dstr *dstr, uint64_t l)
{
	if (l <= dstr->len_data)
	{
		dstr->len_data -= l;
		dstr->start += l;
		dstr->start[dstr->len_data] = '\0';
		return ;
	}
	dstr->len = 0;
	dstr->start = dstr->data;
	dstr->start[0] = '\0';
	dstr->len_data = 0;
}
