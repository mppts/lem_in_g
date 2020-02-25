/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:35:42 by limry             #+#    #+#             */
/*   Updated: 2020/02/25 20:35:45 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	uint8_t		*s_dst;
	uint8_t		*s_src;

	if (0 == len || dst == src)
		return (dst);
	if (src < dst)
	{
		s_dst = (uint8_t*)dst;
		s_src = (uint8_t*)src;
		while (len--)
			s_dst[len] = s_src[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
