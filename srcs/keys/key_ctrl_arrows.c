/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_arrows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 23:47:21 by juloo             #+#    #+#             */
/*   Updated: 2015/06/20 00:01:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void			key_ctrl_left(t_j *j)
{
	int				cur;

	cur = j->cursor;
	while (cur > 0 && IS(j->line.str[cur - 1], IS_SPACE))
		cur--;
	while (cur > 0 && IS(j->line.str[cur - 1], IS_PUNCT))
		cur--;
	while (cur > 0 && IS(j->line.str[cur - 1], IS_WORD))
		cur--;
	j->cursor = cur;
}

void			key_ctrl_right(t_j *j)
{
	int				cur;

	cur = j->cursor;
	while (cur < j->line.length && IS(j->line.str[cur], IS_SPACE))
		cur++;
	while (cur < j->line.length && IS(j->line.str[cur], IS_PUNCT))
		cur++;
	while (cur < j->line.length && IS(j->line.str[cur], IS_WORD))
		cur++;
	j->cursor = cur;
}
