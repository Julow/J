/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 22:52:12 by juloo             #+#    #+#             */
/*   Updated: 2015/06/18 23:31:15 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void			key_delete(t_j *j, int key)
{
	if (j->cursor >= j->line.length)
		return ;
	ft_dstrset(&(j->line), j->cursor, j->cursor + 1, SUBC(""));
	j->cursor = MIN(j->cursor, j->line.length);
	(void)key;
}

void			key_backspace(t_j *j, int key)
{
	if (j->cursor <= 0 || j->line.length <= 0)
		return ;
	ft_dstrset(&(j->line), j->cursor - 1, j->cursor, SUBC(""));
	j->cursor = MAX(j->cursor - 1, 0);
	(void)key;
}
