/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_set.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 22:09:40 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 15:10:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_colors.h"

static void		ft_promptput(t_prompt *p)
{
	int				tmp;

	tmp = MIN(p->cursor, p->cursor + p->selection);
	if (tmp > 0)
		PN(p->line.str, tmp);
	if (p->selection != 0)
	{
		PS(BG_LMAGENTA);
		PN(p->line.str + tmp, ABS(p->selection));
		PS(BG_RESET);
		tmp += ABS(p->selection);
	}
	PN(p->line.str + tmp, p->line.length - tmp);
}

void			j_set(t_j *j, int flags)
{
	if (flags & J_HIDE)
	{
		PS(tgoto(j->caps.ch, 0, j->line_start));
		PS(j->caps.ce);
	}
	if (flags & J_SHOW)
	{
		ft_promptput(&(j->prompt));
		PS(tgoto(j->caps.ch, 0, j->prompt.cursor + j->line_start));
	}
	FL;
}
