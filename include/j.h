/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:33 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 18:59:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_H
# define J_H

# include "libft.h"
# include "ft_dstr.h"

# include "ft_term.h"
# include "ft_prompt.h"
# include "ft_getkey.h"

# include <time.h>

/*
** ========================================================================== **
** J
*/

/*
** TODO:
**  Keep last output for search
**  Save last output for later
**  Write an output in stdin
**  Pipe an output to a system command
**  Use of ft_regex
**  Config
**  Put clipboard into a tab completion
**  ctrl+space
*/

# define PN(s,n)			(ft_write(FTOUT, (s), (n)))

# define DEF_HIST_FILE		"~/.j_history"
# define DEF_HIST_MAX		256
# define HISTORY_TIMEOUT	30

# define BUFF_SIZE			512

# define SELECT_TIMEOUT		{1, 0}

# define MASTER_BUFF		BUFF_SIZE

# define OUTPUT_MAX			8
# define OUTPUT_MAX_LEN		128
# define OUTPUT_MAX_CURR	(OUTPUT_MAX_LEN + 64)

# define PIPE_READ			0
# define PIPE_WRITE			1

# define MAX_ESCAPE_LEN		8

typedef struct	s_caps
{
	char			*ch; // Move cursor x (Maybe unsupported)
	char			*ce; // Clear from cursor to right
	char			*cl; // Clear screen
	char			*ti;
	char			*te; // End TI mode
	char			*cm; // Move cursor x y
}				t_caps;

typedef struct	s_j
{
	char			**cmd;
	int				master;
	int				slave_pid;
	t_term			term;
	t_caps			caps;
	int				flags;
	char			*history_file;
	int				history_max;
// -
	t_hist			*output[OUTPUT_MAX];
	t_hist			*output_curr;
	int				output_curr_len;
	t_dstr			current_line;
	int				cursor_start;
// -
	time_t			history_timeout;
	t_prompt		prompt;
	t_prompt		search_prompt;
	t_prompt		ask_prompt;
	t_prompt		ctrl_p_prompt;
}				t_j;

# define FLAG_TI		(1 << 1)
# define FLAG_RETURN	(1 << 3)

# define J_HIDE			(1 << 1)
# define J_SHOW			(1 << 2)
# define J_REFRESH		(J_HIDE | J_SHOW)
# define J_ERASE		(1 << 3)
# define J_PS1			(1 << 4)

/*
** argv
*/
t_bool			parse_argv(t_j *j, int argc, char **argv);

/*
** term
*/
t_bool			start_slave(t_j *j);
void			start_master(t_j *j);
void			scan_output(t_j *j, t_sub output);

void			j_set(t_j *j, int flags);

void			j_flush(t_j *j);
void			j_key(t_j *j, t_key key);

t_bool			j_search(t_j *j, t_hist *hist, t_sub *res);
t_bool			j_ask(t_j *j, char const *q, t_sub *res);

void			j_output_save(t_j *j);
void			j_output_line(t_j *j);

void			j_resize(t_j *j);

/*
** keys
*/
void			key_refresh(t_j *j);
void			key_ctrl_l(t_j *j);
void			key_ctrl_r(t_j *j);
void			key_ctrl_f(t_j *j);
void			key_ctrl_p(t_j *j);
void			key_debug(t_j *j);

/*
** utils
*/
t_bool			ft_openpt(int *master, int *slave);

void			ft_dstrreplace(t_dstr *str, t_sub search, t_sub replace);

t_bool			ft_hmatch(char const *str, char const *pattern);

#endif
