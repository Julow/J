/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_histsave.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 14:39:59 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 15:42:45 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hist.h"
#include "j.h"
#include <fcntl.h>

void			ft_histsave(t_hist *hist, char const *file)
{
	char			buff[BUFF_SIZE];
	t_out			out;
	int				i;

	out = OUT(open(file, O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE),
		buff, BUFF_SIZE);
	if (out.fd < 0)
		return ;
	i = HISTORY_MAX;
	while (--i > 0 && hist->prev != NULL)
		hist = hist->prev;
	while (hist != NULL)
	{
		if (hist->length > 0)
		{
			ft_write(&out, hist->str, hist->length);
			ft_writechar(&out, '\n');
		}
		hist = hist->next;
	}
	ft_flush(&out);
}
