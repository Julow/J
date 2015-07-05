/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:11:50 by juloo             #+#    #+#             */
/*   Updated: 2015/07/05 20:38:17 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

t_range			prompt_word(t_prompt *p)
{
	t_range			range;

	range = RANGE(p->cursor, p->cursor);
	while (range.from > 0 && IS(p->line.str[range.from - 1], IS_CNTRL))
		range.from--;
	while (range.from > 0 && IS(p->line.str[range.from - 1], IS_SPACE))
		range.from--;
	while (range.from > 0 && IS(p->line.str[range.from - 1], IS_PUNCT))
		range.from--;
	while (range.from > 0 && IS(p->line.str[range.from - 1], IS_WORD))
		range.from--;
	while (range.to < p->line.length && IS(p->line.str[range.to], IS_CNTRL))
		range.to++;
	while (range.to < p->line.length && IS(p->line.str[range.to], IS_SPACE))
		range.to++;
	while (range.to < p->line.length && IS(p->line.str[range.to], IS_PUNCT))
		range.to++;
	while (range.to < p->line.length && IS(p->line.str[range.to], IS_WORD))
		range.to++;
	return (range);
}
