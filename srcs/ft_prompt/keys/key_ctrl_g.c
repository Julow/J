/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_g.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/06 11:39:17 by juloo             #+#    #+#             */
/*   Updated: 2015/07/06 16:31:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt_keys.h"
#include <time.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

static t_bool	write_tmp(t_prompt *p, char const *tmp_file)
{
	int				fd;

	if ((fd = open(tmp_file, O_CREAT | O_TRUNC | O_WRONLY, FILE_MODE)) < 0)
		return (ft_fdprintf(2, "Error: Cannot create tmp file: %s\r\n",
			strerror(errno)), false);
	write(fd, p->line.str, p->line.length);
	ft_putchar_fd('\n', fd);
	close(fd);
	return (true);
}

static void		read_tmp(t_prompt *p, char const *tmp_file)
{
	int				fd;
	t_sub			line;

	if ((fd = open(tmp_file, O_RDONLY, FILE_MODE)) < 0)
		return (ft_fdprintf(2, "Error: Cannot read tmp file: %s\r\n",
			strerror(errno)), VOID);
	ft_dstrpop(&(p->line), -1);
	line = SUBC("");
	while (get_next_line(fd, &line) > 0)
	{
		if (line.length <= 0)
			continue ;
		if (p->line.length > 0)
		{
			ft_histadd(&(p->history), ft_dstrsub(&(p->line), 0, -1));
			ft_dstrpop(&(p->line), -1);
		}
		ft_dstradd_sub(&(p->line), line);
	}
	close(fd);
	p->cursor = p->line.length;
}

void			key_ctrl_g(t_prompt *p)
{
	char			*cmd[] = {NULL, NULL, NULL};
	char			tmp_file[64];

	ft_sprintf(tmp_file, "/tmp/tmp_j_%llu", (t_ulong)clock());
	if (!write_tmp(p, tmp_file))
		return ;
	if ((cmd[0] = ft_getenv("J_EDITOR", NULL)) == NULL
		&& (cmd[0] = ft_getenv("EDITOR", NULL)) == NULL)
		cmd[0] = DEFAULT_EDITOR;
	cmd[1] = tmp_file;
	ft_call(cmd);
	read_tmp(p, tmp_file);
	unlink(tmp_file);
}
