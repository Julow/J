/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 21:22:57 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 20:08:49 by juloo            ###   ########.fr       */
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

void			key_restore_tab(t_prompt *p, t_key key)
{
	if (p->tab_res == NULL || ft_keyequ(key, KEY('\t', GETKEY_SHIFT))
		|| ft_keyequ(key, KEY('i', GETKEY_CTRL)))
		return ;
	if (key.c == GETKEY_ESC)
		prompt_completion(p, p->tab_count - p->tab_curr - 1);
	ft_freeall(p->tab_res, p->tab_count, sizeof(t_dstr), &ft_dstrdestroy);
	free(p->tab_res);
	p->tab_res = NULL;
	p->tab_count = 0;
	p->tab_curr = 0;
}
