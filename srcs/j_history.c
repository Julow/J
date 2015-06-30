/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_history.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 23:23:57 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 11:12:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <fcntl.h>

void			j_history_save(t_hist *hist)
{
	char			buff[BUFF_SIZE];
	t_out			out;
	int				i;

	out = OUT(open(HISTORY_FILE, O_WRONLY | O_CREAT), buff, BUFF_SIZE);
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

void			j_history_load(t_hist **hist)
{
	int				fd;
	t_hist			*tmp;
	t_sub			line;

	if ((fd = open(HISTORY_FILE, O_RDONLY)) < 0)
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
