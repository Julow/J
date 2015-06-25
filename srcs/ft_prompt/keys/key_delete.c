/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 22:52:12 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:18:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_delete(t_prompt *p)
{
	if (p->cursor >= p->line.length)
		return ;
	ft_dstrset(&(p->line), p->cursor, p->cursor + 1, SUBC(""));
	p->cursor = MIN(p->cursor, p->line.length);
}

void			key_backspace(t_prompt *p)
{
	if (p->cursor <= 0 || p->line.length <= 0)
		return ;
	ft_dstrset(&(p->line), p->cursor - 1, p->cursor, SUBC(""));
	p->cursor = MAX(p->cursor - 1, 0);
}
