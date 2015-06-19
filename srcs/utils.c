/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:11:50 by juloo             #+#    #+#             */
/*   Updated: 2015/06/20 01:11:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

t_val			j_word(t_j *j)
{
	t_val			val;
	t_is			c;

	val = VAL(j->cursor, j->cursor);
	c = (IS(j->line.str[val.from], IS_WORD)) ? IS_WORD : ~(IS_WORD | IS_SPACE);
	while (val.from > 0 && IS(j->line.str[val.from - 1], c))
		val.from--;
	while (val.to < j->line.length && IS(j->line.str[val.to], c))
		val.to++;
	return (val);
}

t_val			j_word_motion(t_j *j)
{
	t_val			val;

	val = VAL(j->cursor, j->cursor);
	while (val.from > 0 && IS(j->line.str[val.from - 1], IS_CNTRL))
		val.from--;
	while (val.from > 0 && IS(j->line.str[val.from - 1], IS_SPACE))
		val.from--;
	while (val.from > 0 && IS(j->line.str[val.from - 1], IS_PUNCT))
		val.from--;
	while (val.from > 0 && IS(j->line.str[val.from - 1], IS_WORD))
		val.from--;
	while (val.to < j->line.length && IS(j->line.str[val.to], IS_CNTRL))
		val.to++;
	while (val.to < j->line.length && IS(j->line.str[val.to], IS_SPACE))
		val.to++;
	while (val.to < j->line.length && IS(j->line.str[val.to], IS_PUNCT))
		val.to++;
	while (val.to < j->line.length && IS(j->line.str[val.to], IS_WORD))
		val.to++;
	return (val);
}
