/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:42:01 by limry             #+#    #+#             */
/*   Updated: 2020/02/05 12:15:12 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_lst	*ft_get_or_add(t_lst *hd, int fd)
{
	t_lst			*new;
	t_lst			*lst;
	t_lst			*last;

	lst = hd;
	while (lst)
	{
		if (lst->dn == fd)
			return (lst);
		if (!lst->next)
			last = lst;
		lst = lst->next;
	}
	if ((new = (t_lst*)malloc(sizeof(t_lst))))
	{
		new->dn = fd;
		new->next = NULL;
		new->str = NULL;
		if (hd && last)
			last->next = new;
		return (new);
	}
	return (NULL);
}

static void		ft_del_fd(t_lst *lst, t_lst *hd)
{
	t_lst	*tmp;

	tmp = hd;
	if (hd == lst)
	{
		free(lst->str);
		lst->next = NULL;
		free(lst);
		lst = NULL;
		return ;
	}
	while (tmp != lst && tmp->next != lst && tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->next == lst)
	{
		tmp->next = tmp->next->next;
		free(lst->str);
		free(lst);
		lst->next = NULL;
	}
}

static int		read_file(t_lst *lst, const int fd)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	long int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = ft_strjoin(lst->str, buf);
		free(lst->str);
		lst->str = tmp;
		if (ft_strchr(lst->str, '\n'))
			break ;
	}
	return (ret);
}

static int		show_line(t_lst *lst, char **line)
{
	char			*tmp;

	if (ft_strchr(lst->str, '\n'))
	{
		*line = ft_strsub(lst->str, 0, ft_strchr(lst->str, '\n') - lst->str);
		tmp = ft_strdup(ft_strchr(lst->str, '\n') + 1);
		free(lst->str);
		lst->str = tmp;
		return (1);
	}
	*line = ft_strdup(lst->str);
	free(lst->str);
	lst->str = NULL;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_lst	*hd;
	t_lst			*lst;
	t_lst			*hd1;
	long int		ret;

	if (!line || BUFF_SIZE <= 0)
		return (-1);
	if (fd < 0)
		return (clean_all_gnl(hd));
	if (!hd)
		hd = ft_get_or_add(hd, fd);
	lst = ft_get_or_add(hd, fd);
	ret = read_file(lst, fd);
	if (ret < 0)
		return (-1);
	if (!(lst->str)[0] && !ret)
	{
		hd1 = hd;
		if (lst == hd)
			hd = hd->next;
		ft_del_fd(lst, hd1);
		return (0);
	}
	return (show_line(lst, line));
}
