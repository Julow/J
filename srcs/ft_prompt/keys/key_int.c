/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:35:49 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 19:53:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_int(t_prompt *p)
{
	p->selection = 0;
	if (p->line.length > 0)
	{
		ft_dstrpop(&(p->line), -1);
		p->cursor = 0;
		return ;
	}
	ft_dstradd_char(&(p->line), 0x3);
	prompt_flush(p);
}
