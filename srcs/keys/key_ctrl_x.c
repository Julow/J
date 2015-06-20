/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:51:50 by juloo             #+#    #+#             */
/*   Updated: 2015/06/21 00:13:11 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void			key_ctrl_x(t_j *j)
{
	t_val			val;

	val = j_word(j);
	if (val.from < val.to)
	{
		j_deletion(j, ft_dstrsub(&(j->line), val.from, val.to));
		ft_dstrset(&(j->line), val.from, val.to, SUBC(""));
	}
	j->cursor = val.from;
}
