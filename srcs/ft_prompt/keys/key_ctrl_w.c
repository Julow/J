/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 11:59:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/07/05 20:40:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_w(t_prompt *p)
{
	t_range			range;

	if (p->selection != 0)
	{
		range.from = MIN(p->cursor, p->cursor + p->selection);
		if (p->selection > 0)
			p->cursor += p->selection;
		range.to = p->cursor;
		p->selection = 0;
	}
	else
		range = prompt_word(p);
	if (range.from < p->cursor)
	{
		ft_histadd(&(p->clipboard),
			ft_dstrsub(&(p->line), range.from, p->cursor));
		ft_dstrset(&(p->line), range.from, p->cursor, SUBC(""));
		p->cursor = range.from;
	}
}
