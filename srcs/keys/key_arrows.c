/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 21:18:57 by juloo             #+#    #+#             */
/*   Updated: 2015/06/20 23:55:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void			key_up(t_j *j)
{
	if (j->hist_curr == NULL)
	{
		j->hist_curr = j->history;
		if (j->line.length > 0)
		{
			j_history(j, j->line);
			if (j->flags & FLAG_DEBUG)
				ft_printf("\r\nSave line in history\r\n");
			j->hist_curr = j->history->prev;
		}
	}
	else if (j->hist_curr->prev == NULL)
		return ;
	else
		j->hist_curr = j->hist_curr->prev;
	ft_dstrpop(&(j->line), -1);
	ft_dstradd(&(j->line), j->hist_curr->str, j->hist_curr->length);
	j->cursor = j->line.length;
}

void			key_right(t_j *j)
{
	if (j->cursor < j->line.length)
		j->cursor++;
}

void			key_down(t_j *j)
{
	if (j->hist_curr == NULL)
	{
		if (j->line.length > 0)
			j_history(j, j->line);
		ft_dstrpop(&(j->line), -1);
		return ;
	}
	j->hist_curr = j->hist_curr->next;
	ft_dstrpop(&(j->line), -1);
	if (j->hist_curr != NULL)
		ft_dstradd(&(j->line), j->hist_curr->str, j->hist_curr->length);
	j->cursor = j->line.length;
}

void			key_left(t_j *j)
{
	if (j->cursor > 0)
		j->cursor--;
}
