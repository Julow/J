/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_refresh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 22:09:40 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:23:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

void			j_set(t_j *j, int flags)
{
	if (flags & J_HIDE)
	{
		PS(tgoto(j->caps.ch, 0, j->line_start));
		PS(j->caps.ce);
	}
	if (flags & J_SHOW)
	{
		PN(j->prompt.line.str, j->prompt.line.length);
		PS(tgoto(j->caps.ch, 0, j->prompt.cursor + j->line_start));
	}
	FL;
}
