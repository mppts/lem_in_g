/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:01:51 by limry             #+#    #+#             */
/*   Updated: 2020/02/05 12:01:51 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_atoli(const char *str)
{
	long long	res;
	long long	sign;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str += 1;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
	{
		str += 1;
	}
	res = 0;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		str += 1;
		if (res >= 223372036854775808 && *str == '9' && sign == -1)
			return (0);
		if (res > 223372036854775807 && *str == '9')
			return (-1);
	}
	res *= sign;
	return (res);
}
