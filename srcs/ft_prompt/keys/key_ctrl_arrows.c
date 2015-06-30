/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_arrows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 23:47:21 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 13:45:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_left(t_prompt *p)
{
	p->selection = 0;
	p->cursor = prompt_word(p).from;
}

void			key_ctrl_right(t_prompt *p)
{
	p->selection = 0;
	p->cursor = prompt_word(p).to;
}
