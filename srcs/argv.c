/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 23:41:30 by juloo             #+#    #+#             */
/*   Updated: 2015/07/25 23:08:15 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_argv.h"
#include "msg.h"
#include <stdlib.h>

static t_bool	arg_history(t_j *j, t_args *args, char *opt, char *arg)
{
	if (ft_strequ(opt, "history-max"))
	{
		if (!ft_sisint(arg) || *arg == '-')
			return (ft_fdprintf(2, E_ARG, args->argv[0], opt, "Invalid value"),
				false);
		j->history_max = ft_atoi(arg);
	}
	else
		j->history_file = arg;
	return (true);
}

static t_bool	arg_help(void)
{
	ft_exec((char*[3]){"man", "j", NULL}, NULL);
	P(E_MAN);
	exit(1);
	return (false);
}

static char		*g_default_cmd[] = {"cat", NULL};

static t_opt	g_opts[] = {
	{"h", "help", false, &arg_help},
	{"H", "history-file", true, &arg_history},
	{"history-max", NULL, true, &arg_history}
};

t_bool			parse_argv(t_j *j, int argc, char **argv)
{
	t_args			args;

	args = ARGS(argc, argv);
	if (!ft_argv(&args, g_opts, sizeof(g_opts) / sizeof(t_opt), j))
		return (false);
	j->cmd = (ARGS_END(args)) ? g_default_cmd : argv + args.c;
	return (true);
}
