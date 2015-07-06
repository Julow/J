/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_resize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/06 22:18:20 by juloo             #+#    #+#             */
/*   Updated: 2015/07/07 00:32:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <signal.h>
#include <sys/ioctl.h>

static t_j		*save_j(t_j *j)
{
	static t_j		*save = NULL;

	if (save == NULL)
		save = j;
	return (save);
}

static void		resize_handler(int sig)
{
	t_j				*j;
	struct winsize	size;

	j = save_j(NULL);
	ft_tupdate(&(j->term));
	kill(j->slave_pid, sig);
	size.ws_col = j->term.width;
	size.ws_row = j->term.height;
	ioctl(j->master, TIOCSWINSZ, &size);
}

void			j_resize(t_j *j)
{
	save_j(j);
	signal(28, &resize_handler);
}
