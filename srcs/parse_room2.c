/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:27:11 by limry             #+#    #+#             */
/*   Updated: 2020/03/03 19:06:16 by limry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_room(t_room *new, int x, int y, char *name)
{
	new->x = x;
	new->y = y;
	new->name = name;
	new->linked_to = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->num_linked_to = 0;
	new->level = 0;
	new->pot_out = 0;
	new->pot_in = 0;
	new->path_id = 0;
	new->ant = 0;
	new->pred_in = NULL;
	new->pred_out = NULL;
	new->sign = 0;
	new->flv = 0;
	new->delta_out = INT64_MAX;
	new->delta_in = INT64_MAX;
	new->sim = 0;
}
