/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 11:59:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/30 15:09:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_w(t_prompt *p)
{
	t_val			val;

	if (p->selection != 0)
	{
		val.from = MIN(p->cursor, p->cursor + p->selection);
		if (p->selection > 0)
			p->cursor += p->selection;
		val.to = p->cursor;
		p->selection = 0;
	}
	else
		val = prompt_word(p);
	if (val.from < p->cursor)
	{
		prompt_deletion(p, ft_dstrsub(&(p->line), val.from, p->cursor));
		ft_dstrset(&(p->line), val.from, p->cursor, SUBC(""));
		p->cursor = val.from;
	}
}
