/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:30:46 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 00:23:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_prompt_keys.h"
#include "ft_getkey.h"
#include <unistd.h>
#include <sys/select.h>

static t_bool	read_stdin(t_j *j)
{
	t_ulong			key;
	int				len;

	key = 0;
	len = 0; // TEST
	// if ((len = read(0, &key, sizeof(t_ulong))) <= 0)
	// 	return (false);
	if (key == KEY_CTRL_SPACE)
		j->flags ^= FLAG_TI;
	if (j->flags & FLAG_TI)
		return (write(j->master, &key, len), true);
	// j_key(j, key);
	// j_set(j, J_REFRESH);
	{ // TEST
		t_key			k = ft_getkey();

		ft_printf("\r\nKey: %x (%c) (%d, %d, %d)", k.c, (char)k.c, k.ctrl, k.shift, k.alt);
		if (k.c == 0)
			return (false);
	}
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

static void		history_save(t_j *j)
{
	time_t			t;

	t = time(NULL);
	if ((t - j->history_timeout) > HISTORY_TIMEOUT)
	{
		ft_histtrunc(&(j->prompt.history), j->history_max);
		ft_histsave(j->prompt.history, SUBC(j->history_file));
		j->history_timeout = t;
	}
}

void			start_master(t_j *j)
{
	fd_set			fd_read;

	while (true)
	{
		FD_ZERO(&fd_read);
		FD_SET(0, &fd_read);
		FD_SET(j->master, &fd_read);
		if (select(j->master + 1, &fd_read, NULL, NULL,
			&(struct timeval)SELECT_TIMEOUT) < 0)
			continue ;
		if (FD_ISSET(0, &fd_read) && !read_stdin(j))
			break ;
		if (FD_ISSET(j->master, &fd_read) && !read_slave(j))
			break ;
		history_save(j);
	}
}
