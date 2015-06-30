/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 21:18:57 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 13:45:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_up(t_prompt *p)
{
	p->selection = 0;
	if (p->hist_curr == NULL)
	{
		p->hist_curr = p->history;
		if (p->line.length > 0)
		{
			prompt_history(p, p->line);
			p->hist_curr = p->history->prev;
		}
	}
	else if (p->hist_curr->prev == NULL)
		return ;
	else
		p->hist_curr = p->hist_curr->prev;
	ft_dstrpop(&(p->line), -1);
	ft_dstradd(&(p->line), p->hist_curr->str, p->hist_curr->length);
	p->cursor = p->line.length;
}

void			key_right(t_prompt *p)
{
	p->selection = 0;
	if (p->cursor < p->line.length)
		p->cursor++;
}

void			key_down(t_prompt *p)
{
	p->selection = 0;
	if (p->hist_curr == NULL)
	{
		if (p->line.length > 0)
			prompt_history(p, p->line);
		ft_dstrpop(&(p->line), -1);
		return ;
	}
	p->hist_curr = p->hist_curr->next;
	ft_dstrpop(&(p->line), -1);
	if (p->hist_curr != NULL)
		ft_dstradd(&(p->line), p->hist_curr->str, p->hist_curr->length);
	p->cursor = p->line.length;
}

void			key_left(t_prompt *p)
{
	p->selection = 0;
	if (p->cursor > 0)
		p->cursor--;
}
