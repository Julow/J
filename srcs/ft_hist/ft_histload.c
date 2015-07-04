/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_histload.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 14:39:56 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 15:42:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hist.h"
#include <fcntl.h>

void			ft_histload(t_hist **hist, char const *file)
{
	int				fd;
	t_hist			*tmp;
	t_sub			line;

	if ((fd = open(file, O_RDONLY)) < 0)
		return ;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = (t_hist*)MAL(t_byte, sizeof(t_hist) + line.length + 1);
		*tmp = (t_hist){NULL, NULL, ((void*)tmp) + sizeof(t_hist), line.length};
		ft_memcpy(tmp->str, line.str, line.length + 1);
		tmp->prev = *hist;
		tmp->prev->next = tmp;
		*hist = tmp;
	}
}
