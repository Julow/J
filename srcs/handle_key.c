/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:39:22 by juloo             #+#    #+#             */
/*   Updated: 2015/06/17 00:24:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "keys.h"

const t_binding	g_bindings[] = {
	{0x03,			&key_int},
	{0x04,			&key_eof},
	{'\r',			&key_nl},
	{KEY_UP,		&key_up},
	{KEY_RIGHT,		&key_right},
	{KEY_DOWN,		&key_down},
	{KEY_LEFT,		&key_left},
	{KEY_DELETE,	&key_delete},
	{KEY_BACK,		&key_backspace},
	{KEY_CTRL_L,	&key_ctrl_l},
	{KEY_CTRL_A,	&key_ctrl_a},
	{KEY_CTRL_E,	&key_ctrl_e},
	{'\0',			NULL}
};

void			handle_key(t_j *j, int key)
{
	int				i;

	i = -1;
	while (g_bindings[++i].key != '\0')
		if (g_bindings[i].key == key)
		{
			g_bindings[i].f(j, key);
			return ;
		}
	if (!ft_isalnum(key))
		ft_fdprintf(2, "\nUnhandled key: %d\r\n", key);
	i = ft_strlen((char*)&key);
	ft_dstrset(&(j->line), j->cursor, j->cursor, SUB((char*)&key, i));
	j->cursor += i;
}