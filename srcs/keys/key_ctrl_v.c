/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:05:14 by juloo             #+#    #+#             */
/*   Updated: 2015/06/21 00:14:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void			key_ctrl_v(t_j *j)
{
	if (j->deletions == NULL)
		return ;
	ft_dstrset(&(j->line), j->cursor, j->cursor,
		SUB(j->deletions->str, j->deletions->length));
	j->cursor += j->deletions->length;
}
