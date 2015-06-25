/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_flush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 22:35:30 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:40:54 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <unistd.h>

void			j_flush(t_j *j)
{
	write(j->master, j->prompt.line.str, j->prompt.line.length);
}
