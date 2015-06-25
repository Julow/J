/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 23:59:52 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:21:10 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			prompt_deletion(t_prompt *p, t_sub str)
{
	t_hist			*hist;

	hist = ft_emalloc(str.length + 1 + sizeof(t_hist));
	*hist = (t_hist){
		p->deletions,
		NULL,
		((void*)hist) + sizeof(t_hist),
		str.length
	};
	ft_memcpy(hist->str, str.str, str.length + 1);
	p->deletions = hist;
}
