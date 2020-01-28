/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:44:31 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/06 20:45:46 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use size_t, thus we need libft.h in order to include stdlib.h
*/

static void	small_string(void *s, size_t *n)
{
	while (*n != 0)
	{
		*(UC *)s = '\0';
		*n -= 1;
		s++;
	}
}

static void	*ft_memsync(void *s, size_t *n)
{
	while (((size_t)s & (sizeof(size_t) - 1)) != 0)
	{
		*(UC *)s = '\0';
		*n -= 1;
		s++;
	}
	return (s);
}

void		ft_bzero(void *s, size_t n)
{
	size_t	bogey;
	size_t	zero;

	if (0 == n)
		return ;
	if (n < sizeof(long))
	{
		small_string(s, &n);
		return ;
	}
	if (sizeof(size_t) < 8)
		zero = 0x00000000;
	else
		zero = 0x0000000000000000;
	s = ft_memsync(s, &n);
	bogey = n / sizeof(size_t);
	while (bogey != 0)
	{
		*(size_t *)s = zero;
		s += (sizeof(size_t));
		bogey--;
	}
	bogey = n % sizeof(size_t);
	small_string(s, &bogey);
	return ;
}
