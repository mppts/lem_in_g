/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:37:04 by limry             #+#    #+#             */
/*   Updated: 2020/02/09 01:02:50 by kona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	bogey;

	if (s && f)
	{
		bogey = 0;
		while (s[bogey] != '\0')
		{
			f(bogey, &s[bogey]);
			bogey++;
		}
	}
}
