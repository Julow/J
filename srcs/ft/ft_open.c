/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 20:41:51 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 21:20:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <fcntl.h>

/*
** ft_open
** ----
** Resolve pathname starting with '~/'
** and call open(2)
** ----
** Same return value as open(2)
*/
static int		try_open(char const *prefix, t_sub file, int flags)
{
	const int		prefix_len = ft_strlen(prefix);
	const int		full_len = prefix_len + file.length;
	char			full[full_len + 1];

	ft_memcpy(full, prefix, prefix_len);
	ft_memcpy(full + prefix_len, file.str, file.length);
	full[full_len] = '\0';
	return (ft_open(SUB(full, full_len), flags));
}

int				ft_open(t_sub file, int flags)
{
	char			*tmp;

	if (file.length > 1 && file.str[0] == '~' && file.str[1] == '/')
	{
		tmp = ft_getenv("HOME", NULL);
		if (tmp != NULL)
			return (try_open(tmp, SUB(file.str + 1, file.length - 1), flags));
	}
	else if (file.str[file.length] != '\0')
		return (try_open("", file, flags));
	return (open(file.str, flags, FILE_MODE));
}
