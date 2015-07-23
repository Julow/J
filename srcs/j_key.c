/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:39:22 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 19:41:22 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_prompt_keys.h"

const t_binding	g_bindings[] = {
	{KEY('\0', 0),				&key_refresh},
	{KEY('l', GETKEY_CTRL),		&key_ctrl_l},
	{KEY('r', GETKEY_CTRL),		&key_ctrl_r},
	{KEY('f', GETKEY_CTRL),		&key_ctrl_f},
	{KEY('p', GETKEY_CTRL),		&key_ctrl_p},
	{KEY('\0', 0),				NULL}
};

void			j_key(t_j *j, t_key key)
{
	int				i;

	i = -1;
	while (g_bindings[++i].f != NULL)
		if (ft_keyequ(g_bindings[i].key, key) || g_bindings[i].key.c == '\0')
		{
			g_bindings[i].f(j, key);
			if (g_bindings[i].key.c != '\0')
				return ;
		}
	ft_promptkey(&(j->prompt), key);
}
