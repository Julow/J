/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 22:37:14 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 22:59:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

static void		print_hist(t_hist *hist)
{
	if (hist == NULL)
		return ;
	while (hist->prev != NULL)
		hist = hist->prev;
	while (hist != NULL)
	{
		PN(hist->str, hist->length);
		PS("\n\r");
		hist = hist->next;
	}
	FL;
}

void			key_debug(t_j *j)
{
	int				i;

	i = -1;
	PS("\n\r");
	while (++i < OUTPUT_MAX)
	{
		ft_printf(" --> output #%d\n\r", i);
		print_hist(j->output[i]);
	}
	ft_printf(" --> current output (len: %d)\n\r", j->output_curr_len);
	print_hist(j->output_curr);
	ft_printf(" --> current line (len: %d): %.*s\n\r", j->current_line.length,
		j->current_line.length, j->current_line.str);
}
