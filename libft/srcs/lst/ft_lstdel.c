/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:00:15 by limry             #+#    #+#             */
/*   Updated: 2020/02/28 18:00:15 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*sub;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		sub = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = sub;
	}
	*alst = NULL;
}
