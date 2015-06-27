/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrreplace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 00:07:36 by juloo             #+#    #+#             */
/*   Updated: 2015/06/28 00:35:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_dstr.h"

void			ft_dstrreplace(t_dstr *str, t_sub search, t_sub replace)
{
	int				i;

	i = 0;
	while (i <= (str->length - search.length))
		if (str->str[i] == search.str[0]
			&& ft_memcmp(search.str, str->str + i, search.length) == 0)
		{
			ft_dstrset(str, i, i + search.length, replace);
			i += replace.length;
		}
		else
			i++;
}
