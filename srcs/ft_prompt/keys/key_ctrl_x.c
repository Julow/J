/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:51:50 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 16:53:54 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_x(t_prompt *p)
{
	if (p->selection != 0)
	{
		key_ctrl_w(p);
		return ;
	}
	ft_histadd(&(p->clipboard), ft_dstrsub(&(p->line), 0, -1));
	ft_dstrpop(&(p->line), -1);
	p->cursor = 0;
}
