/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_k.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:51:50 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 16:53:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_k(t_prompt *p)
{
	p->selection = 0;
	ft_histadd(&(p->clipboard), ft_dstrsub(&(p->line), p->cursor, -1));
	ft_dstrpop(&(p->line), p->line.length - p->cursor);
}
