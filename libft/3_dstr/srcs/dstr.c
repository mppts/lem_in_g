/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:32:08 by limry             #+#    #+#             */
/*   Updated: 2020/02/28 18:01:22 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"

char			*dstr_pop_front(t_dstr *dstr, char **res, uint64_t l)
{
	if (l <= dstr->len_data)
	{
		if (res)
			*res = ft_strsub(dstr->start, 0, l);
		dstr->start += l;
		dstr->len_data -= l;
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

t_dstr			*dstr_init(char *data, uint64_t cap)
{
	t_dstr		*new;

	new = (t_dstr*)malloc(sizeof(t_dstr));
	new->len = data ? ft_strlen(data) : 0;
	if (!cap)
		cap = 4;
	while (cap < new->len)
		cap <<= 1;
	new->cap = cap;
	new->data = ft_strnew(new->cap);
	new->data[0] = '\0';
	new->start = new->data;
	new->len_data = 0;
	if (data)
		ft_strlcat(new->data, data, new->cap);
	return (new);
}

void			dstr_del(t_dstr *str)
{
	if (!str)
		return ;
	free(str->data);
	str->data = NULL;
	str->start = NULL;
	free(str);
	str = NULL;
}

static void		dstr_expand(t_dstr *dstr, uint64_t len_s, char *s)
{
	uint64_t	new_cap;
	char		*new;

	new_cap = dstr->cap;
	while (new_cap <= len_s + dstr->len)
		new_cap <<= 1;
	new = ft_strnew(new_cap);
	ft_bzero(new, new_cap);
	if (dstr->data)
		ft_strlcat(new, dstr->start, new_cap);
	ft_strlcat(new + dstr->len_data, s, new_cap - dstr->len_data);
	free(dstr->data);
	dstr->data = new;
	dstr->cap = new_cap;
	dstr->start = dstr->data;
	dstr->len_data = dstr->len_data + len_s;
	dstr->len = dstr->len_data;
}

t_dstr			*dstr_joinstr(t_dstr *dstr, char *s)
{
	uint64_t	len_s;

	if (!s)
		return (dstr);
	len_s = ft_strlen(s);
	if (len_s + dstr->len >= dstr->cap)
	{
		if (len_s < dstr->len - dstr->len_data)
		{
			ft_memmove(dstr->data, dstr->start, dstr->len_data + 1);
			dstr->start = dstr->data;
			ft_strlcat(dstr->data + dstr->len_data, s,
					dstr->cap - dstr->len_data);
			dstr->len_data += len_s;
			dstr->len = dstr->len_data;
		}
		else
			dstr_expand(dstr, len_s, s);
		return (dstr);
	}
	ft_strlcat(dstr->start + dstr->len_data, s, dstr->cap - dstr->len);
	dstr->len += len_s;
	dstr->len_data += len_s;
	return (dstr);
}
