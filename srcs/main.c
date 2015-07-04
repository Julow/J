/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:45 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 16:55:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "msg.h"

static t_bool	init_caps(t_j *j)
{
	if ((j->caps.ch = tgetstr("ch", NULL)) == NULL
		|| (j->caps.ce = tgetstr("ce", NULL)) == NULL
		|| (j->caps.cl = tgetstr("cl", NULL)) == NULL)
		return (false);
	return (true);
}

static void		init_j(t_j *j)
{
	ft_promptinit(&(j->prompt), (t_prompt_events){
		.on_return = &j_flush,
		.data = j
	});
	ft_promptinit(&(j->search_prompt), (t_prompt_events){
		.data = j
	});
	ft_promptinit(&(j->ask_prompt), (t_prompt_events){
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
	if (!parse_argv(&j, argc, argv))
		return (2);
	init_j(&j);
	if (!start_slave(&j))
		return (ft_fdprintf(2, E_SLAVE), 1);
	ft_histload(&(j.prompt.history), HISTORY_FILE);
	ft_trestore(&(j.term), true);
	start_master(&j);
	ft_trestore(&(j.term), false);
	ft_histsave(j.prompt.history, HISTORY_FILE);
	return (0);
}
