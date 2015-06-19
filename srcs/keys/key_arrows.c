/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 21:18:57 by juloo             #+#    #+#             */
/*   Updated: 2015/06/19 23:49:40 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void			key_up(t_j *j)
{
	(void)j;
}

void			key_right(t_j *j)
{
	if (j->cursor < j->line.length)
		j->cursor++;
}

void			key_down(t_j *j)
{
	(void)j;
}

void			key_left(t_j *j)
{
	if (j->cursor > 0)
		j->cursor--;
}
