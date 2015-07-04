/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_output.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 22:09:33 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 22:46:15 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

void			j_output_save(t_j *j)
{
	if (j->output[OUTPUT_MAX - 1] != NULL)
		ft_histdelete(j->output[OUTPUT_MAX - 1]);
	ft_memmove(j->output + 1, j->output, S(t_hist*, OUTPUT_MAX - 1));
	j->output[0] = j->output_curr;
	j->output_curr = NULL;
	j->output_curr_len = 0;
}

void			j_output_line(t_j *j)
{
	ft_histadd(&(j->output_curr), ft_dstrsub(&(j->current_line), 0, -1));
	ft_dstrpop(&(j->current_line), -1);
	j->output_curr_len++;
}
