/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_histadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 15:36:24 by juloo             #+#    #+#             */
/*   Updated: 2015/07/05 20:45:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hist.h"

void			ft_histadd(t_hist **hist, t_sub add)
{
	t_hist			*tmp;

	tmp = ft_emalloc(add.length + 1 + sizeof(t_hist));
	*tmp = (t_hist){
		*hist,
		NULL,
		((void*)tmp) + sizeof(t_hist),
		add.length
	};
	ft_memcpy(tmp->str, add.str, add.length);
	tmp->str[add.length] = '\0';
	if (*hist != NULL)
		(*hist)->next = tmp;
	*hist = tmp;
}
