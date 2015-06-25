/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_eof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:31:09 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:18:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

void			key_eof(t_prompt *p, int key)
{
	if (p->line.length > 0)
		return ;
	ft_dstradd_char(&(p->line), (char)key);
	prompt_flush(p);
}
