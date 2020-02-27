/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_sufficienty_c_common_rooms_calc.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:53:29 by dorphan           #+#    #+#             */
/*   Updated: 2020/02/27 18:53:31 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			common_rooms_calc(t_graph_inf *inf)
{
	int		i;
	int		total_result;
	int		current_result;

	i = 1;
	total_result = 0;
	current_result = 1;
	while (inf->common_rooms[i])
	{
		if (inf->common_rooms[i]->way_number !=
				inf->common_rooms[i - 1]->way_number)
		{
			total_result += ((current_result - 1) * 2);
			current_result = 1;
			i++;
		}
		else
		{
			current_result++;
			i++;
		}
	}
	if (!inf->common_rooms[i])
		total_result += ((current_result - 1) * 2);
	return (total_result);
}
