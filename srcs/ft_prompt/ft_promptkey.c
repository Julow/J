/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_promptkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:39:22 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 20:22:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"

const t_binding	g_prompt_bindings[] = {
	{KEY('\0', 0),						&key_restore_tab},
	{KEY('c', KEY_CTRL),				&key_int},
	{KEY('d', KEY_CTRL),				&key_eof},
	{KEY('m', KEY_CTRL),				&key_nl},
	{KEY('i', KEY_CTRL),				&key_tab},
	{KEY('\t', KEY_SHIFT),				&key_shift_tab},
	{KEY(KEY_UP, 0),					&key_up},
	{KEY(KEY_RIGHT, 0),					&key_right},
	{KEY(KEY_DOWN, 0),					&key_down},
	{KEY(KEY_LEFT, 0),					&key_left},
	{KEY(KEY_DELETE, 0),				&key_delete},
	{KEY(KEY_DELETE, KEY_ALT),			&key_ctrl_delete},
	{KEY(KEY_DELETE, KEY_CTRL),			&key_ctrl_delete},
	{KEY(KEY_BACKSPACE, 0),				&key_backspace},
	{KEY(KEY_BACKSPACE, KEY_ALT),		&key_ctrl_backspace},
	{KEY('h', KEY_CTRL),				&key_ctrl_backspace},
	{KEY('a', KEY_CTRL),				&key_ctrl_a},
	{KEY(KEY_HOME, 0),					&key_ctrl_a},
	{KEY('e', KEY_CTRL),				&key_ctrl_e},
	{KEY(KEY_END, 0),					&key_ctrl_e},
	{KEY('x', KEY_CTRL),				&key_ctrl_x},
	{KEY('k', KEY_CTRL),				&key_ctrl_k},
	{KEY('o', KEY_CTRL),				&key_ctrl_o},
	{KEY('v', KEY_CTRL),				&key_ctrl_v},
	{KEY('y', KEY_CTRL),				&key_ctrl_y},
	{KEY('w', KEY_CTRL),				&key_ctrl_w},
	{KEY('g', KEY_CTRL),				&key_ctrl_g},
	{KEY(KEY_RIGHT, KEY_SHIFT),			&key_shift_right},
	{KEY(KEY_LEFT, KEY_SHIFT),			&key_shift_left},
	{KEY(KEY_RIGHT, KEY_CTRL | KEY_SHIFT),	&key_ctrl_shift_right},
	{KEY(KEY_LEFT, KEY_CTRL | KEY_SHIFT),	&key_ctrl_shift_left},
	{KEY(KEY_RIGHT, KEY_SHIFT | KEY_ALT),	&key_ctrl_shift_right},
	{KEY(KEY_LEFT, KEY_SHIFT | KEY_ALT),	&key_ctrl_shift_left},
	{KEY(KEY_LEFT, KEY_CTRL),			&key_ctrl_left},
	{KEY(KEY_LEFT, KEY_ALT),			&key_ctrl_left},
	{KEY(KEY_RIGHT, KEY_CTRL),			&key_ctrl_right},
	{KEY(KEY_RIGHT, KEY_ALT),			&key_ctrl_right},
	{KEY('\0', 0),					NULL}
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
