/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_set.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 22:09:40 by juloo             #+#    #+#             */
/*   Updated: 2015/07/05 18:06:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_colors.h"

void			j_set(t_j *j, int flags)
{
	int				cursor;

	if (flags & J_HIDE)
	{
		PS(tgoto(j->caps.ch, 0, j->cursor_start));
		PS(j->caps.ce);
	}
	if (flags & J_SHOW)
	{
		cursor = ft_promptput(&(j->prompt), j->term.width - j->cursor_start);
		PS(tgoto(j->caps.ch, 0, cursor + j->cursor_start));
	}
	FL;
}
