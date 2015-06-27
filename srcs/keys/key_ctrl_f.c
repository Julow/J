/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 00:00:10 by juloo             #+#    #+#             */
/*   Updated: 2015/06/28 00:31:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

static void		f_replace(t_j *j, t_sub search)
{
	char			tmp[search.length];
	t_sub			replace;

	ft_memcpy(tmp, search.str, search.length);
	if (!j_ask(j, "Replace", &replace))
		return ;
	ft_dstrreplace(&(j->prompt.line), SUB(tmp, search.length), replace);
	if (j->prompt.cursor > j->prompt.line.length)
		j->prompt.cursor = j->prompt.line.length;
}

void			key_ctrl_f(t_j *j)
{
	t_sub			search;

	if (!j_ask(j, "Search", &search) || search.length <= 0)
		return ;
	f_replace(j, search);
}
