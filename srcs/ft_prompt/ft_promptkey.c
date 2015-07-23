/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_promptkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:39:22 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 20:07:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

const t_binding	g_prompt_bindings[] = {
	{KEY('\0', 0),						&key_restore_tab},
	{KEY('c', GETKEY_CTRL),				&key_int},
	{KEY('d', GETKEY_CTRL),				&key_eof},
	{KEY('m', GETKEY_CTRL),				&key_nl},
	{KEY('i', GETKEY_CTRL),				&key_tab},
	{KEY('\t', GETKEY_SHIFT),			&key_shift_tab},
	{KEY(GETKEY_UP, 0),					&key_up},
	{KEY(GETKEY_RIGHT, 0),				&key_right},
	{KEY(GETKEY_DOWN, 0),				&key_down},
	{KEY(GETKEY_LEFT, 0),				&key_left},
	{KEY(GETKEY_DELETE, 0),				&key_delete},
	{KEY(GETKEY_DELETE, GETKEY_ALT),	&key_ctrl_delete},
	{KEY(GETKEY_DELETE, GETKEY_CTRL),	&key_ctrl_delete},
	{KEY(GETKEY_BACKSPACE, 0),			&key_backspace},
	{KEY(GETKEY_BACKSPACE, GETKEY_ALT),	&key_ctrl_backspace},
	{KEY('h', GETKEY_CTRL),				&key_ctrl_backspace},
	{KEY('a', GETKEY_CTRL),				&key_ctrl_a},
	{KEY(GETKEY_HOME, 0),				&key_ctrl_a},
	{KEY('e', GETKEY_CTRL),				&key_ctrl_e},
	{KEY(GETKEY_END, 0),				&key_ctrl_e},
	{KEY('x', GETKEY_CTRL),				&key_ctrl_x},
	{KEY('k', GETKEY_CTRL),				&key_ctrl_k},
	{KEY('o', GETKEY_CTRL),				&key_ctrl_o},
	{KEY('v', GETKEY_CTRL),				&key_ctrl_v},
	{KEY('y', GETKEY_CTRL),				&key_ctrl_y},
	{KEY('w', GETKEY_CTRL),				&key_ctrl_w},
	{KEY('g', GETKEY_CTRL),				&key_ctrl_g},
	{KEY(GETKEY_RIGHT, GETKEY_SHIFT),	&key_shift_right},
	{KEY(GETKEY_LEFT, GETKEY_SHIFT),	&key_shift_left},
	{KEY(GETKEY_RIGHT, GETKEY_CTRL | GETKEY_SHIFT),	&key_ctrl_shift_right},
	{KEY(GETKEY_LEFT, GETKEY_CTRL | GETKEY_SHIFT),	&key_ctrl_shift_left},
	{KEY(GETKEY_RIGHT, GETKEY_SHIFT | GETKEY_ALT),	&key_ctrl_shift_right},
	{KEY(GETKEY_LEFT, GETKEY_SHIFT | GETKEY_ALT),	&key_ctrl_shift_left},
	{KEY(GETKEY_LEFT, GETKEY_CTRL),		&key_ctrl_left},
	{KEY(GETKEY_LEFT, GETKEY_ALT),		&key_ctrl_left},
	{KEY(GETKEY_RIGHT, GETKEY_CTRL),	&key_ctrl_right},
	{KEY(GETKEY_RIGHT, GETKEY_ALT),		&key_ctrl_right},
	{KEY('\0', 0),				NULL}
};

void			ft_promptkey(t_prompt *p, t_key key)
{
	int				i;

	i = -1;
	while (g_prompt_bindings[++i].f != NULL)
		if (ft_keyequ(g_prompt_bindings[i].key, key)
			|| g_prompt_bindings[i].key.c == '\0')
		{
			g_prompt_bindings[i].f(p, key);
			if (g_prompt_bindings[i].key.c != '\0')
				return ;
		}
	if (key.c < 0 || key.c >= 128 || key.flags != 0)
		return ;
	ft_dstrset(&(p->line), p->cursor, p->cursor + p->selection,
		SUB((char*)&(key.c), 1));
	p->cursor = 1 + MIN(p->selection + p->cursor, p->cursor);
	p->selection = 0;
}
