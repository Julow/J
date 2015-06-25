/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 22:24:28 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:40:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			ft_promptinit(t_prompt *p, t_prompt_events events)
{
	ft_bzero(p, sizeof(t_prompt));
	p->events = events;
	p->line = DSTR0();
	p->history = MAL1(t_hist);
	*(p->history) = (t_hist){NULL, NULL, "", 0};
	p->hist_curr = NULL;
}
