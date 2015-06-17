/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:45 by juloo             #+#    #+#             */
/*   Updated: 2015/06/18 00:21:14 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "msg.h"

#define TSTR_SUB(j,c)	((j->caps.c = tgetstr(#c, NULL)) == NULL)

static t_bool	init_caps(t_j *j)
{
	if (TSTR_SUB(j, ch) || TSTR_SUB(j, ce) || TSTR_SUB(j, te)
		|| TSTR_SUB(j, ti))
		return (false);
	return (true);
}

static void		init_j(t_j *j)
{
	j->line = DSTR0();
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
	ft_trestore(&(j.term), true);
	if (!start_slave(&j))
		return (ft_trestore(&(j.term), false), ft_fdprintf(2, E_SLAVE), 1);
	start_master(&j);
	ft_trestore(&(j.term), false);
	return (0);
}
