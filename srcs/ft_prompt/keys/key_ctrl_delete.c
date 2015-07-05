/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:11:15 by juloo             #+#    #+#             */
/*   Updated: 2015/07/05 20:40:40 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_delete(t_prompt *p)
{
	t_range			range;

	if (p->selection != 0)
	{
		key_delete_selection(p);
		return ;
	}
	range = prompt_word(p);
	if (range.to > p->cursor)
		ft_dstrset(&(p->line), p->cursor, range.to, SUBC(""));
}

void			key_ctrl_backspace(t_prompt *p)
{
	t_range			range;

	if (p->selection != 0)
	{
		key_delete_selection(p);
		return ;
	}
	range = prompt_word(p);
	if (range.from < p->cursor)
		ft_dstrset(&(p->line), range.from, p->cursor, SUBC(""));
	p->cursor = range.from;
}
