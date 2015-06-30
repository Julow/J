/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:11:15 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 17:16:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_delete(t_prompt *p)
{
	t_val			val;

	if (p->selection != 0)
	{
		key_delete_selection(p);
		return ;
	}
	val = prompt_word(p);
	if (val.to > p->cursor)
		ft_dstrset(&(p->line), p->cursor, val.to, SUBC(""));
}

void			key_ctrl_backspace(t_prompt *p)
{
	t_val			val;

	if (p->selection != 0)
	{
		key_delete_selection(p);
		return ;
	}
	val = prompt_word(p);
	if (val.from < p->cursor)
		ft_dstrset(&(p->line), val.from, p->cursor, SUBC(""));
	p->cursor = val.from;
}
