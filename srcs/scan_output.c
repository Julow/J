/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 22:30:15 by juloo             #+#    #+#             */
/*   Updated: 2015/07/05 16:19:31 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

static int		scan_escape(t_sub output)
{
	int				len;

	output.length = MIN(output.length, MAX_ESCAPE_LEN);
	len = ft_subchr(output, IS_ALPHA);
	return ((len <= 0) ? output.length : len + 1);
}

void			scan_output(t_j *j, t_sub output)
{
	int				i;
	int				line_i;
	int				flushed;
	int				c;

	line_i = j->cursor_start;
	flushed = 0;
	i = -1;
	while (++i < output.length)
		if ((c = output.str[i]) == '\n' || c == '\r')
		{
			ft_dstradd(&(j->current_line), output.str + flushed, i - flushed);
			j_output_line(j);
			j->flags |= FLAG_RETURN;
			line_i = 0;
			if ((i + 1) < output.length && output.str[i] != output.str[i + 1])
				i++;
			flushed = i + 1;
		}
		else if (c == '\033')
			i += scan_escape(ft_sub(output.str, i, -1)) - 1;
		else
			line_i++;
	ft_dstradd(&(j->current_line), output.str + flushed, i - flushed);
	j->cursor_start = line_i % j->term.width;
}
