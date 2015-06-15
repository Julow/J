/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:45 by juloo             #+#    #+#             */
/*   Updated: 2015/06/16 00:02:03 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "msg.h"

int				main(int argc, char **argv)
{
	t_j				j;

	if (!ft_tinit(&(j.term)))
		return (ft_fdprintf(2, E_TERM), 1);
	if (!parse_argv(&j, argc, argv))
		return (2);
	return (0);
}
