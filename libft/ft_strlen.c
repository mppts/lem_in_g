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

size_t			ft_strlen(const char *s)
{
	uint64_t	*longword;
	uint8_t		*byte;

	byte = (uint8_t*)s;
	while ((uint64_t)byte & 7ULL)
	{
		if (*byte == '\0')
			return ((size_t)byte - (size_t)s);
		byte++;
	}
	longword = (uint64_t*)byte;
	while ((((*longword) - MHZERO)
	& ~(*longword) & DHZERO) == FALSE)
		longword++;
	byte = (uint8_t*)longword;
	while (*byte)
		byte++;
	return ((size_t)byte - (size_t)s);
}