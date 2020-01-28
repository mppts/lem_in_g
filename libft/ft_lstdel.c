/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:08:38 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/05 23:58:56 by mschimme         ###   ########.fr       */
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
