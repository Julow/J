/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_nl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:10:22 by juloo             #+#    #+#             */
/*   Updated: 2015/06/23 21:53:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void			key_nl(t_j *j, int key)
{
	if (j->line.length > 0)
		j_history(j, j->line);
	ft_dstradd_char(&(j->line), (char)key);
	j_flush(j);
	j->flags |= FLAG_RETURN;
}
