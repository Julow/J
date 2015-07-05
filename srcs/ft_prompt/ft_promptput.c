/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_promptput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/05 17:55:37 by juloo             #+#    #+#             */
/*   Updated: 2015/07/05 20:36:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_colors.h"

int				ft_promptput(t_prompt *p, int max_width)
{
	t_range			range;
	int				i;
	t_range			selection;

	i = p->cursor + PROMPT_MARGIN;
	range = (i > max_width) ? RANGE(i - max_width, i)
		: RANGE(0, MIN(p->line.length, max_width));
	selection = ft_rangelimit(ft_range(p->cursor, p->cursor + p->selection),
		range);
	i = range.from;
	if (range.from > 0)
	{
		PS(C_GRAY "#" C_RESET);
		i++;
	}
	while (i < selection.from)
		PC(p->line.str[i++]);
	PS(BG_LMAGENTA);
	while (i < selection.to)
		PC(p->line.str[i++]);
	PS(BG_RESET);
	while (i < range.to)
		PC(p->line.str[i++]);
	return (p->cursor - range.from);
}
