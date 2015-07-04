/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:05:14 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 16:57:01 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_y(t_prompt *p)
{
	if (p->clipboard == NULL)
		return ;
	p->clipboard = p->clipboard;
	ft_dstrset(&(p->line), p->cursor, p->cursor + p->selection,
		SUB(p->clipboard->str, p->clipboard->length));
	p->cursor = p->clipboard->length + MIN(p->selection + p->cursor, p->cursor);
	p->selection = 0;
}
