/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:52:19 by limry             #+#    #+#             */
/*   Updated: 2020/02/05 13:00:05 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		del_lsts(t_lst *lst)
{
	t_lst	*tmp;
	t_lst	*tmp1;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		if (tmp1->str)
			free(tmp1->str);
		free(tmp1);
	}
}

int			clean_all_gnl(t_lst *lst)
{
	del_lsts(lst);
	return (-1);
}
