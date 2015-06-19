/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:33 by juloo             #+#    #+#             */
/*   Updated: 2015/06/19 23:58:19 by juloo            ###   ########.fr       */
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
**  Disable j
*/

# define PN(s,n)		(ft_write(FTOUT, (s), (n)))

# define MASTER_BUFF	512

# define MAX_ESCAPE_LEN	8

typedef struct	s_caps
{
	char			*ch; // Move cursor x (Maybe unsupported)
	char			*ce; // Clear from cursor to right
	char			*ti; // Enter TI mode
	char			*te; // Exit TI mode
}				t_caps;

typedef struct	s_j
{
	t_term			term;
	t_dstr			line;
	char			**cmd;
	t_caps			caps;
	int				flags;
	int				master;
	int				line_start;
	int				cursor;
}				t_j;

# define FLAG_TI		(1 << 1)

# define J_HIDE			(1 << 1)
# define J_SHOW			(1 << 2)
# define J_REFRESH		(J_HIDE | J_SHOW)

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
void			handle_key(t_j *j, t_ulong key);

/*
** control
*/
void			j_flush(t_j *j);
void			j_set(t_j *j, int flags);

/*
** output
*/
void			scan_output(t_j *j, t_sub output);

/*
** utils
*/
void			ft_tmakeraw(t_term *term);
t_bool			ft_openpt(int *master, int *slave);

int				ft_subindex(t_sub sub, char c);
int				ft_subchr(t_sub sub, t_is mask);

#endif
