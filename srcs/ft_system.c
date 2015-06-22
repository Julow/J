/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 23:28:23 by juloo             #+#    #+#             */
/*   Updated: 2015/06/23 00:04:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <unistd.h>

t_dstr			ft_system(char **cmd)
{
	pid_t			pid;
	t_dstr			output;
	char			buff[FT_SYS_BUFF];
	int				fds[2];
	int				len;

	output = DSTR0();
	if (pipe(fds) < 0 || (pid = fork()) < 0)
		return (output);
	if (pid == 0)
	{
		close(fds[PIPE_READ]);
		dup2(fds[PIPE_WRITE], 1);
		dup2(fds[PIPE_WRITE], 2);
		ft_exec(cmd, NULL);
		_exit(0);
	}
	close(fds[PIPE_WRITE]);
	while ((len = read(fds[PIPE_READ], buff, FT_SYS_BUFF)) > 0)
		ft_dstradd(&output, buff, len);
	close(fds[PIPE_READ]);
	return (output);
}
