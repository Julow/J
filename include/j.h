/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:33 by juloo             #+#    #+#             */
/*   Updated: 2015/06/16 20:55:18 by juloo            ###   ########.fr       */
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
**  Save last output for later
**  Write an output in stdin
**  Pipe an output to a system command
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

/*
** argv
*/
t_bool			parse_argv(t_j *j, int argc, char **argv);

/*
** pty
*/
t_bool			start_slave(t_j *j);
void			start_master(t_j *j);

/*
** keys
*/
t_bool			handle_key(t_j *j, int key);

/*
** control
*/
void			j_flush(t_j *j);

/*
** utils
*/
void			ft_tmakeraw(t_term *term);
t_bool			ft_openpt(int *master, int *slave);

#endif
