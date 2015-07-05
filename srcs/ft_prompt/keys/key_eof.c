/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_eof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:31:09 by juloo             #+#    #+#             */
/*   Updated: 2015/07/05 20:40:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_eof(t_prompt *p, int key)
{
	t_range			word;

	if (p->line.length > 0)
	{
		word = prompt_word(p);
		p->cursor = word.to;
		p->selection = -(word.to - word.from);
		return ;
	}
	ft_dstradd_char(&(p->line), (char)key);
	prompt_flush(p);
}
