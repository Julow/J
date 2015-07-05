/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_promptput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/05 17:55:37 by juloo             #+#    #+#             */
/*   Updated: 2015/07/05 19:38:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_colors.h"

t_val			ft_val(int from, int to)
{
	if (from > to)
		return (VAL(to, from));
	return (VAL(from, to));
}

t_val			ft_valrange(t_val val, int min, int max)
{
	if (min > max)
		return (ft_valrange(val, max, min));
	if (val.from < min)
		val.from = min;
	else if (val.from > max)
		val.from = max;
	if (val.to < min)
		val.to = min;
	else if (val.to > max)
		val.to = max;
	return (val);
}

t_val			ft_valmove(t_val val, int move)
{
	return (VAL(val.from + move, val.to + move));
}

int				ft_promptput(t_prompt *p, int max_width)
{
	t_val			val;
	int				i;
	t_val			selection;

	i = p->cursor + PROMPT_MARGIN;
	val = (i > max_width) ? VAL(i - max_width, i)
		: VAL(0, MIN(p->line.length, max_width));
	selection = (p->selection == 0) ? VAL(-1, val.from) : ft_valrange(
		ft_val(p->cursor, p->cursor + p->selection), val.from, val.to);
	i = val.from - 1;
	if (val.from > 0)
	{
		i++;
		PS(C_GRAY "#" C_RESET);
		if (selection.from == i)
			selection.from++;
	}
	while (++i < val.to)
	{
		if (i == selection.from)
			PS(BG_LMAGENTA);
		if (i == selection.to)
			PS(BG_RESET);
		PC(p->line.str[i]);
	}
	if (i == selection.to)
		PS(BG_RESET);
	return (p->cursor - val.from);
}
