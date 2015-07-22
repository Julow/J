/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_set.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 22:09:40 by juloo             #+#    #+#             */
/*   Updated: 2015/07/07 22:47:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_colors.h"

void			j_set(t_j *j, int flags)
{
	int				cursor;

	if (flags & J_ERASE)
	{
		PS(tgoto(j->caps.ch, 0, 0));
		PS(j->caps.ce);
	}
	else if (flags & J_HIDE)
	{
		PS(tgoto(j->caps.ch, 0, j->cursor_start));
		PS(j->caps.ce);
	}
	if (flags & J_PS1)
		PN(j->current_line.str, j->current_line.length);
	if (flags & J_SHOW)
	{
		cursor = ft_promptput(&(j->prompt), j->term.width - j->cursor_start);
		PS(tgoto(j->caps.ch, 0, cursor + j->cursor_start));
	}
	FL;
}
