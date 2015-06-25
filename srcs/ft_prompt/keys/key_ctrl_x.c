/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:51:50 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:18:10 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_x(t_prompt *p)
{
	t_val			val;

	val = prompt_word(p);
	if (val.from < val.to)
	{
		prompt_deletion(p, ft_dstrsub(&(p->line), val.from, val.to));
		ft_dstrset(&(p->line), val.from, val.to, SUBC(""));
	}
	p->cursor = val.from;
}
