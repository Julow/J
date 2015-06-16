/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_refresh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 22:09:40 by juloo             #+#    #+#             */
/*   Updated: 2015/06/16 22:55:22 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"

void			j_refresh(t_j *j)
{
	t_sub			prompt = SUBC("PROMPT > ");

	TPS("cr");
	TPS("ce");
	PN(prompt.str, prompt.length);
	PN(j->line.str, j->line.length);
	PS(tgoto(tgetstr("ch", NULL), 0, j->cursor + prompt.length));
	FL;
}
