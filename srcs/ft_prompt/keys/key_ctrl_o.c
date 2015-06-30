/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 00:36:19 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 13:45:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_o(t_prompt *p)
{
	p->selection = 0;
	prompt_deletion(p, ft_dstrsub(&(p->line), 0, p->cursor));
	ft_dstrset(&(p->line), 0, p->cursor, SUBC(""));
	p->cursor = 0;
}
