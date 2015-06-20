/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:05:14 by juloo             #+#    #+#             */
/*   Updated: 2015/06/21 00:15:29 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include <stdlib.h>

void			key_ctrl_y(t_j *j)
{
	t_hist			*tmp;

	if (j->deletions == NULL)
		return ;
	tmp = j->deletions;
	ft_dstrset(&(j->line), j->cursor, j->cursor, SUB(tmp->str, tmp->length));
	j->cursor += tmp->length;
	j->deletions = tmp->prev;
	free(tmp);
}
