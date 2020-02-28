/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:58:55 by limry             #+#    #+#             */
/*   Updated: 2020/02/28 17:58:55 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isalpha(int c)
{
	return (('a' <= c && 'z' >= c) || ('A' <= c && 'Z' >= c));
}
