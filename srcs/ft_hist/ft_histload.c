/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_histload.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 14:39:56 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 21:23:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hist.h"
#include <fcntl.h>

void			ft_histload(t_hist **hist, t_sub file)
{
	int				fd;
	t_sub			line;

	if ((fd = ft_open(file, O_RDONLY)) < 0)
		return ;
	while (get_next_line(fd, &line) > 0)
		ft_histadd(hist, line);
}
