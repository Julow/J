/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl_arrows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 23:47:21 by juloo             #+#    #+#             */
/*   Updated: 2015/06/20 01:00:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void			key_ctrl_left(t_j *j)
{
	j->cursor = j_word_motion(j).from;
}

void			key_ctrl_right(t_j *j)
{
	j->cursor = j_word_motion(j).to;
}
