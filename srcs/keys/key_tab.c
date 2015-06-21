/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 21:22:57 by juloo             #+#    #+#             */
/*   Updated: 2015/06/21 22:35:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include <stdlib.h>

void			key_tab(t_j *j)
{
	if (j->tab_res != NULL)
	{
		j->cursor -= j->tab_res[j->tab_curr].length;
		ft_dstrset(&(j->line), j->cursor,
			j->cursor + j->tab_res[j->tab_curr].length, SUBC(""));
		j->tab_curr++;
	}
	else if (!j_glob(j))
		return ;
	if (j->tab_curr >= j->tab_count)
		j->tab_curr = 0;
	ft_dstrset(&(j->line), j->cursor, j->cursor,
		ft_dstrsub(j->tab_res + j->tab_curr, 0, -1));
	j->cursor += j->tab_res[j->tab_curr].length;
}

void			key_restore_tab(t_j *j, t_ulong key)
{
	if (j->tab_res == NULL || key == '\t')
		return ;
	ft_freeall(j->tab_res, j->tab_count, sizeof(t_dstr), &ft_dstrdestroy);
	free(j->tab_res);
	j->tab_res = NULL;
	j->tab_count = 0;
	j->tab_curr = 0;
}
