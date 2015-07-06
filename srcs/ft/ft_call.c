/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/06 15:52:22 by juloo             #+#    #+#             */
/*   Updated: 2015/07/06 16:28:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <unistd.h>
#include <wait.h>
#include <errno.h>

/*
** ft_call
** ----
** Execute a commande and wait
** ----
** Return the exit status of the command
**  or:
**   -1     an error occur
**   126    cannot exec
**   127    command not found
**   128+s  exit by signal s
*/
int			ft_call(char **cmd)
{
	pid_t		pid;
	int			status;

	if ((pid = fork()) < 0)
		return (-1);
	if (pid == 0)
	{
		if (ft_exec(cmd, NULL) == ENOENT)
			_exit(127);
		_exit(126);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (-1);
}
