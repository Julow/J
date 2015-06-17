/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 22:30:15 by juloo             #+#    #+#             */
/*   Updated: 2015/06/18 00:31:33 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

static int		scan_escape(t_j *j, t_sub output)
{
	if (ft_strstart(output.str, j->caps.te))
		return ((j->flags |= FLAG_TE), ft_strlen(j->caps.te));
	if (ft_strstart(output.str, j->caps.ti))
		return ((j->flags &= ~FLAG_TE), ft_strlen(j->caps.ti));
	return (1);
}

void			scan_output(t_j *j, t_sub output)
{
	int				i;
	int				line_i;
	int				c;

	line_i = j->line_start;
	i = -1;
	while (++i < output.length)
		if ((c = output.str[i]) == '\n' || c == '\r')
			line_i = 0;
		else if (c == '\033' || c == j->caps.te[0] || c == j->caps.ti[0])
			i += scan_escape(j, ft_sub(output.str, i, -1)) - 1;
		else
			line_i++;
	j->line_start = line_i;
}
