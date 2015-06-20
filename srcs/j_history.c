/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_history.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 22:49:15 by juloo             #+#    #+#             */
/*   Updated: 2015/06/20 23:49:37 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <stdlib.h>

void			j_history(t_j *j, t_dstr str)
{
	t_hist			*hist;

	hist = malloc(str.length + 1 + sizeof(t_hist));
	*hist = (t_hist){
		j->history,
		NULL,
		((void*)hist) + sizeof(t_hist),
		str.length
	};
	ft_memcpy(hist->str, str.str, str.length + 1);
	j->history->next = hist;
	j->history = hist;
	j->hist_curr = NULL;
	if (j->flags & FLAG_DEBUG)
	{
		ft_printf("\r\nSave line in history\r\n");
		t_hist		*tmp = j->history;
		while (tmp != NULL)
		{
			ft_printf("%s\n", tmp->str);
			tmp = tmp->prev;
		}
	}
}
