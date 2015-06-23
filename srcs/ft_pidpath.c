/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pidpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 21:09:51 by juloo             #+#    #+#             */
/*   Updated: 2015/06/23 21:46:21 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_proc.h"

#ifdef __APPLE__

# include "libproc.h"

char			*ft_pidpath(pid_t pid)
{
	char			buff[PROC_PIDPATHINFO_MAXSIZE];
	int				len;
	char			*tmp;

	if ((len = proc_pidpath(pid, buff, PROC_PIDPATHINFO_MAXSIZE)) <= 0)
		return (NULL);
	tmp = MAL(char, len + 1);
	ft_memcpy(tmp, buff, len);
	tmp[len] = '\0';
	return (tmp);
}

#else

# include <unistd.h>

# define LINK_BUFF		256
# define LINK_NAME_LEN	64

char			*ft_pidpath(pid_t pid)
{
	char			link_name[LINK_NAME_LEN];
	char			buff[LINK_BUFF];
	int				len;

	len = 6;
	ft_memcpy(link_name, "/proc/", len);
	len += ft_itoab(pid, link_name + len);
	ft_memcpy(link_name + len, "/cwd", 4);
	link_name[len + 4] = '\0';
	if ((len = readlink(link_name, buff, LINK_BUFF)) < 0)
		return (NULL);
	return (ft_memdup(buff, len));
}

#endif
