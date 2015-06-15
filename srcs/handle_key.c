/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 00:39:22 by juloo             #+#    #+#             */
/*   Updated: 2015/06/16 01:19:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <unistd.h>

static void		flush_j(t_j *j)
{
	write(j->master, j->line.str, j->line.length);
	ft_dstrpop(&(j->line), -1);
}

void			handle_key(t_j *j, int key)
{
	if (!ft_isascii(key))
		ft_printf("Key: %d - %#o - %#x - %#b\n", key, key, key, key);
	ft_dstradd_char(&(j->line), key);
	if (key == '\r')
		flush_j(j);
	if (key == 3)
	{
		ft_trestore(&(j->term), false);
		_exit(0);
	}
}
