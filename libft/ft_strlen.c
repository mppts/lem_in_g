/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:59:30 by mschimme          #+#    #+#             */
/*   Updated: 2019/02/22 17:17:59 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use size_t, thus we need libft.h in order to include stdlib.h
** Previously function had
** if (bogey == '\0')
**		return (bogey - (UCC *)str);
** Preventing segfaults.
*/

static UCC		*ft_memsync(UCC *str)
{
	if (((size_t)str & (sizeof(size_t) - 1)) != 0)
	{
		while (((size_t)str & (sizeof(size_t) - 1)) != 0)
		{
			if (*str == '\0')
				return (str);
			str++;
		}
		return (str);
	}
	return (str);
}

static UCC		*ft_memcrawl(UCC *str)
{
	while (*str != '\0')
		str++;
	return (str);
}

size_t			ft_strlen(const char *str)
{
	size_t		*monad;
	UCC			*bogey;

	bogey = (ft_memsync((UCC *)str));
	monad = ((size_t *)bogey);
	while (1)
	{
		if (((*monad + 0X7EFEFEFEFEFEFEFF) ^ ~*monad) & 0x8101010101010100)
			if (((((*monad & 0x7F7F7F7F7F7F7F7F) + 0x7F7F7F7F7F7F7F7F) | *monad)
				| 0x7F7F7F7F7F7F7F7F))
				return (ft_memcrawl(((UCC *)(monad))) - (UCC *)str);
		monad++;
	}
}
