/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_shift_arrows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 13:03:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/30 18:08:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_shift_right(t_prompt *p)
{
	if (p->cursor >= p->line.length)
		return ;
	p->cursor++;
	p->selection--;
}

void			key_shift_left(t_prompt *p)
{
	if (p->cursor <= 0)
		return ;
	p->cursor--;
	p->selection++;
}

void			key_ctrl_shift_right(t_prompt *p)
{
	t_val			word;

	word = prompt_word(p);
	word.to = word.to - p->cursor;
	p->selection -= word.to;
	p->cursor += word.to;
}

void			key_ctrl_shift_left(t_prompt *p)
{
	t_val			word;

	word = prompt_word(p);
	word.from = p->cursor - word.from;
	p->selection += word.from;
	p->cursor -= word.from;
}
