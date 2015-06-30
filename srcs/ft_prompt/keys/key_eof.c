/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_eof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:31:09 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 13:46:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_eof(t_prompt *p, int key)
{
	p->selection = 0;
	if (p->line.length > 0)
		return ;
	ft_dstradd_char(&(p->line), (char)key);
	prompt_flush(p);
}
