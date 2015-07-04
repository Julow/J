/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_promptinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 22:24:28 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 19:53:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			ft_promptinit(t_prompt *p, t_prompt_events events)
{
	ft_bzero(p, sizeof(t_prompt));
	p->events = events;
	p->line = DSTR0();
	p->history = NULL;
	p->hist_curr = NULL;
}
