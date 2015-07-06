/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/06 20:26:57 by juloo             #+#    #+#             */
/*   Updated: 2015/07/06 21:45:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_prompt_keys.h"
#include <unistd.h>

static void		print_outputs(t_j *j)
{
	int				i;
	int				y;
	t_hist			*tmp;

	PS(j->caps.cl);
	y = j->term.height - 1;
	i = -1;
	while (++i < OUTPUT_MAX)
	{
		tmp = j->output[i];
		while (y > 0 && tmp != NULL)
		{
			PS(tgoto(j->caps.cm, 3, --y));
			PN(tmp->str, tmp->length);
			PC('\n');
			tmp = tmp->prev;
		}
		y--;
	}
	PS(tgoto(j->caps.cm, 0, j->term.height - 1));
	PS("SEARCH > ");
	PS(tgoto(j->caps.ch, 0,
		ft_promptput(&(j->ctrl_p_prompt), j->term.width - 9) + 9));
	FL;
}

void			key_ctrl_p(t_j *j)
{
	t_ulong			key;

	PS(j->caps.ti);
	while (true)
	{
		print_outputs(j);
		key = 0;
		if (read(0, &key, sizeof(t_ulong)) <= 0 || key == KEY_CTRL_D
			|| key == KEY_CTRL_C || key == KEY_ESC)
			break ;
		ft_promptkey(&(j->ctrl_p_prompt), key);
	}
	PS(j->caps.te);
}
