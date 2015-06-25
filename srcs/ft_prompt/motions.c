/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:11:50 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:19:51 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

t_val			prompt_word(t_prompt *p)
{
	t_val			val;
	t_is			c;

	val = VAL(p->cursor, p->cursor);
	c = (IS(p->line.str[val.from], IS_WORD)) ? IS_WORD : ~(IS_WORD | IS_SPACE);
	while (val.from > 0 && IS(p->line.str[val.from - 1], c))
		val.from--;
	while (val.to < p->line.length && IS(p->line.str[val.to], c))
		val.to++;
	return (val);
}

t_val			prompt_word_motion(t_prompt *p)
{
	t_val			val;

	val = VAL(p->cursor, p->cursor);
	while (val.from > 0 && IS(p->line.str[val.from - 1], IS_CNTRL))
		val.from--;
	while (val.from > 0 && IS(p->line.str[val.from - 1], IS_SPACE))
		val.from--;
	while (val.from > 0 && IS(p->line.str[val.from - 1], IS_PUNCT))
		val.from--;
	while (val.from > 0 && IS(p->line.str[val.from - 1], IS_WORD))
		val.from--;
	while (val.to < p->line.length && IS(p->line.str[val.to], IS_CNTRL))
		val.to++;
	while (val.to < p->line.length && IS(p->line.str[val.to], IS_SPACE))
		val.to++;
	while (val.to < p->line.length && IS(p->line.str[val.to], IS_PUNCT))
		val.to++;
	while (val.to < p->line.length && IS(p->line.str[val.to], IS_WORD))
		val.to++;
	return (val);
}
