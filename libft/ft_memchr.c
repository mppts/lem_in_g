/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:33:59 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/11 00:10:26 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use size_t, thus we need libft.h in order to include stdlib.h
** Based on ft_strlen method.
*/

static UCC	*ft_memsync_s(UCC *str, UCC logos, size_t *n)
{
	while ((((size_t)str & (sizeof(size_t) - 1)) != 0) && *n != 0)
	{
		if (*str == logos)
			return (str);
		str++;
		*n -= 1;
	}
	if (*str == logos || n != 0)
		return (str);
	return (NULL);
}

static void	*ft_memcrawl_s(UCC *str, UCC logos, size_t n)
{
	while (n != 0)
	{
		if (*str == logos)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}

void		*ft_memchr(const void *s, int c, size_t n)
{
	UC		logos;
	size_t	mask;

	if (n == 0)
		return (NULL);
	logos = (UC)c;
	if (*(char *)(s = (ft_memsync_s((UCC *)s, (UCC)logos, &n))) == logos\
					&& n != 0)
		return ((void *)s);
	if (n < (sizeof(size_t)))
		return (ft_memcrawl_s((UCC *)s, (UCC)logos, n));
	else
	{
		while (n / sizeof(size_t) > 0 && n != 0)
		{
			mask = *(size_t *)s ^ (~0UL / 255 * (int)logos);
			if ((mask - MHZERO) & ~mask & DHZERO)
				return (ft_memcrawl_s((UCC *)s, (UCC)logos, n));
			s += sizeof(size_t);
			n -= 8;
		}
		if (n != 0)
			return (ft_memcrawl_s((UCC *)s, (UCC)logos, n));
	}
	return (NULL);
}
