
#include "dstr.h"

char			*dstr_pop_front(t_dstr *dstr, char **res, uint64_t l)
{
	if (l >= dstr->cap)
	{
		res = ft_strdup(dstr->data);
		free(dstr->data);
		dstr->len = 0;
	}
	res = ft_strsub(dstr->data, )
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
			new_cap <<=1;
		new = ft_strnew(new_cap);
		if (dstr->data)
			ft_strlcat(new, dstr->data, new_cap);
		ft_strlcat(new + dstr->len, s, new_cap - dstr->len);
		free(dstr->data);
		dstr->data = new;
		dstr->cap = new_cap;
		return (dstr);
	}
	ft_strlcat(dstr->data + dstr->len, s, dstr->cap - dstr->len);
	dstr->len = len_s + dstr->len;
	return (dstr);
}
