/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:06:10 by juloo             #+#    #+#             */
/*   Updated: 2015/06/23 23:56:54 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <unistd.h>
#include <sys/ioctl.h>

t_bool			start_slave(t_j *j)
{
	struct winsize	win;
	int				slave;

	if (!ft_openpt(&(j->master), &slave))
		return (false);
	if (ioctl(0, TIOCGWINSZ, &win) < 0)
		return (false);
	if ((j->slave_pid = fork()) < 0)
		return (false);
	if (j->slave_pid == 0)
	{
		dup2(slave, 0);
		dup2(slave, 1);
		dup2(slave, 2);
		close(slave);
		setsid();
		ioctl(0, TIOCSCTTY, 1);
		ft_exec(j->cmd, NULL);
		_exit(1);
	}
	close(slave);
	return (true);
}
