/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 22:52:12 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 13:46:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_delete(t_prompt *p)
{
	p->selection = 0;
	if (p->cursor >= p->line.length)
		return ;
	ft_dstrset(&(p->line), p->cursor, p->cursor + 1, SUBC(""));
	p->cursor = MIN(p->cursor, p->line.length);
}

void			key_backspace(t_prompt *p)
{
	p->selection = 0;
	if (p->cursor <= 0 || p->line.length <= 0)
		return ;
	ft_dstrset(&(p->line), p->cursor - 1, p->cursor, SUBC(""));
	p->cursor = MAX(p->cursor - 1, 0);
}
