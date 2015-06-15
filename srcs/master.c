/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:30:46 by juloo             #+#    #+#             */
/*   Updated: 2015/06/16 00:37:35 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <unistd.h>
#include <sys/select.h>

void			start_master(t_j *j)
{
	fd_set			fd_read;
	char			buff[512];
	int				len;

	while (true)
	{
		FD_ZERO(&fd_read);
		FD_SET(0, &fd_read);
		FD_SET(j->master, &fd_read);
		if (select(j->master + 1, &fd_read, NULL, NULL, NULL) < 0)
			continue ;
		if (FD_ISSET(0, &fd_read))
		{
			if ((len = read(0, buff, len)) <= 0)
				break ;
			write(j->master, buff, len);
		}
		if (FD_ISSET(j->master, &fd_read))
		{
			if ((len = read(j->master, buff, len)) <= 0)
				break ;
			write(1, buff, len);
		}
	}
}
