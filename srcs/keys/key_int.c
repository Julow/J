/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:35:49 by juloo             #+#    #+#             */
/*   Updated: 2015/06/19 23:55:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void			key_int(t_j *j, int key)
{
	if (j->line.length > 0)
	{
		ft_dstrpop(&(j->line), -1);
		j->cursor = 0;
		return ;
	}
	ft_dstradd_char(&(j->line), (char)key);
	j_flush(j);
}
