/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_histdelete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 14:40:10 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 14:45:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hist.h"
#include <stdlib.h>

void			ft_histdelete(t_hist *hist)
{
	t_hist			*tmp;

	while (hist != NULL)
	{
		tmp = hist;
		hist = hist->prev;
		free(tmp);
	}
}
