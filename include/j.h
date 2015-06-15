/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:33 by juloo             #+#    #+#             */
/*   Updated: 2015/06/16 01:21:29 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_H
# define J_H

# include "libft.h"
# include "ft_dstr.h"
# include "ft_term.h"

/*
** ========================================================================== **
** J
** ----
** TODO:
**  Selection with keyboard
**  Fullscreen mode
**  History search
**  Keep last output for search
**  Use of ft_regex
**  Config
**  Globing
*/

typedef struct	s_j
{
	t_term			term;
	t_dstr			line;
	char			**cmd;
	int				master;
}				t_j;

t_bool			parse_argv(t_j *j, int argc, char **argv);

t_bool			start_slave(t_j *j);
void			start_master(t_j *j);

void			handle_key(t_j *j, int key);

void			ft_tmakeraw(t_term *term);

#endif
