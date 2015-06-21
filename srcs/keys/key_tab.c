/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 21:22:57 by juloo             #+#    #+#             */
/*   Updated: 2015/06/22 01:15:35 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include <stdlib.h>

static void		tab_completion(t_j *j, int order)
{
	if (j->tab_res == NULL && !j_glob(j))
		return ;
	j->cursor -= j->tab_res[j->tab_curr].length;
	ft_dstrset(&(j->line), j->cursor,
		j->cursor + j->tab_res[j->tab_curr].length, SUBC(""));
	j->tab_curr += order;
	if (j->tab_curr < 0)
		j->tab_curr = j->tab_count - 1;
	if (j->tab_curr >= j->tab_count)
		j->tab_curr = 0;
	ft_dstrset(&(j->line), j->cursor, j->cursor,
		ft_dstrsub(j->tab_res + j->tab_curr, 0, -1));
	j->cursor += j->tab_res[j->tab_curr].length;
}

void			key_tab(t_j *j)
{
	tab_completion(j, 1);
}

void			key_shift_tab(t_j *j)
{
	tab_completion(j, -1);
}

void			key_restore_tab(t_j *j, t_ulong key)
{
	if (j->tab_res == NULL || key == '\t' || key == KEY_SHIFT_TAB)
		return ;
	ft_freeall(j->tab_res, j->tab_count, sizeof(t_dstr), &ft_dstrdestroy);
	free(j->tab_res);
	j->tab_res = NULL;
	j->tab_count = 0;
	j->tab_curr = 0;
}
