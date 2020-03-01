/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:02:42 by limry             #+#    #+#             */
/*   Updated: 2020/02/28 18:02:42 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

void		ft_putnbr(int n)
{
	long long		num;

	num = (long long)n;
	if (n < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
		ft_putchar(num + '0');
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}
