/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:05:14 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 13:46:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_y(t_prompt *p)
{
	p->selection = 0;
	if (p->deletions == NULL)
		return ;
	ft_dstrset(&(p->line), p->cursor, p->cursor,
		SUB(p->deletions->str, p->deletions->length));
	p->cursor += p->deletions->length;
}
