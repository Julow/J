/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:33 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:46:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_H
# define J_H

# include "libft.h"
# include "ft_dstr.h"
# include "ft_term.h"
# include "ft_prompt.h"

/*
** ========================================================================== **
** J
*/

/*
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
**  Disable j
**  Put deletion history into a tab completion
*/

# define PN(s,n)		(ft_write(FTOUT, (s), (n)))

# define MASTER_BUFF	512

# define FT_SYS_BUFF	512
# define PIPE_READ		0
# define PIPE_WRITE		1

# define MAX_ESCAPE_LEN	8

typedef struct	s_caps
{
	char			*ch; // Move cursor x (Maybe unsupported)
	char			*ce; // Clear from cursor to right
}				t_caps;

typedef struct	s_j
{
	char			**cmd;
	int				master;
	int				slave_pid;
	t_term			term;
	t_caps			caps;
	int				flags;
	int				line_start;
	t_prompt		prompt;
}				t_j;

# define FLAG_TI		(1 << 1)
# define FLAG_DEBUG		(1 << 2)
# define FLAG_RETURN	(1 << 3)

# define J_HIDE			(1 << 1)
# define J_SHOW			(1 << 2)
# define J_REFRESH		(J_HIDE | J_SHOW)

/*
** argv
*/
t_bool			parse_argv(t_j *j, int argc, char **argv);

/*
** term
*/
t_bool			start_slave(t_j *j);
void			start_master(t_j *j);

void			j_flush(t_j *j);

void			j_key(t_j *j, t_ulong key);

void			j_set(t_j *j, int flags);

void			scan_output(t_j *j, t_sub output);

/*
** keys
*/
void			key_refresh(t_j *j);
void			key_ctrl_l(t_j *j);

/*
** utils
*/
void			ft_tmakeraw(t_term *term);
t_bool			ft_openpt(int *master, int *slave);

t_dstr			ft_system(char **cmd);

#endif
