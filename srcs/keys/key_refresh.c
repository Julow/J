/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_refresh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 21:54:41 by juloo             #+#    #+#             */
/*   Updated: 2015/06/24 00:01:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "ft_proc.h"
#include <stdlib.h>
#include <unistd.h>

void			key_refresh(t_j *j)
{
	char			*tmp;

	if (!(j->flags & FLAG_RETURN))
		return ;
	j->flags &= ~FLAG_RETURN;
	tmp = ft_pidpath(j->slave_pid);
	if (j->cwd != NULL)
	{
		if (!ft_strequ(j->cwd, tmp))
			chdir(tmp);
		free(j->cwd);
	}
	j->cwd = tmp;
}
