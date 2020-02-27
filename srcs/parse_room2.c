/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limry <limry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:27:11 by limry             #+#    #+#             */
/*   Updated: 2020/02/26 11:16:15 by limry            ###   ########.fr       */
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
	new->potential = 0;
	new->path_id = 0;
	new->ant = 0;
	new->color = WHITE;
	new->pred = NULL;
	new->pred_neg = NULL;
	new->sign = 0;
	new->flv = 0;
	new->delta = INT64_MAX;
}
