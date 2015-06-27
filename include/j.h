/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:33 by juloo             #+#    #+#             */
/*   Updated: 2015/06/27 23:48:53 by juloo            ###   ########.fr       */
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
** ========================================================================== **
** Bindings
** -----
** c = ctrl
** s = shift
** m = alt / option
** -----
** Cursor:
**  left / right		Move cursor into line
**  c+left / c+right	Move cursor into line word by word
**  c+A / home			Move to the start of the line
**  c+E / end			Move to the end of the line
** -----
** History:
**  up / right			Navigate in the history
**  c+R					History search
** -
** Delete:
**  c+C					Clear line (if line is not empty)
**  delete				Delete
**  c+H					Backspace by word
**  c+delete			Delete by word
**  c+K					Delete from the cursor to the end of line
**  c+X					Delete current word
** -
** Paste:
**  c+Y					Paste last delete
**  c+V					Paste last delete but keep it in the history
** -
** (TODO) Selection:
**  (TODO) s+right / s+left		Select
**  (TODO) s+c+right / s+c+left	Select by word
** -
** Other:
**  tab					Auto complete
**  shift+tab			Auto complete in reverse order
**  m+!					Active debug print
**  c+space				Disable J
** ========================================================================== **
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
**  Put deletion history into a tab completion
*/

# define PN(s,n)		(ft_write(FTOUT, (s), (n)))

# define MASTER_BUFF	512

# define PIPE_READ		0
# define PIPE_WRITE		1

# define MAX_ESCAPE_LEN	8

typedef struct	s_caps
{
	char			*ch; // Move cursor x (Maybe unsupported)
	char			*ce; // Clear from cursor to right
	char			*cm; // Move cursor x y
	char			*cl; // Clear screen
	char			*vi; // VI mode (cursor hide)
	char			*ve; // exit VI mode
	char			*ti; // TI mode (tmp screen)
	char			*te; // exit TI mode
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
	t_prompt		search_prompt;
}				t_j;

# define FLAG_TI		(1 << 1)
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
void			scan_output(t_j *j, t_sub output);

void			j_set(t_j *j, int flags);

void			j_flush(t_j *j);
void			j_key(t_j *j, t_ulong key);

t_bool			j_search(t_j *j, t_hist *hist, t_sub *res);

/*
** keys
*/
void			key_refresh(t_j *j);
void			key_ctrl_l(t_j *j);
void			key_ctrl_r(t_j *j);

/*
** utils
*/
void			ft_tmakeraw(t_term *term);
t_bool			ft_openpt(int *master, int *slave);

#endif
