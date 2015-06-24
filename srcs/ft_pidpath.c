/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pidpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 21:09:51 by juloo             #+#    #+#             */
/*   Updated: 2015/06/24 23:55:40 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_proc.h"

#ifdef __APPLE__

int				ft_pidpath(pid_t pid, char *buff, int buff_size)
{
	return (proc_pidpath(pid, buff, buff_size));
}

#else

# include <unistd.h>

int				ft_pidpath(pid_t pid, char *buff, int buff_size)
{
	int				len;
	char			link_name[64];

	buff_size--;
	ft_sprintf(link_name, "/proc/%d/cwd", pid);
	if ((len = readlink(link_name, buff, buff_size)) <= 0)
		return ((buff[0] = '\0'), len);
	buff[len] = '\0';
	return (len);
}

#endif
