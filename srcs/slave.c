/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:06:10 by juloo             #+#    #+#             */
/*   Updated: 2015/06/16 00:32:13 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <unistd.h>
#include <pty.h>

t_bool			start_slave(t_j *j)
{
	pid_t			pid;
	struct winsize	win;

	if (ioctl(0, TIOCGWINSZ, &win) < 0)
		return (false);
	if ((pid = forkpty(&(j->master), NULL, &(j->term.save), &win)) < 0)
		return (false);
	if (pid == 0)
	{
		ft_exec(j->cmd, NULL);
		_exit(1);
	}
	j->pid = pid;
	return (true);
}
