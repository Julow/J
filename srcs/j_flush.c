/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_flush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 22:35:30 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 20:25:15 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include <unistd.h>

void			j_flush(t_j *j)
{
	j->flags |= FLAG_RETURN;
	write(j->master, j->prompt.line.str, j->prompt.line.length);
}
