/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:05:14 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 16:48:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_y(t_prompt *p)
{
	if (p->deletions == NULL)
		return ;
	p->deletions = p->deletions;
	ft_dstrset(&(p->line), p->cursor, p->cursor + p->selection,
		SUB(p->deletions->str, p->deletions->length));
	p->cursor = p->deletions->length + MIN(p->selection + p->cursor, p->cursor);
	p->selection = 0;
}
