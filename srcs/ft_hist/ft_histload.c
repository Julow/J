/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_histload.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 14:39:56 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 19:55:31 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hist.h"
#include <fcntl.h>

void			ft_histload(t_hist **hist, char const *file)
{
	int				fd;
	t_sub			line;

	if ((fd = open(file, O_RDONLY)) < 0)
		return ;
	while (get_next_line(fd, &line) > 0)
		ft_histadd(hist, line);
}
