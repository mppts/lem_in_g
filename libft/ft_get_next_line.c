/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:08:08 by mschimme          #+#    #+#             */
/*   Updated: 2019/04/16 23:13:17 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** t_list stem manager: creating its new parts, linking them together...
** DOES NOT intend to manage t_list CNTs.
**	pr == iterator, it aims to point behind last t_list.
**	We use them to link t_lists together.
**	last == iterator, it aims to point to the last t_list.
**	Drops out as result, if we found fd required.
**	Function calls fdl_man(flag3) if malloc fails. Thus we destroy
**	the chain.
**	!				IT's a must to pass non-NULL pr and last			!
**	pr and last ought to be == original fd_lst (*fd_lst here).
*/

static int			ft_lstmk(int fl, t_list **lst, int val, t_list **fd_lst)
{
	if (fl > 1)
	{
		if (!(*lst = ft_lstnew(NULL, 0)))
		{
			ft_lstdel(fd_lst, &ft_del);
			return (-1);
		}
		if ((fl == 2) && !((*lst)->CNT = ft_memalloc(SZFINT)))
		{
			ft_lstdel(fd_lst, &ft_del);
			*lst = NULL;
			return (-1);
		}
		if ((fl == 3) && !((*lst)->CNT = ft_memalloc(BUFF_SIZE + 1)))
		{
			ft_lstdel(fd_lst, &ft_del);
			*lst = NULL;
			return (-1);
		}
		(*lst)->C_S = SZFINT;
		(*(int *)((*lst)->CNT)) = val;
		return (0);
	}
	ft_lstdel(lst, &ft_del);
	return (-1);
}

static t_list		*ft_fdr(t_list **fd_lst, int fd, t_list *last, \
								t_list *pr)
{
	if (fd == -1)
		return (NULL);
	if (!(*fd_lst))
	{
		if (ft_lstmk(2, fd_lst, fd, fd_lst) == -1)
			return (NULL);
		return (*fd_lst);
	}
	else
	{
		while (last)
		{
			if (*(int *)(last->CNT) == fd)
				return (last);
			if (last->next == NULL)
				pr = last;
			last = last->next;
		}
		if (ft_lstmk(2, &(pr->next), fd, fd_lst) == -1)
			return (NULL);
		return (pr->next);
	}
}

/*
** 	I though I shall skip a row of '\n' with:
** while (*(char *)(++eolscan) == '\n' && eolscan < eosscan)
** 	;
** Guess I was wrong...
** bogey[0] == pointer to '\n' in rem.
** bogey[1] == substitute pointer for new rem->CNT.
** returns 0 when we found \n in rem AND there is remains in rem->CNT;
** returns 1 when we foudn \n in rem AND this \n is the last symbol of rem->CNT;
** returns 2 if we didn't find \n in rem.
*/

static int			ft_rs(char **line, t_list *rem, t_list **fd_lst)
{
	void			*bgy[3];

	bgy[0] = ft_memchr((CV *)rem->CNT + SZFINT, '\n', rem->C_S - SZFINT);
	bgy[2] = ft_memchr((CV *)rem->CNT + SZFINT, '\0', rem->C_S - SZFINT);
	if (((bgy[0]) && (bgy[0] < bgy[2])) || ((bgy[0]) && !(bgy[2])))
		;
	else
		bgy[0] = bgy[2];
	if ((bgy[0]) && (bgy[0] += 1))
	{
		if (!((*line) = ft_memalloc(bgy[0] - rem->CNT - SZFINT)))
			return (ft_lstmk(2, fd_lst, 0, fd_lst));
		ft_memcpy((void *)(*line), (CV *)rem->CNT + SZFINT, SIZEOFSBSTR);
		if (*(char *)(bgy[0] - 1) == '\0' && (bgy[0] - 1) != rem->CNT + SZFINT)
			bgy[0] -= 1;
		rem->C_S -= (bgy[0] - rem->CNT - SZFINT);
		if (!(bgy[1] = (ft_memalloc(rem->C_S))))
			return (ft_lstmk(2, fd_lst, 0, fd_lst));
		ft_memcpy(bgy[1] + SZFINT, (CV *)bgy[0], rem->C_S - SZFINT);
		*(int *)bgy[1] = *(int *)rem->CNT;
		free(rem->CNT);
		rem->CNT = bgy[1];
		return (0);
	}
	return (2);
}

static int			ft_hopper(t_list **ar, t_list **fdl, char **lin, size_t fl)
{
	if (fl == 1)
	{
		if (!(ar[2] = (t_list *)ft_memalloc(ar[0]->C_S + ar[1]->C_S)))
			return (ft_lstmk(2, fdl, 0, fdl));
		ft_memcpy(ft_memcpy((void *)ar[2], (CV *)ar[0]->CNT, ar[0]->C_S) + \
				ar[0]->C_S, (CV *)ar[1]->CNT, ar[1]->C_S);
		free(ar[0]->CNT);
		ar[0]->CNT = (void *)ar[2];
		ar[0]->C_S += ar[1]->C_S;
		ft_lstdelone(&ar[1], &ft_del);
		return (get_next_line(*(const int *)(ar[0]->CNT), lin));
	}
	if (!((*lin) = (char *)ft_memalloc(ar[0]->C_S - SZFINT + 1)))
		return (ft_lstmk(2, fdl, 0, fdl));
	ft_memcpy((void *)(*lin), (CV *)ar[0]->CNT + SZFINT, ar[0]->C_S - SZFINT);
	ft_bzero(ar[0]->CNT + SZFINT, ar[0]->C_S - SZFINT);
	ar[0]->C_S = SZFINT;
	ar[2] = *fdl;
	fl += ar[2]->C_S - SZFINT;
	while ((ar[2] = ar[2]->next))
		fl += ar[2]->C_S - SZFINT;
	if (fl == 0)
		ft_lstdel(fdl, &ft_del);
	ft_lstdelone(&ar[1], &ft_del);
	return (1);
}

/*
** sbs[0] - is pointer to current fd_lst, corresponding appropriate fd.
** sbs[1] - is a pointer to buffer.
** sbs[2] - is a poiter to void * string.
*/

int					get_next_line(const int fd, char **line)
{
	static t_list	*fdl;
	t_list			*pl[3];
	int				ss[2];

	if (!((pl[0] = ft_fdr(&fdl, fd, fdl, fdl)) && !(BUFF_SIZE < 1) && \
			((ss[0] = ft_rs(line, pl[0], &fdl)) != -1)))
		return (-1);
	if (ss[0] == 0)
		return (1);
	if ((pl[2] = fdl) && (ft_lstmk(3, &pl[1], 0, &fdl) == -1))
		return (-1);
	if ((ss[1] = read(fd, pl[1]->CNT, BUFF_SIZE)) == -1)
		return (-1);
	if ((pl[1]->C_S = (size_t)ss[1]) != 0)
		return (ft_hopper(pl, &fdl, line, 1));
	if (pl[0]->C_S - SZFINT == 0 && !(*line = NULL))
	{
		pl[1]->C_S += pl[2]->C_S - SZFINT;
		while ((pl[2] = pl[2]->next))
			pl[1]->C_S += pl[2]->C_S - SZFINT;
		if (pl[1]->C_S == 0)
			ft_lstdel(&fdl, &ft_del);
		return (ft_lstmk(0, &pl[1], 0, NULL) + 1);
	}
	return (ft_hopper(pl, &fdl, line, 0));
}
