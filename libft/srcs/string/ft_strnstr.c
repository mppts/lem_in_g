/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:28:08 by limry             #+#    #+#             */
/*   Updated: 2020/02/26 11:16:15 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len)
{
	const char	*camel;
	const char	*eye;
	size_t		cash;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0' && len != 0)
	{
		camel = haystack;
		eye = needle;
		cash = len;
		while (*eye != '\0' && *camel == *eye && cash != 0)
		{
			++eye;
			++camel;
			--cash;
		}
		if (*eye == '\0')
			return ((char*)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}
