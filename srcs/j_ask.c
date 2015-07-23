/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_ask.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 23:50:10 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 20:23:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_prompt_keys.h"
#include <unistd.h>

t_bool			j_ask(t_j *j, char const *q, t_sub *res)
{
	t_key			key;

	*res = SUB(NULL, 0);
	while (true)
	{
		j_set(j, J_HIDE);
		PS(q);
		PS(" > ");
		PN(j->ask_prompt.line.str, j->ask_prompt.line.length);
		FL;
		key = ft_getkey();
		if (key.c == EOF || ft_keyequ(key, KEY('d', KEY_CTRL))
			|| ft_keyequ(key, KEY('c', KEY_CTRL))
			|| key.c == KEY_ESC)
			break ;
		if (ft_keyequ(key, KEY('m', KEY_CTRL)))
		{
			*res = ft_dstrsub(&(j->ask_prompt.line), 0, -1);
			break ;
		}
		ft_promptkey(&(j->ask_prompt), key);
	}
	j_set(j, J_SHOW);
	return ((res->str == NULL) ? false : true);
}
