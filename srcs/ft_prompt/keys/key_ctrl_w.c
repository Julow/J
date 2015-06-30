/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 11:59:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/30 12:08:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_w(t_prompt *p)
{
	t_val			val;

	val = prompt_word(p);
	if (val.from < p->cursor)
	{
		prompt_deletion(p, ft_dstrsub(&(p->line), val.from, p->cursor));
		ft_dstrset(&(p->line), val.from, p->cursor, SUBC(""));
		p->cursor = val.from;
	}
}
