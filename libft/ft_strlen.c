/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:59:30 by mschimme          #+#    #+#             */
/*   Updated: 2020/02/05 12:00:45 by limry            ###   ########.fr       */
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

size_t				ft_strlen(const char *str)
{
	unsigned char	*v;
	size_t			ret;

	ret = 0;
	v = (unsigned char*)str;
	while (*v != '\0')
	{
		ret++;
		v++;
	}
	return (ret);
}
