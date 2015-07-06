/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_promptkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:39:22 by juloo             #+#    #+#             */
/*   Updated: 2015/07/06 15:10:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

const t_binding	g_prompt_bindings[] = {
	{KEY_ALL,			&key_restore_tab},
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
	{KEY_CTRL_A,		&key_ctrl_a},
	{KEY_HOME,			&key_ctrl_a},
	{KEY_CTRL_E,		&key_ctrl_e},
	{KEY_END,			&key_ctrl_e},
	{KEY_CTRL_X,		&key_ctrl_x},
	{KEY_CTRL_K,		&key_ctrl_k},
	{KEY_CTRL_O,		&key_ctrl_o},
	{KEY_CTRL_V,		&key_ctrl_v},
	{KEY_CTRL_Y,		&key_ctrl_y},
	{KEY_CTRL_W,		&key_ctrl_w},
	{KEY_CTRL_G,		&key_ctrl_g},
	{KEY_SHIFT_RIGHT,	&key_shift_right},
	{KEY_SHIFT_LEFT,	&key_shift_left},
	{KEY_CTRL_S_RIGHT,	&key_ctrl_shift_right},
	{KEY_CTRL_S_LEFT,	&key_ctrl_shift_left},
	{KEY_ALT_S_RIGHT,	&key_ctrl_shift_right},
	{KEY_ALT_S_LEFT,	&key_ctrl_shift_left},
	{1146821403,		&key_ctrl_left},
	{74995417045787,	&key_ctrl_left},
	{1130044187,		&key_ctrl_right},
	{73895905418011,	&key_ctrl_right},
	{'\0',				NULL}
};

void			ft_promptkey(t_prompt *p, t_ulong key)
{
	int				i;

	i = -1;
	while (g_prompt_bindings[++i].f != NULL)
		if (g_prompt_bindings[i].key == key
			|| g_prompt_bindings[i].key == KEY_ALL)
		{
			g_prompt_bindings[i].f(p, key);
			if (g_prompt_bindings[i].key != KEY_ALL)
				return ;
		}
	if (key >= 128 || !IS(key, IS_PRINT | IS_WHITE))
		ft_printf("\r\n[DEBUG] Unhandled key: %lld\r\n", key);
	i = ft_strlen((char*)&key);
	ft_dstrset(&(p->line), p->cursor, p->cursor + p->selection,
		SUB((char*)&key, i));
	p->cursor = i + MIN(p->selection + p->cursor, p->cursor);
	p->selection = 0;
}
