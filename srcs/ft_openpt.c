/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openpt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:50:05 by juloo             #+#    #+#             */
/*   Updated: 2015/06/17 13:24:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define _XOPEN_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define PTMX		"/dev/ptmx"

/*
** ft_openpt
** ----
** Open a pseudo-terminal (master/slave)
** ----
** Return false if something fail
** true otherwise
*/
t_bool			ft_openpt(int *master, int *slave)
{
	int				master_fd;
	struct winsize	win;

	*master = -1;
	*slave = -1;
	if (ioctl(0, TIOCGWINSZ, &win) < 0)
		return (false);
	if ((master_fd = open(PTMX, O_RDWR)) < 0)
		return (false);
	if (grantpt(master_fd) < 0)
		return (false);
	if (unlockpt(master_fd) < 0)
		return (false);
	if ((*slave = open(ptsname(master_fd), O_RDWR)) < 0)
		return (false);
	if (ioctl(master_fd, TIOCSWINSZ, &win) < 0)
		return (false);
	*master = master_fd;
	return (true);
}
