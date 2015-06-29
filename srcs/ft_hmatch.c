/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 00:13:13 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 00:48:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

/*
** ft_hmatch
** ----
** String matching
** ----
** Special chars:
**  '?'            Match any char except white-space
**  '*'            Match 0 or more ?
**  ' '            Match 1 or more white-space then any char
** ----
** Examples: (all match)
**  "abcdef"       "bcd"
**  "abcdef"       "*c*"
**  "abcdef"       "*c?e*"
**  "abcdef"       "*c?e*"
**  " a   bcd e "  "a bcd e"
**  "abc defghij"  "bc f?h"
** ----
** Return true if str match pattern
**  false otherwise
*/
static t_bool	hmatch(char const *str, char const *pattern)
{
	if (*pattern == '\0')
		return (true);
	if (*pattern == '*')
		return (hmatch(str, pattern + 1)
			|| (*str != '\0' && hmatch(str + 1, pattern)));
	if (!(*pattern == '?' && *str != '\0') && *pattern != *str)
		return (false);
	if (*pattern == ' ')
	{
		while (*(++pattern) == ' ')
			;
		while (*(++str) != '\0')
			if (hmatch(str, pattern))
				return (true);
		return (false);
	}
	return (hmatch(str + 1, pattern + 1));
}

t_bool			ft_hmatch(char const *str, char const *pattern)
{
	while (*str != '\0')
		if (hmatch(str, pattern))
			return (true);
		else
			str++;
	return (false);
}
