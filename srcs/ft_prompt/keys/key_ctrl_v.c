/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:05:14 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:17:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_v(t_prompt *p)
{
	if (p->deletions == NULL)
		return ;
	ft_dstrset(&(p->line), p->cursor, p->cursor,
		SUB(p->deletions->str, p->deletions->length));
	p->cursor += p->deletions->length;
}
