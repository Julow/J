/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:30:46 by juloo             #+#    #+#             */
/*   Updated: 2015/06/18 01:26:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <unistd.h>
#include <sys/select.h>

static t_bool	read_stdin(t_j *j)
{
	int				key;
	int				len;

	key = 0;
	if ((len = read(0, &key, sizeof(int))) <= 0)
		return (false);
	if (j->flags & FLAG_TI)
		return (write(j->master, &key, len), true);
	handle_key(j, key);
	j_set(j, J_REFRESH);
	return (true);
}

static t_bool	read_slave(t_j *j)
{
	char			buff[MASTER_BUFF + 1];
	int				len;

	if ((len = read(j->master, buff, MASTER_BUFF)) <= 0)
		return (false);
	buff[len] = '\0';
	if (!(j->flags & FLAG_TI))
		j_set(j, J_HIDE);
	scan_output(j, SUB(buff, len));
	write(1, buff, len);
	if (!(j->flags & FLAG_TI))
		j_set(j, J_SHOW);
	return (true);
}

void			start_master(t_j *j)
{
	fd_set			fd_read;

	while (true)
	{
		FD_ZERO(&fd_read);
		FD_SET(0, &fd_read);
		FD_SET(j->master, &fd_read);
		if (select(j->master + 1, &fd_read, NULL, NULL, NULL) < 0)
			continue ;
		if (FD_ISSET(0, &fd_read) && !read_stdin(j))
			break ;
		if (FD_ISSET(j->master, &fd_read) && !read_slave(j))
			break ;
	}
}
