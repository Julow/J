/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:14:15 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 15:39:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			prompt_flush(t_prompt *p)
{
	if (p->events.on_return != NULL)
		p->events.on_return(p->events.data);
	ft_dstrpop(&(p->line), -1);
	p->hist_curr = NULL;
	p->selection = 0;
	p->cursor = 0;
}
