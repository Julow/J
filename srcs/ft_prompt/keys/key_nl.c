/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_nl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:10:22 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 19:52:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_nl(t_prompt *p)
{
	if (p->line.length > 0)
		ft_histadd(&(p->history), ft_dstrsub(&(p->line), 0, -1));
	ft_dstradd_char(&(p->line), '\n');
	prompt_flush(p);
}
