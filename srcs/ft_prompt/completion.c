/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 23:03:37 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:21:21 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			prompt_completion(t_prompt *p, int order)
{
	if (p->tab_res == NULL && !prompt_glob(p))
		return ;
	p->cursor -= p->tab_res[p->tab_curr].length;
	ft_dstrset(&(p->line), p->cursor,
		p->cursor + p->tab_res[p->tab_curr].length, SUBC(""));
	p->tab_curr += order;
	if (p->tab_curr < 0)
		p->tab_curr = p->tab_count - 1;
	if (p->tab_curr >= p->tab_count)
		p->tab_curr = 0;
	ft_dstrset(&(p->line), p->cursor, p->cursor,
		ft_dstrsub(p->tab_res + p->tab_curr, 0, -1));
	p->cursor += p->tab_res[p->tab_curr].length;
}
