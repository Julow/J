/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:11:15 by juloo             #+#    #+#             */
/*   Updated: 2015/06/20 00:26:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void			key_ctrl_delete(t_j *j)
{
	t_val			val;

	val	= j_word(j);
	if (val.to > j->cursor)
		ft_dstrset(&(j->line), j->cursor, val.to, SUBC(""));
}

void			key_ctrl_backspace(t_j *j)
{
	t_val			val;

	val	= j_word(j);
	if (val.from < j->cursor)
		ft_dstrset(&(j->line), val.from, j->cursor, SUBC(""));
	j->cursor = val.from;
}
