/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:37:10 by limry             #+#    #+#             */
/*   Updated: 2020/02/09 01:02:50 by kona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char		*ft_strdup(const char *s1)
{
	char	*sub_res;

	if (!(sub_res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	return (ft_strcpy(sub_res, s1));
}
