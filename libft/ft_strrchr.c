/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:29:47 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/09 00:03:49 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static UCC		*ft_memrcrawl(UCC *str, UCC logos, size_t n)
{
	while (n != 0)
	{
		if (*str == logos)
			return (str);
		str--;
		n -= 1;
	}
	if (*str == logos)
		return (str);
	return (NULL);
}

static UCC		*ft_wordwalker(UCC *str, UCC logos)
{
	size_t		counter;

	counter = 8;
	while (counter != 0)
	{
		if (*str == logos)
			return (str);
		str--;
		counter--;
	}
	return (NULL);
}

static void		*ft_memrchr(CV *s, int c, size_t n)
{
	size_t		*monad;
	UC			logos;
	size_t		mask;

	logos = c;
	if (*(UCC *)s == logos)
		return ((void *)s);
	if (n < (sizeof(size_t)))
		return ((void *)ft_memrcrawl(s, (UCC)logos, n));
	else
	{
		monad = (size_t *)(s - sizeof(size_t) + 1);
		while (n / sizeof(size_t) != 0)
		{
			mask = *monad ^ (~0UL / 255 * logos);
			if ((mask - MHZERO) & ~mask & DHZERO)
				return ((void *)ft_wordwalker(s, (UCC)logos));
			monad--;
			n -= 8;
			s -= 8;
		}
		return ((void *)ft_memrcrawl(s, (UCC)logos, n));
	}
}

char			*ft_strrchr(const char *s, int c)
{
	size_t		length;
	CV			*bogey;

	length = ft_strlen(s);
	bogey = (CV *)s + length;
	return (ft_memrchr(bogey, c, length));
}
