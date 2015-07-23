/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/06 20:26:57 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 19:39:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_prompt_keys.h"
#include "ft_colors.h"
#include <unistd.h>

static void		put_hightlight(t_sub sub, t_sub pattern)
{
	int				i;

	i = -1;
	while (++i < sub.length)
	{
		if (pattern.length > 0 && sub.str[i] == pattern.str[0]
			&& (sub.length - pattern.length) >= i
			&& ft_memcmp(sub.str + i, pattern.str, pattern.length) == 0)
		{
			PS(BG_YELLOW);
			PN(pattern.str, pattern.length);
			PS(BG_RESET);
			i += pattern.length - 1;
		}
		else
			PC(sub.str[i]);
	}
}

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
			put_hightlight(SUB(tmp->str, tmp->length),
				SUB(j->ctrl_p_prompt.line.str, j->ctrl_p_prompt.line.length));
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
	t_key			key;

	PS(j->caps.ti);
	while (true)
	{
		print_outputs(j);
		key = ft_getkey();
		if (key.c == EOF || ft_keyequ(key, KEY('d', GETKEY_CTRL))
			|| ft_keyequ(key, KEY('c', GETKEY_CTRL)) || key.c == KEY_ESC)
			break ;
		ft_promptkey(&(j->ctrl_p_prompt), key);
	}
	PS(j->caps.te);
}
