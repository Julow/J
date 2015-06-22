/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 21:22:57 by juloo             #+#    #+#             */
/*   Updated: 2015/06/22 23:09:21 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include <stdlib.h>

void			key_tab(t_j *j)
{
	j_completion(j, 1);
}

void			key_shift_tab(t_j *j)
{
	j_completion(j, -1);
}

void			key_restore_tab(t_j *j, t_ulong key)
{
	if (j->tab_res == NULL || key == '\t' || key == KEY_SHIFT_TAB)
		return ;
	if (key == KEY_ESC)
		j_completion(j, j->tab_count - j->tab_curr - 1);
	ft_freeall(j->tab_res, j->tab_count, sizeof(t_dstr), &ft_dstrdestroy);
	free(j->tab_res);
	j->tab_res = NULL;
	j->tab_count = 0;
	j->tab_curr = 0;
}
