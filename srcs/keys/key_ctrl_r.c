/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 22:12:01 by juloo             #+#    #+#             */
/*   Updated: 2015/06/27 01:18:37 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

void			key_ctrl_r(t_j *j)
{
	t_sub			res;

	if (j_search(j, j->prompt.history, &res))
	{
		ft_dstrset(&(j->prompt.line), 0, -1, res);
		j->prompt.cursor = j->prompt.line.length;
	}
}
