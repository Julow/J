/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:39:22 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 22:39:53 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_prompt_keys.h"

const t_binding	g_bindings[] = {
	{KEY_ALL,			&key_refresh},
	{KEY_CTRL_L,		&key_ctrl_l},
	{KEY_CTRL_R,		&key_ctrl_r},
	{KEY_CTRL_F,		&key_ctrl_f},
	{8475,				&key_debug},
	{'\0',				NULL}
};

void			j_key(t_j *j, t_ulong key)
{
	int				i;

	i = -1;
	while (g_bindings[++i].f != NULL)
		if (g_bindings[i].key == key || g_bindings[i].key == KEY_ALL)
		{
			g_bindings[i].f(j, key);
			if (g_bindings[i].key != KEY_ALL)
				return ;
		}
	ft_promptkey(&(j->prompt), key);
}
