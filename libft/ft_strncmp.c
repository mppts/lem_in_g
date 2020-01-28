/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 00:09:31 by mschimme          #+#    #+#             */
/*   Updated: 2019/02/20 18:22:14 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use size_t, thus we need libft.h in order to include stdlib.h
*/

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t size_s1;
	size_t size_s2;

	size_s1 = ft_strlen(s1) + 1;
	size_s2 = ft_strlen(s2) + 1;
	if (size_s1 <= size_s2 && size_s1 <= n)
		return (ft_memcmp((CV *)s1, (CV *)s2, size_s1));
	else if (size_s2 <= size_s1 && size_s2 <= n)
		return (ft_memcmp((CV *)s1, (CV *)s2, size_s2));
	return (ft_memcmp((CV *)s1, (CV *)s2, n));
}
