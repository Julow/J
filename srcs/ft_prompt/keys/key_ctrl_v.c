/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:05:14 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 16:56:53 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"
#include <stdlib.h>

void			key_ctrl_v(t_prompt *p)
{
	t_hist			*tmp;

	if (p->clipboard == NULL)
		return ;
	tmp = p->clipboard;
	ft_dstrset(&(p->line), p->cursor, p->cursor + p->selection,
		SUB(tmp->str, tmp->length));
	p->cursor = tmp->length + MIN(p->selection + p->cursor, p->cursor);
	p->selection = 0;
	p->clipboard = tmp->prev;
	free(tmp);
}
