/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_histtrunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 14:40:04 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 14:49:48 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hist.h"

void			ft_histtrunc(t_hist **hist, int max)
{
	while (max-- > 0 && *hist != NULL)
		hist = &((*hist)->prev);
	ft_histdelete(*hist);
	*hist = NULL;
}
