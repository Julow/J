/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 00:48:41 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 00:05:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_subindex(t_sub sub, char c)
{
	int				i;

	i = -1;
	while (++i < sub.length)
		if (sub.str[i] == c)
			return (i);
	return (-1);
}
