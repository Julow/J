/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 21:22:57 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:19:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"
#include <stdlib.h>

void			key_tab(t_prompt *p)
{
	prompt_completion(p, 1);
}

void			key_shift_tab(t_prompt *p)
{
	prompt_completion(p, -1);
}

void			key_restore_tab(t_prompt *p, t_ulong key)
{
	if (p->tab_res == NULL || key == '\t' || key == KEY_SHIFT_TAB)
		return ;
	if (key == KEY_ESC)
		prompt_completion(p, p->tab_count - p->tab_curr - 1);
	ft_freeall(p->tab_res, p->tab_count, sizeof(t_dstr), &ft_dstrdestroy);
	free(p->tab_res);
	p->tab_res = NULL;
	p->tab_count = 0;
	p->tab_curr = 0;
}
