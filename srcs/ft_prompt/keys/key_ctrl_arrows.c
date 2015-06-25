/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_arrows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 23:47:21 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:17:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_ctrl_left(t_prompt *p)
{
	p->cursor = prompt_word_motion(p).from;
}

void			key_ctrl_right(t_prompt *p)
{
	p->cursor = prompt_word_motion(p).to;
}
