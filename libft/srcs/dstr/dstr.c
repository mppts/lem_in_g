/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:32:08 by limry             #+#    #+#             */
/*   Updated: 2020/02/08 19:35:20 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstr.h"

char			*dstr_pop_front(t_dstr *dstr, char **res, uint64_t l)
{
	if (l <= dstr->cap)
	{
		if (res)
			*res = ft_strsub(dstr->data, 0, l);
		ft_memmove(dstr->data, dstr->data + l, dstr->cap - l);
		dstr->len = dstr->len - l;
		if (res)
			return (*res);
		else
			return (NULL);
	}
	*res = dstr->data;
	dstr->data = NULL;
	dstr->len = 0;
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
		cap <<=1;
	new->cap = cap;
	new->data = ft_strnew(new->cap);
	new->data[0] = '\0';
	if (data)
		ft_strlcat(new->data, data, new->cap);
	return (new);
}

void			dstr_del(t_dstr *str)
{
	if (!str)
		return ;
	if(str->data)
	{
		free(str->data);
		str->data = NULL;
	}
	free(str);
	str = NULL;
}

t_dstr 			*dstr_joinstr(t_dstr *dstr, char *s)
{
	uint64_t	len_s;
	uint64_t	new_cap;
	char		*new;

	if (!s)
		return (dstr);
	len_s  = ft_strlen(s);
	new_cap = dstr->cap;
	if (len_s + dstr->len >= new_cap)
	{
		while (new_cap / 2 < len_s + dstr->len)
			new_cap <<= 1;
		new = ft_strnew(new_cap);
		if (dstr->data)
			ft_strlcat(new, dstr->data, dstr->len);
		ft_strlcat(new + dstr->len, s, len_s);
		free(dstr->data);
		dstr->data = new;
		dstr->cap = new_cap;
		return (dstr);
	}
	ft_strlcat(dstr->data + dstr->len, s, len_s + 1);
	dstr->len = len_s + dstr->len;
	return (dstr);
}
