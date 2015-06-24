/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_refresh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 21:54:41 by juloo             #+#    #+#             */
/*   Updated: 2015/06/24 23:55:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ft_proc.h"
#include <unistd.h>

void			key_refresh(t_j *j)
{
	char			cwd[PROC_PATH_LEN];

	if (!(j->flags & FLAG_RETURN))
		return ;
	if (ft_pidpath(j->slave_pid, cwd, PROC_PATH_LEN) <= 0)
		return ;
	chdir(cwd);
}
