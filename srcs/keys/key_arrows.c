/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 21:18:57 by juloo             #+#    #+#             */
/*   Updated: 2015/06/16 22:24:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void			key_up(t_j *j, int key)
{
	(void)j;
	(void)key;
}

void			key_right(t_j *j, int key)
{
	if (j->cursor < j->line.length)
		j->cursor++;
	(void)key;
}

void			key_down(t_j *j, int key)
{
	(void)j;
	(void)key;
}

void			key_left(t_j *j, int key)
{
	if (j->cursor > 0)
		j->cursor--;
	(void)key;
}
