/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:51:50 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 15:12:49 by jaguillo         ###   ########.fr       */
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
	prompt_deletion(p, ft_dstrsub(&(p->line), 0, -1));
	ft_dstrpop(&(p->line), -1);
	p->cursor = 0;
}
