/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:39:22 by juloo             #+#    #+#             */
/*   Updated: 2015/06/23 21:56:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "keys.h"

const t_binding	g_bindings[] = {
	{KEY_ALL,			&key_restore_tab},
	{KEY_ALL,			&key_refresh},
	{0x03,				&key_int},
	{0x04,				&key_eof},
	{'\r',				&key_nl},
	{'\t',				&key_tab},
	{KEY_SHIFT_TAB,		&key_shift_tab},
	{KEY_UP,			&key_up},
	{KEY_RIGHT,			&key_right},
	{KEY_DOWN,			&key_down},
	{KEY_LEFT,			&key_left},
	{KEY_DELETE,		&key_delete},
	{KEY_BACK,			&key_backspace},
	{138767091587867,	&key_ctrl_delete},
	{KEY_CTRL_H,		&key_ctrl_backspace},
	{KEY_CTRL_L,		&key_ctrl_l},
	{KEY_CTRL_A,		&key_ctrl_a},
	{KEY_HOME,			&key_ctrl_a},
	{KEY_CTRL_E,		&key_ctrl_e},
	{KEY_END,			&key_ctrl_e},
	{KEY_CTRL_X,		&key_ctrl_x},
	{KEY_CTRL_K,		&key_ctrl_k},
	{KEY_CTRL_V,		&key_ctrl_v},
	{KEY_CTRL_Y,		&key_ctrl_y},
	{74995417045787,	&key_ctrl_left},
	{73895905418011,	&key_ctrl_right},
	{8475,				&key_debug},
	{'\0',				NULL}
};

void			handle_key(t_j *j, t_ulong key)
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
	if (!ft_isascii(key) || !IS(key, IS_PRINT))
	{
		if (j->flags & FLAG_DEBUG && !ft_isalnum(key))
			ft_fdprintf(2, "\r\nUnhandled key: %lld\r\n", key);
		return ;
	}
	i = ft_strlen((char*)&key);
	ft_dstrset(&(j->line), j->cursor, j->cursor, SUB((char*)&key, i));
	j->cursor += i;
}
