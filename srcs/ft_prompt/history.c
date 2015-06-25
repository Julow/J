/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 22:49:15 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:20:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			prompt_history(t_prompt *p, t_dstr str)
{
	t_hist			*hist;

	hist = ft_emalloc(str.length + 1 + sizeof(t_hist));
	*hist = (t_hist){
		p->history,
		NULL,
		((void*)hist) + sizeof(t_hist),
		str.length
	};
	ft_memcpy(hist->str, str.str, str.length + 1);
	p->history->next = hist;
	p->history = hist;
	p->hist_curr = NULL;
}
