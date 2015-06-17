/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_refresh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 22:09:40 by juloo             #+#    #+#             */
/*   Updated: 2015/06/18 00:30:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

void			j_set(t_j *j, int flags)
{
	if (flags & J_HIDE)
	{
		PS(tgoto(tgetstr("ch", NULL), 0, j->line_start));
		PS(j->caps.ce);
	}
	if (flags & J_SHOW)
	{
		PN(j->line.str, j->line.length);
		PS(tgoto(tgetstr("ch", NULL), 0, j->cursor + j->line_start));
	}
	FL;
}
