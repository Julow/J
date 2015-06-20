/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_deletion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 23:59:52 by juloo             #+#    #+#             */
/*   Updated: 2015/06/21 00:11:36 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

void			j_deletion(t_j *j, t_sub str)
{
	t_hist			*hist;

	hist = ft_emalloc(str.length + 1 + sizeof(t_hist));
	*hist = (t_hist){
		j->deletions,
		NULL,
		((void*)hist) + sizeof(t_hist),
		str.length
	};
	ft_memcpy(hist->str, str.str, str.length + 1);
	j->deletions = hist;
}
