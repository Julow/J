/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_completion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 23:03:37 by juloo             #+#    #+#             */
/*   Updated: 2015/06/22 23:04:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

void			j_completion(t_j *j, int order)
{
	if (j->tab_res == NULL && !j_glob(j))
		return ;
	j->cursor -= j->tab_res[j->tab_curr].length;
	ft_dstrset(&(j->line), j->cursor,
		j->cursor + j->tab_res[j->tab_curr].length, SUBC(""));
	j->tab_curr += order;
	if (j->tab_curr < 0)
		j->tab_curr = j->tab_count - 1;
	if (j->tab_curr >= j->tab_count)
		j->tab_curr = 0;
	ft_dstrset(&(j->line), j->cursor, j->cursor,
		ft_dstrsub(j->tab_res + j->tab_curr, 0, -1));
	j->cursor += j->tab_res[j->tab_curr].length;
}
