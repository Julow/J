/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:39:22 by juloo             #+#    #+#             */
/*   Updated: 2015/06/16 20:36:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "keys.h"

const t_binding	g_bindings[] = {
	{0x03, &key_int},
	{0x04, &key_eof},
	{'\r', &key_nl},
	{'\0', NULL}
};

t_bool			handle_key(t_j *j, int key)
{
	int				i;

	i = -1;
	while (g_bindings[++i].key != '\0')
		if (g_bindings[i].key == key)
		{
			g_bindings[i].f(j, key);
			return (true);
		}
	if (!ft_isalnum(key))
		ft_printf("Unhandled key: %d\r\n", key);
	return (false);
}
