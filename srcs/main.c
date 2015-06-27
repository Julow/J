/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:45 by juloo             #+#    #+#             */
/*   Updated: 2015/06/27 23:32:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "msg.h"

static t_bool	init_caps(t_j *j)
{
	if ((j->caps.ch = tgetstr("ch", NULL)) == NULL
		|| (j->caps.ce = tgetstr("ce", NULL)) == NULL
		|| (j->caps.cm = tgetstr("cm", NULL)) == NULL
		|| (j->caps.cl = tgetstr("cl", NULL)) == NULL
		|| (j->caps.vi = tgetstr("vi", NULL)) == NULL
		|| (j->caps.ve = tgetstr("ve", NULL)) == NULL
		|| (j->caps.ti = tgetstr("ti", NULL)) == NULL
		|| (j->caps.te = tgetstr("te", NULL)) == NULL)
		return (false);
	return (true);
}

static void		init_j(t_j *j)
{
	ft_promptinit(&(j->prompt), (t_prompt_events){
		.on_return = &j_flush,
		.data = j
	});
	ft_tmakeraw(&(j->term));
}

int				main(int argc, char **argv)
{
	t_j				j;

	ft_bzero(&j, sizeof(t_j));
	if (!ft_tinit(&(j.term)) || !init_caps(&j))
		return (ft_fdprintf(2, E_TERM), 1);
	init_j(&j);
	if (!parse_argv(&j, argc, argv))
		return (2);
	if (!start_slave(&j))
		return (ft_fdprintf(2, E_SLAVE), 1);
	ft_trestore(&(j.term), true);
	start_master(&j);
	ft_trestore(&(j.term), false);
	return (0);
}
